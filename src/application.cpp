#include "application.hpp"

#include <cassert>
#include "application_events_impl.hpp"
#include "ui/window.hpp"
#include "game/game.hpp"


namespace
{
Application* instance = nullptr;
}


Application::Application(int argc, char** argv)
    : _events_impl(new ApplicationEventsImpl)
{
    assert(::instance == nullptr);
    ::instance = this;

    _arguments.reserve(argc);
    for (int i = 0; i < argc; ++i)
    {
        _arguments.push_back(argv[i]);
    }
}

Application::~Application()
{
    ::instance = nullptr;
    delete _events_impl;
}

Application* Application::instance()
{
    return ::instance;
}

void Application::setWindow(Window* window)
{
    _window = window;
}

void Application::setGameModel(Game* game)
{
    _game = game;
}

int Application::execute()
{
    return _events_impl->execute();
}

void Application::quit(int code)
{
    _events_impl->quit(code);
}

const std::vector<std::string>& Application::arguments() const
{
    return _arguments;
}


void Application::mouseButtonEvent(const MouseButtonEvent& event)
{
    if (_game != nullptr)
    {
        _game->onMouseButtonEvent(event);
    }
}

void Application::mouseMoveEvent(const MouseMoveEvent& event)
{
    if (_game != nullptr)
    {
        _game->onMouseMoveEvent(event);
    }
}

void Application::mouseWheelEvent(const MouseWheelEvent& event)
{
    if (_game != nullptr)
    {
        _game->onMouseWheelEvent(event);
    }
}

void Application::keyEvent(const KeyEvent& event)
{
    if (_game != nullptr)
    {
        _game->onKeyEvent(event);
    }
}

void Application::tickEvent(int microseconds_elapsed)
{
    if (_game != nullptr)
    {
        _game->onTickEvent(microseconds_elapsed);
    }
    else
    {
        return;
    }

    if (_window != nullptr)
    {
        _window->clear();
        _window->drawTexture(_game->player().texture(), _game->player().position(),
                             _game->player().flip(), _game->player().rotation());
        _window->present();
    }
}
