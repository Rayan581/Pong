#include "game.h"
#include "ball.h"

void Game::Update()
{
    int ballFailed = ball.Update();
    if (ballFailed == 0)
    {
        playerOneScore++;
        Reset();
        return;
    }
    else if (ballFailed == 1)
    {
        playerTwoScore++;
        Reset();
        return;
    }

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
    ball.CollisionWithPaddle(paddle1.GetPosition(), paddle1.GetDimensions(), 5);
    ball.CollisionWithPaddle(paddle2.GetPosition(), paddle2.GetDimensions(), -5);
}

void Game::Reset()
{
    ball = Ball();
    paddle1 = Paddle(1);
    paddle2 = Paddle(2);
}

void Game::DisplayScore()
{
    DrawText(TextFormat("%i", playerOneScore), GetScreenWidth() / 4 - 20, 10, 80, WHITE);
    DrawText(TextFormat("%i", playerTwoScore), 3 * GetScreenWidth() / 4 - 20, 10, 80, WHITE);
}
