#pragma once


#include "../structs/events.hpp"


class Game
{
public:
    Game() = default;

    void onMouseButtonEvent(const MouseButtonEvent& event);
    void onMouseMoveEvent(const MouseMoveEvent& event);
    void onMouseWheelEvent(const MouseWheelEvent& event);
    void onKeyEvent(const KeyEvent& event);

    void onTickEvent(int microseconds_elapsed);
};

