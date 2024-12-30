#include "ball.h"
#include <raylib.h>
#include <iostream>
#include "constants.h"

Ball::Ball()
{
    pos.set(600, 300);
    int xDir = GetRandomValue(0, 1);
    int yDir = GetRandomValue(0, 1);
    xDir = xDir == 0 ? 1 : -1;
    yDir = yDir == 0 ? 1 : -1;
    direction.x = xDir;
    direction.y = yDir;
    speed.set(5, 3);
    radius = 15;
}

void Ball::Draw()
{
    DrawCircle(pos.x, pos.y, radius, YELLOW);
    DrawCircleLines(pos.x, pos.y, radius, WHITE);
}

int Ball::Update()
{
    pos += speed * direction;

    // Bounce off the edges of the screen
    if (pos.y - radius <= 0 || pos.y + radius >= GetScreenHeight())
        direction.y *= -1;

    if (pos.x + radius >= GetScreenWidth())
        return 0;
    if (pos.x - radius <= 0)
        return 1;

    return -1;
}

void Ball::CollisionWithPaddle(Position paddlePos, Position paddleDim, int xDir)
{
    if (pos.x + radius >= paddlePos.x && pos.x - radius <= paddlePos.x + paddleDim.x && pos.y + radius >= paddlePos.y && pos.y - radius <= paddlePos.y + paddleDim.y)
        direction.x = xDir;
}

void Ball::IncrementSpeed()
{
    speed.x = std::min(speed.x + 1, MAXBALLSPEEDX);
    speed.y = std::min(speed.y + 1, MAXBALLSPEEDY);
}
