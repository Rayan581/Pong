#include "game.h"
#include "ball.h"

void Game::Update()
{
    ball.Update();
    paddle1.Update();
    paddle2.Update();
}

void Game::Draw()
{
    ball.Draw();
    paddle1.Draw();
    paddle2.Draw();
}

void Game::CheckCollisions()
{
    ball.CollisionWithPaddle(paddle1.GetPosition(), paddle1.GetDimensions());
    ball.CollisionWithPaddle(paddle2.GetPosition(), paddle2.GetDimensions());
}

void Game::Reset()
{
    ball = Ball();
    paddle1 = Paddle(1);
    paddle2 = Paddle(2);
}
