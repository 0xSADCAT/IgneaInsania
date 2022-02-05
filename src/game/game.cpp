#include "game.hpp"

#include <iostream>


void Game::onMouseButtonEvent(const MouseButtonEvent& event)
{
    std::cout << event << std::endl;
}

void Game::onMouseMoveEvent(const MouseMoveEvent& event)
{
    std::cout << event << std::endl;
}

void Game::onMouseWheelEvent(const MouseWheelEvent& event)
{
    std::cout << event << std::endl;
}

void Game::onKeyEvent(const KeyEvent& event)
{
    std::cout << event << std::endl;
}

void Game::onTickEvent(int microseconds_elapsed)
{
    static int time = 0;
    time += microseconds_elapsed;

    if (time > 5000000)
    {
        time = 0;
        std::cout << "Elapsed 5 seconds" << std::endl;
    }
}
