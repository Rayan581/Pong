#include "ball.h"
#include <raylib.h>

Ball::Ball()
{
    pos.set(600, 300);
    speed.set(5, -3);
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

void Ball::CollisionWithPaddle(Position paddlePos, Position paddleDim)
{
    if (pos.x + radius >= paddlePos.x && pos.x - radius <= paddlePos.x + paddleDim.x && pos.y + radius >= paddlePos.y && pos.y - radius <= paddlePos.y + paddleDim.y)
        speed.x *= -1;
}
