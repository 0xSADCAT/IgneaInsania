#include "WindowImpl.hpp"

#include <cassert>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../textures/TextureManager.hpp"
#include "../textures/SizeManager.hpp"


namespace
{
static constexpr Uint32 window_flags = SDL_WINDOW_SHOWN;

static constexpr Uint32 render_flags = SDL_RENDERER_ACCELERATED |
                                       SDL_RENDERER_PRESENTVSYNC;

static constexpr int window_width = 1920;
static constexpr int window_height = 1080;
};

WindowImpl::WindowImpl(const std::string& title)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "Failed to init SDL:" << std::endl
                  << SDL_GetError() << std::endl;
        std::exit(-1);
    }

    if (IMG_Init(IMG_INIT_PNG) == 0)
    {
        std::cerr << "Failed to init IMG:" << std::endl
                  << IMG_GetError() << std::endl;
        std::exit(-1);
    }

    _window = SDL_CreateWindow(title.c_str(),
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               window_width,
                               window_height,
                               window_flags);
    if (_window == nullptr)
    {
        std::cerr << "Failed to create window:" << std::endl
                  << SDL_GetError() << std::endl;
        std::exit(-1);
    }

    _renderer = SDL_CreateRenderer(_window, -1, render_flags);
    if (_renderer == nullptr)
    {
        std::cerr << "Failed to create renderer:" << std::endl
                  << SDL_GetError() << std::endl;
        std::exit(-1);
    }

    _texture_manager = new TextureManager(_renderer);
    _size_manager = new SizeManager(window_width, window_height);

    SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(_renderer);
    SDL_RenderPresent(_renderer);
}

WindowImpl::~WindowImpl()
{
    if (_texture_manager != nullptr)
    {
        delete _texture_manager;
    }
    if (_size_manager != nullptr)
    {
        delete _size_manager;
    }

    if (_renderer != nullptr)
    {
        SDL_DestroyRenderer(_renderer);
    }
    if (_window != nullptr)
    {
        SDL_DestroyWindow(_window);
    }
}

void WindowImpl::clear()
{
    SDL_RenderClear(_renderer);
}

void WindowImpl::present()
{
    SDL_RenderPresent(_renderer);
}

void WindowImpl::drawTexture(TextureId id, const Point& position, Flip flip, double rotation)
{
    SDL_Texture* texture = _texture_manager->get(id);

    assert(texture != nullptr);

    SDL_Rect rect;
    rect.x = static_cast<int>(position.x());
    rect.y = static_cast<int>(position.y());
    rect.w = rect.h = _size_manager->size(id);

    if (flip == Flip::None and rotation == 0.0)
    {
        SDL_RenderCopy(_renderer, texture, nullptr, &rect);
    }
    else
    {
        SDL_RendererFlip sdl_flip;
        switch (flip)
        {
        case Flip::Horizontal:
            sdl_flip = SDL_FLIP_HORIZONTAL;
            break;

        case Flip::Vertical:
            sdl_flip = SDL_FLIP_VERTICAL;
            break;

        default:
            sdl_flip = SDL_FLIP_NONE;
            break;
        }

        SDL_RenderCopyEx(_renderer, texture, nullptr, &rect, rotation, nullptr, sdl_flip);
    }
}
