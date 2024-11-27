#pragma once
#include "position.h"
#include <raylib.h>

class Paddle
{
private:
    struct Controls
    {
        int upKey;
        int downKey;

        Controls() : upKey(0), downKey(0) {}
        Controls(int player)
        {
            if (player == 1)
            {
                upKey = KEY_UP;
                downKey = KEY_DOWN;
            }
            else if (player == 2)
            {
                upKey = KEY_W;
                downKey = KEY_S;
            }
        }
    };

    Controls controls;
    Position pos;
    int speed;
    int width;
    int height;

public:
    Paddle();
    Paddle(int player);
    void Draw();
    void Update();
    void MoveUp();
    void MoveDown();
};
