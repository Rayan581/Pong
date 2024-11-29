#include "ball.h"
#include <raylib.h>

Ball::Ball()
{
    pos.set(600, 300);
    int xDir = GetRandomValue(0, 1);
    int yDir = GetRandomValue(0, 1);
    xDir = xDir == 0 ? 1 : -1;
    yDir = yDir == 0 ? 1 : -1;
    speed.set(5 * xDir, 3 * yDir);
    radius = 10;
}

void Ball::Draw()
{
    DrawCircle(pos.x, pos.y, radius, WHITE);
}

void Ball::Update()
{
    pos += speed;

    // Bounce off the edges of the screen
    if (pos.y - radius <= 0 || pos.y + radius >= 600)
        speed.y *= -1;
}

void Ball::CollisionWithPaddle(Position paddlePos, Position paddleDim, int xDir)
{
    if (pos.x + radius >= paddlePos.x && pos.x - radius <= paddlePos.x + paddleDim.x && pos.y + radius >= paddlePos.y && pos.y - radius <= paddlePos.y + paddleDim.y)
        speed.x = xDir;
}
