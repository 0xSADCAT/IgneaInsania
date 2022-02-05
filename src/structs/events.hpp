#pragma once

#include <ostream>
#include "buttons.hpp"


class MouseButtonEvent
{
public:
    MouseButtonEvent(int x, int y, MouseButton button, ButtonState state);

    int x() const;
    int y() const;

    MouseButton button() const;

    ButtonState state() const;

private:
    const int _x;
    const int _y;

    const MouseButton _button;
    const ButtonState _state;
};


class MouseMoveEvent
{
public:
    MouseMoveEvent(int x, int y);

    int x() const;
    int y() const;

private:
    const int _x;
    const int _y;
};


class MouseWheelEvent
{
public:
    MouseWheelEvent(int delta_x, int delta_y);

    int deltaX() const;
    int deltaY() const;

private:
    const int _delta_x;
    const int _delta_y;
};


class KeyEvent
{
public:
    KeyEvent(Key key, ButtonState state);

    Key key() const;
    ButtonState state() const;

private:
    const Key _key;
    const ButtonState _state;
};


std::ostream& operator<<(std::ostream& os, const MouseButtonEvent& event);
std::ostream& operator<<(std::ostream& os, const MouseMoveEvent& event);
std::ostream& operator<<(std::ostream& os, const MouseWheelEvent& event);
std::ostream& operator<<(std::ostream& os, const KeyEvent& event);
