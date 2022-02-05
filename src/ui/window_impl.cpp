#include "window_impl.hpp"

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include <SDL2/SDL.h>

namespace
{
static constexpr Uint32 render_flags = SDL_RENDERER_ACCELERATED |
                                       SDL_RENDERER_PRESENTVSYNC;
};

WindowImpl::WindowImpl(const std::string& title)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "Failed to init SDL:" << std::endl
                  << SDL_GetError() << std::endl;
        std::exit(-1);
    }

    _window = SDL_CreateWindow(title.c_str(),
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               1920,
                               1080,
                               SDL_WINDOW_SHOWN);
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

    SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(_renderer);
    SDL_RenderPresent(_renderer);
}

WindowImpl::~WindowImpl()
{
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
