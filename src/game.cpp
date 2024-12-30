#include "game.h"
#include "ball.h"
#include "constants.h"

void Game::Update()
{
    int ballFailed = ball.Update();
    if (ballFailed == 0)
    {
        playerOneScore++;
        Reset();
        isRunning = false;
    }
    else if (ballFailed == 1)
    {
        playerTwoScore++;
        Reset();
        isRunning = false;
    }

    if (playerOneScore >= GAMEWINSCORE || playerTwoScore >= GAMEWINSCORE)
    {
        isRunning = false;
        isGameOver = true;
        return;
    }

    if (ballFailed == 0 || ballFailed == 1)
        return;

    paddle1.Update();
    paddle2.Update();

    int timeElapsed = GetTime() - inningsTime;
    if (timeElapsed != 0 && timeElapsed % SPEEDINCREMENTTIME == 0 && !increased)
    {
        ball.IncrementSpeed();
        increased = true;
    }
    else if(timeElapsed % SPEEDINCREMENTTIME != 0)
        increased = false;
}

void Game::Draw()
{
    ball.Draw();
    paddle1.Draw();
    paddle2.Draw();
}

void Game::CheckCollisions()
{
    ball.CollisionWithPaddle(paddle1.GetPosition(), paddle1.GetDimensions(), 1);
    ball.CollisionWithPaddle(paddle2.GetPosition(), paddle2.GetDimensions(), -1);
}

void Game::Reset()
{
    ball = Ball();
    paddle1 = Paddle(1);
    paddle2 = Paddle(2);
    inningsTime = GetTime();
}

void Game::DisplayScore()
{
    DrawText(TextFormat("%i", playerOneScore), SCREEN_WIDTH / 4 - 20, 10, 80, WHITE);
    DrawText(TextFormat("%i", playerTwoScore), 3 * SCREEN_WIDTH / 4 - 20, 10, 80, WHITE);
}

void Game::DisplayWinner()
{
    DrawText("Game Over!", SCREEN_WIDTH / 2 - 80, 2 * SCREEN_HEIGHT / 3, 30, SOFT_WHITE);
    (playerOneScore > playerTwoScore) ? DrawText("Player 1 wins!", SCREEN_WIDTH / 2 - 100, 2 * SCREEN_HEIGHT / 3 + 50, 30, SOFT_WHITE) : DrawText("Player 2 wins!", SCREEN_WIDTH / 2 - 100, 2 * SCREEN_HEIGHT / 3 + 50, 30, SOFT_WHITE);

    DrawText("Press Enter to continue...", SCREEN_WIDTH / 2 - 200, 2 * SCREEN_HEIGHT / 3 + 100, 30, SOFT_WHITE);
    if (IsKeyPressed(KEY_ENTER))
    {
        playerOneScore = 0;
        playerTwoScore = 0;
        isRunning = true;
        isGameOver = false;
    }
}

void Game::DrawBackground()
{
    DrawRectangle(0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT, MINT_GREEN);
    DrawCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 150, LIGHT_GREEN);
    DrawCircleLines(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 150, SOFT_WHITE);
    DrawLine(SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT, SOFT_WHITE);
}
