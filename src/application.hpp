#pragma once

#include <string>
#include <vector>

#include "ui/window.hpp"


#define iapp \
    Application::instance()


class ApplicationImpl;


class Application
{
public:
    Application(int argc, char** argv);
    ~Application();

    static Application* instance();

    void setWindow(Window* window);

    int execute();

    void quit(int code = 0);

    const std::vector<std::string>& arguments() const;

private:
    ApplicationImpl* _impl;

    Application(Application&) = delete;
    Application(Application&&) = delete;
    Application& operator=(Application&) = delete;
    Application& operator=(Application&&) = delete;
};

