#pragma once

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
    MouseWheelEvent(int x, int y, int delta);

    int x() const;
    int y() const;

    int delta() const;

private:
    const int _x;
    const int _y;
    const int _delta;
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

