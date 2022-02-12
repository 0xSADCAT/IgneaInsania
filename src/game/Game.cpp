#include "Game.hpp"

#include <iostream>
#include <thread>


void Game::onMouseButtonEvent(const MouseButtonEvent& event)
{
    if (event.state() == ButtonState::Pressed)
    {
        switch (event.button())
        {
        case MouseButton::Left:
            _player.setFlip(Flip::Horizontal);
            break;

        case MouseButton::Right:
            _player.setFlip(Flip::Vertical);
            break;

        case MouseButton::Middle:
            _player.setFlip(Flip::None);
            break;

        default:
            break;
        }
    }
}

void Game::onMouseMoveEvent([[maybe_unused]] const MouseMoveEvent& event)
{
}

void Game::onMouseWheelEvent(const MouseWheelEvent& event)
{
    _player.setRotation(_player.rotation() + 5 * event.deltaY());
}

void Game::onKeyEvent(const KeyEvent& event)
{
    // Needs state machine here and for all events
    static constexpr double speed_delta = 150.0;

    Size speed = _player.speed();

    switch (event.key()) {
    case Key::W:
        speed.setHeight(event.state() == ButtonState::Pressed ? -speed_delta : 0.0);
        break;

    case Key::S:
        speed.setHeight(event.state() == ButtonState::Pressed ? speed_delta : 0.0);
        break;

    case Key::A:
        speed.setWidth(event.state() == ButtonState::Pressed ? -speed_delta : 0.0);
        break;

    case Key::D:
        speed.setWidth(event.state() == ButtonState::Pressed ? speed_delta : 0.0);
        break;

    default:
        break;
    }

    _player.setSpeed(speed);
}

void Game::onTickEvent(int microseconds_elapsed)
{
    static int time = 0;

    time += microseconds_elapsed;

    if (time < 5'000)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
    else
    {
        _player.move(time);
        time = 0;
    }
}

const Player& Game::player() const
{
    return _player;
}
