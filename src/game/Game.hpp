#pragma once

#include "Player.hpp"
#include "../structs/Events.hpp"


class Game
{
public:
    Game() = default;

    void onMouseButtonEvent(const MouseButtonEvent& event);
    void onMouseMoveEvent(const MouseMoveEvent& event);
    void onMouseWheelEvent(const MouseWheelEvent& event);
    void onKeyEvent(const KeyEvent& event);

    void onTickEvent(int microseconds_elapsed);

    const Player& player() const;

private:
    Player _player = Player({500, 500}, {0, 0});
};

