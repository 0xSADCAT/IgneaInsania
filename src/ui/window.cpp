#include "window.hpp"

#include "window_impl.hpp"


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

