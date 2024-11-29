#pragma once
#include "ball.h"
#include "paddle.h"

class Game
{
private:
    Ball ball;
    Paddle paddle1;
    Paddle paddle2;

public:
    Game() : ball(), paddle1(1), paddle2(2) {}
    void Update();
    void Draw();
    void CheckCollisions();
    void Reset();
};
