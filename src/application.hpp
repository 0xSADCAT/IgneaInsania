#pragma once

#include <string>
#include <vector>

#include "structs/events.hpp"


#define iapp \
    Application::instance()


class Window;
class Game;
class ApplicationEventsImpl;


class Application
{
public:
    Application(int argc, char** argv);
    ~Application();

    static Application* instance();

    void setWindow(Window* window);
    void setGameModel(Game* game);

    int execute();

    void quit(int code = 0);

    const std::vector<std::string>& arguments() const;

protected:
    void mouseButtonEvent(const MouseButtonEvent &event);
    void mouseMoveEvent(const MouseMoveEvent &event);
    void mouseWheelEvent(const MouseWheelEvent &event);
    void keyEvent(const KeyEvent &event);

    void tickEvent(int microseconds_elapsed);

private:
    ApplicationEventsImpl* _events_impl;

    std::vector<std::string> _arguments;

    Window* _window = nullptr;
    Game* _game = nullptr;

    Application(Application&) = delete;
    Application(Application&&) = delete;
    Application& operator=(Application&) = delete;
    Application& operator=(Application&&) = delete;

    friend class ApplicationEventsImpl;
};

