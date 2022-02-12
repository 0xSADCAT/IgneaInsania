#include "Events.hpp"
#include "Buttons.hpp"


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


MouseWheelEvent::MouseWheelEvent(int x, int y)
    : _delta_x(x), _delta_y(y)
{}

int MouseWheelEvent::deltaX() const
{
    return _delta_x;
}

int MouseWheelEvent::deltaY() const
{
    return _delta_y;
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


std::ostream& operator<<(std::ostream& os, const MouseButtonEvent& event)
{
    os << "MouseButtonEvent<" << event.x() << ", " << event.y() << ", ";

    switch (event.button())
    {
    case MouseButton::Left:
        os << "Left";
        break;

    case MouseButton::Right:
        os << "Right";
        break;

    case MouseButton::Middle:
        os << "Middle";
        break;

    default:
        os << "Undefined";
        break;
    }

    os << ", " << (event.state() == ButtonState::Pressed ? "Pressed" : "Released") << ">";
    return os;
}

std::ostream& operator<<(std::ostream& os, const MouseMoveEvent& event)
{
    os << "MouseMoveEvent<" << event.x() << ", " << event.y() << ">";
    return os;
}

std::ostream& operator<<(std::ostream& os, const MouseWheelEvent& event)
{
    os << "MouseWheelEvent<" << event.deltaX() << ", " << event.deltaY() << ">";
    return os;
}

std::ostream& operator<<(std::ostream& os, const KeyEvent& event)
{
    os << "KeyEvent<code = " << static_cast<int>(event.key()) << ", "
       << (event.state() == ButtonState::Pressed ? "Pressed" : "Released") << ">";
    return os;
}
