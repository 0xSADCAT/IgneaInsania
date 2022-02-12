#include "ApplicationEventsImpl.hpp"

#include <chrono>
#include <SDL2/SDL.h>
#include "Application.hpp"


namespace
{

MouseButtonEvent makeEvent(const SDL_MouseButtonEvent& event)
{
    MouseButton button;
    switch (event.button)
    {
    case SDL_BUTTON_LEFT:
        button = MouseButton::Left;
        break;

    case SDL_BUTTON_RIGHT:
        button = MouseButton::Right;
        break;

    case SDL_BUTTON_MIDDLE:
        button = MouseButton::Middle;
        break;

    default:
        button = MouseButton::Undefined;
        break;
    }

    return MouseButtonEvent(event.x, event.y, button,
                            event.state == SDL_PRESSED ? ButtonState::Pressed
                                                       : ButtonState::Released);
}

MouseMoveEvent makeEvent(const SDL_MouseMotionEvent& event)
{
    return MouseMoveEvent(event.x, event.y);
}

MouseWheelEvent makeEvent(const SDL_MouseWheelEvent& event)
{
    return MouseWheelEvent(event.x, event.y);
}

KeyEvent makeEvent(const SDL_KeyboardEvent& event);

}


int ApplicationEventsImpl::execute()
{
    if (_running)
    {
        return 1;
    }

    static std::chrono::steady_clock::time_point time = std::chrono::steady_clock::now();

    _running = true;
    _code = 0;
    SDL_Event event;

    while (_running)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            switch (event.type)
            {
            case SDL_QUIT:
                quit(0);
                break;

            case SDL_MOUSEBUTTONDOWN:
            case SDL_MOUSEBUTTONUP:
                iapp->mouseButtonEvent(makeEvent(event.button));
                break;

            case SDL_MOUSEMOTION:
                iapp->mouseMoveEvent(makeEvent(event.motion));
                break;

            case SDL_MOUSEWHEEL:
                iapp->mouseWheelEvent(makeEvent(event.wheel));
                break;

            case SDL_KEYDOWN:
            case SDL_KEYUP:
                if (not event.key.repeat)
                {
                    iapp->keyEvent(makeEvent(event.key));
                }
                break;

            default:
                break;
            }
        }
        
        int mcs_e = std::chrono::duration_cast<std::chrono::microseconds>(
                        std::chrono::steady_clock::now() - time)
                    .count();
        time = std::chrono::steady_clock::now();
        iapp->tickEvent(mcs_e);
    }

    return _code;
}

void ApplicationEventsImpl::quit(int code)
{
    if (not _running)
    {
        return;
    }

    _running = false;
    _code = code;
}

namespace
{

#define CASE(sdlk, key_) \
    case sdlk: \
        key = Key::key_; \
        break;

#define CASE_N(x) \
    case SDLK_##x: \
        key = Key::_##x; \
        break;

#define CASE_NUM(x) \
    case SDLK_KP_##x: \
        key = Key::Num##x; \
        break;

KeyEvent makeEvent(const SDL_KeyboardEvent& event)
{
    Key key;

    switch (event.keysym.sym)
    {
    // ------------------------------------------
    // Arrows
        CASE(SDLK_UP, Up);
        CASE(SDLK_DOWN, Down);
        CASE(SDLK_LEFT, Left);
        CASE(SDLK_RIGHT, Right);

    // ------------------------------------------
    // First line
        CASE(SDLK_BACKQUOTE, Tilda);
        CASE_N(1);
        CASE_N(2);
        CASE_N(3);
        CASE_N(4);
        CASE_N(5);
        CASE_N(6);
        CASE_N(7);
        CASE_N(8);
        CASE_N(9);
        CASE_N(0);

    // ------------------------------------------
    // Second line
        CASE(SDLK_q, Q);
        CASE(SDLK_w, W);
        CASE(SDLK_e, E);
        CASE(SDLK_r, R);
        CASE(SDLK_t, T);
        CASE(SDLK_y, Y);
        CASE(SDLK_u, U);
        CASE(SDLK_i, I);
        CASE(SDLK_o, O);
        CASE(SDLK_p, P);

    // ------------------------------------------
    // Third line
        CASE(SDLK_a, A);
        CASE(SDLK_s, S);
        CASE(SDLK_d, D);
        CASE(SDLK_f, F);
        CASE(SDLK_g, G);
        CASE(SDLK_h, H);
        CASE(SDLK_j, J);
        CASE(SDLK_k, K);
        CASE(SDLK_l, L);

    // ------------------------------------------
    // Fourth line
        CASE(SDLK_z, Z);
        CASE(SDLK_x, X);
        CASE(SDLK_c, C);
        CASE(SDLK_v, V);
        CASE(SDLK_b, B);
        CASE(SDLK_n, N);
        CASE(SDLK_m, M);

    // ------------------------------------------
    // Modifers
        CASE(SDLK_LSHIFT, LShift);
        CASE(SDLK_RSHIFT, RShift);
        CASE(SDLK_LCTRL, LCtrl);
        CASE(SDLK_RCTRL, RCtrl);
        CASE(SDLK_LALT, LAlt);
        CASE(SDLK_RALT, RAlt);

    // ------------------------------------------
    // Around
        CASE(SDLK_SPACE, Space);
        CASE(SDLK_TAB, Tab);
        CASE(SDLK_RETURN, Enter);
        CASE(SDLK_ESCAPE, Esc);

    // ------------------------------------------
    // Num
        CASE(SDLK_KP_PERIOD, NumDel);
        CASE(SDLK_KP_ENTER, NumEnter);
        CASE(SDLK_KP_PLUS, NumPlus);
        CASE(SDLK_KP_MINUS, NumMinus);
        CASE(SDLK_KP_DIVIDE, NumDiv);
        CASE(SDLK_KP_MULTIPLY, NumMul);
        CASE_NUM(1);
        CASE_NUM(2);
        CASE_NUM(3);
        CASE_NUM(4);
        CASE_NUM(5);
        CASE_NUM(6);
        CASE_NUM(7);
        CASE_NUM(8);
        CASE_NUM(9);
        CASE_NUM(0);

    // ------------------------------------------
    default:
        key = Key::Undefined;
        break;
    }

    return KeyEvent(key, event.state == SDL_PRESSED ? ButtonState::Pressed : ButtonState::Released);
}

#undef CASE
#undef CASE_N
#undef CASE_NUM

}
