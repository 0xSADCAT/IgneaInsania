#pragma once

#include <string>
#include <SDL2/SDL.h>


class WindowImpl
{
public:
    WindowImpl(const std::string& title);
    ~WindowImpl();

    void clear();

    void present();

private:
    SDL_Window* _window = nullptr;
    SDL_Renderer* _renderer = nullptr;

    WindowImpl(WindowImpl&) = delete;
    WindowImpl(WindowImpl&&) = delete;
    WindowImpl& operator=(WindowImpl&) = delete;
    WindowImpl& operator=(WindowImpl&&) = delete;
};

