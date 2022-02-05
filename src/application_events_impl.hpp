#pragma once


class ApplicationEventsImpl
{
public:
    ApplicationEventsImpl() = default;

    int execute();

    void quit(int code);

private:
    bool _running = false;
    int _code;
};

