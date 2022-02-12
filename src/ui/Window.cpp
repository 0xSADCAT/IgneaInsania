#include "Window.hpp"

#include "WindowImpl.hpp"


Window::Window(const std::string& title)
    : _impl(new WindowImpl(title))
{}

Window::~Window()
{
    delete _impl;
}

void Window::clear()
{
    _impl->clear();
}

void Window::present()
{
    _impl->present();
}

void Window::drawTexture(TextureId id, const Point& position, Flip flip, double rotation)
{
    _impl->drawTexture(id, position, flip, rotation);
}

