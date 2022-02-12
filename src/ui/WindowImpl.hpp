#pragma once

#include <string>
#include <SDL2/SDL.h>

#include "../structs/Geometry.hpp"
#include "../textures/TextureId.hpp"


class TextureManager;
class SizeManager;


class WindowImpl
{
public:
    WindowImpl(const std::string& title);
    ~WindowImpl();

    void clear();

    void present();

    void drawTexture(TextureId id, const Point& position, Flip flip, double rotation);

private:
    SDL_Window* _window = nullptr;
    SDL_Renderer* _renderer = nullptr;
    TextureManager* _texture_manager = nullptr;
    SizeManager* _size_manager = nullptr;

    WindowImpl(WindowImpl&) = delete;
    WindowImpl(WindowImpl&&) = delete;
    WindowImpl& operator=(WindowImpl&) = delete;
    WindowImpl& operator=(WindowImpl&&) = delete;
};

