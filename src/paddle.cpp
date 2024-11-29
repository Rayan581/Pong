#include "paddle.h"
#include <raylib.h>

Paddle::Paddle()
{
    width = 20;
    height = 100;
    pos.set(10, (GetScreenHeight() / 2) - (height / 2));
    speed = 4;
}

Paddle::Paddle(int player)
{
    speed = 4;
    width = 20;
    height = 100;
    controls = Controls(player);
    if (player == 1)
        pos.x = 10;
    else if (player == 2)
        pos.x = GetScreenWidth() - width - 10;
    pos.y = (GetScreenHeight() / 2) - (height / 2);
}

void Paddle::Draw()
{
    DrawRectangleRounded(Rectangle{float(pos.x), float(pos.y), float(width), float(height)}, 5, 6, WHITE);
}

void Paddle::Update()
{
    if (IsKeyDown(controls.upKey))
        MoveUp();
    else if (IsKeyDown(controls.downKey))
        MoveDown();
}

void Paddle::MoveUp()
{
    pos.y -= speed;
    if (pos.y <= 0)
        pos.y = 0;
}

void Paddle::MoveDown()
{
    pos.y += speed;
    if (pos.y + height >= GetScreenHeight())
        pos.y = GetScreenHeight() - height;
}

Position Paddle::GetPosition()
{
    return pos;
}

Position Paddle::GetDimensions()
{
    return Position(width, height);
}
