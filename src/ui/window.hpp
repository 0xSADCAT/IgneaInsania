#pragma once

#include <string>

#include "../structs/geometry.hpp"
#include "../textures/texture_id.hpp"


class WindowImpl;


class Window
{
public:
    Window(const std::string& title);
    ~Window();

    void clear();

    void present();

    void drawTexture(TextureId id, const Point& position,
                     Flip flip = Flip::None, double rotation = 0.0);

private:
    WindowImpl* _impl;

    Window(Window&) = delete;
    Window(Window&&) = delete;
    Window& operator=(Window&) = delete;
    Window& operator=(Window&&) = delete;

    friend class TextureManager;
};

