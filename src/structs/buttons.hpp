#pragma once


enum class MouseButton
{
    Left,
    Right,
    Middle
};


enum class Key
{
    Up, Down, Left, Right,
    Tilda, _1, _2, _3, _4, _5, _6, _7, _8, _9, _0,
    Q, W, E, R, T, Y, U, I, O, P,
    A, S, D, F, G, H, J, K, L,
    Z, X, C, V, B, N, M,
    LShift, RShift,
    LCtrl, RCtrl,
    LAlt, RAlt,
    Space, Tab, Enter,
    Num0, Num1, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9,
    NumDel, NumEnter, NumPlus, NumMinus, NumDiv, NumMul
};


enum class ButtonState
{
    Pressed,
    Released
};

