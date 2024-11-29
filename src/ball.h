#pragma once
#include "position.h"

class Ball
{
private:
    Position pos;
    Position speed;
    int radius;

public:
    Ball();
    void Draw();
    int Update();
    void CollisionWithPaddle(Position paddlePos, Position paddleDim, int xDir);
};
