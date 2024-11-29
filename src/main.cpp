#include <raylib.h>
#include "ball.h"
#include "paddle.h"

int SCREEN_WIDTH = 1200;
int SCREEN_HEIGHT = 600;

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pongo");
    SetTargetFPS(60);

    Ball ball;
    Paddle paddle1(1);
    Paddle paddle2(2);

    // Game Loop
    while (WindowShouldClose() == false)
    {
        // Event Handling

        // Updating Positions
        ball.Update();
        paddle1.Update();
        paddle2.Update();

        // Checking collisions
        ball.CollisionWithPaddle(paddle1.GetPosition(), paddle1.GetDimensions());
        ball.CollisionWithPaddle(paddle2.GetPosition(), paddle2.GetDimensions());

        // Drawing
        BeginDrawing();
        ClearBackground(BLACK);

        ball.Draw();
        paddle1.Draw();
        paddle2.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
