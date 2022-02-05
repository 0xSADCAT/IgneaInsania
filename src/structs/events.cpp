#include "events.hpp"
#include "buttons.hpp"


MouseButtonEvent::MouseButtonEvent(int x, int y, MouseButton button, ButtonState state)
    : _x(x), _y(y), _button(button), _state(state)
{}

int MouseButtonEvent::x() const
{
    return _x;
}

int MouseButtonEvent::y() const
{
    return _y;
}

MouseButton MouseButtonEvent::button() const
{
    return _button;
}

ButtonState MouseButtonEvent::state() const
{
    return _state;
}


MouseMoveEvent::MouseMoveEvent(int x, int y)
    : _x(x), _y(y)
{}

int MouseMoveEvent::x() const
{
    return _x;
}

int MouseMoveEvent::y() const
{
    return _y;
}


MouseWheelEvent::MouseWheelEvent(int x, int y, int delta)
    : _x(x), _y(y), _delta(delta)
{}

int MouseWheelEvent::x() const
{
    return _x;
}

int MouseWheelEvent::y() const
{
    return _y;
}

int MouseWheelEvent::delta() const
{
    return _delta;
}


KeyEvent::KeyEvent(Key key, ButtonState state)
    : _key(key), _state(state)
{}

Key KeyEvent::key() const
{
    return _key;
}

ButtonState KeyEvent::state() const
{
    return _state;
}

