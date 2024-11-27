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
    if (pos.x - radius <= 0 || pos.x + radius >= 1200)
        speed.x *= -1;
    if (pos.y - radius <= 0 || pos.y + radius >= 600)
        speed.y *= -1;
}
