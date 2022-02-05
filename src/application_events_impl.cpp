#include "application_events_impl.hpp"

#include <chrono>
#include <SDL2/SDL.h>
#include "application.hpp"


namespace
{

MouseButtonEvent makeEvent(const SDL_MouseButtonEvent& event)
{
    MouseButton button;
    switch (event.button)
    {
    case SDL_BUTTON_LEFT:
        button = MouseButton::Left;
        break;

    case SDL_BUTTON_RIGHT:
        button = MouseButton::Right;
        break;

    case SDL_BUTTON_MIDDLE:
        button = MouseButton::Middle;
        break;

    default:
        button = MouseButton::Undefined;
        break;
    }

    return MouseButtonEvent(event.x, event.y, button,
                            event.state == SDL_PRESSED ? ButtonState::Pressed
                                                       : ButtonState::Released);
}

MouseMoveEvent makeEvent(const SDL_MouseMotionEvent& event)
{
    return MouseMoveEvent(event.x, event.y);
}

MouseWheelEvent makeEvent(const SDL_MouseWheelEvent& event)
{
    return MouseWheelEvent(event.x, event.y, event.direction);
}

KeyEvent makeEvent(const SDL_KeyboardEvent& event)
{
    Key key;

    switch (event.keysym.sym)
    {

    default:
        key = Key::Undefined;
        break;
    }

    return KeyEvent(key, event.state == SDL_PRESSED ? ButtonState::Pressed : ButtonState::Released);
}

}


int ApplicationEventsImpl::execute()
{
    if (_running)
    {
        return 1;
    }

    static std::chrono::steady_clock::time_point time =
            std::chrono::steady_clock::now();

    _running = true;
    _code = 0;
    SDL_Event event;

    while (_running)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            switch (event.type)
            {
            case SDL_QUIT:
                quit(0);
                break;

            case SDL_MOUSEBUTTONDOWN:
            case SDL_MOUSEBUTTONUP:
                iapp->mouseButtonEvent(makeEvent(event.button));
                break;

            case SDL_MOUSEMOTION:
                iapp->mouseMoveEvent(makeEvent(event.motion));
                break;

            case SDL_MOUSEWHEEL:
                iapp->mouseWheelEvent(makeEvent(event.wheel));
                break;

            case SDL_KEYDOWN:
            case SDL_KEYUP:
                iapp->keyEvent(makeEvent(event.key));
                break;

            default:
                break;
            }

            int mcs_e = std::chrono::duration_cast<std::chrono::microseconds>(
                            std::chrono::steady_clock::now() - time)
                        .count();
            time = std::chrono::steady_clock::now();
            iapp->tickEvent(mcs_e);
        }
    }

    return _code;
}

void ApplicationEventsImpl::quit(int code)
{
    if (not _running)
    {
        return;
    }

    _running = false;
    _code = code;
}
