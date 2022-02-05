#pragma once

#include <string>


class WindowImpl;


class Window
{
public:
    Window(const std::string& title);
    ~Window();

    void clear();

    void present();

private:
    WindowImpl* _impl;

    Window(Window&) = delete;
    Window(Window&&) = delete;
    Window& operator=(Window&) = delete;
    Window& operator=(Window&&) = delete;
};

