#include <raylib.h>
#include "game.h"
#include "constants.h"

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pongo");
    SetTargetFPS(60);

    Game game;

    // Game Loop
    while (WindowShouldClose() == false)
    {
        // Event Handling
        if (IsKeyPressed(KEY_ENTER) && !game.isGameOver)
            game.isRunning = true;
        if (game.isRunning)
        {
            // Updating Positions
            game.Update();

            // Checking collisions
            game.CheckCollisions();
        }

        // Drawing
        BeginDrawing();
        ClearBackground(DARK_GREEN);

        DrawRectangle(0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT, MINT_GREEN);
        DrawCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 150, LIGHT_GREEN);
        DrawCircleLines(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 150, SOFT_WHITE);
        DrawLine(SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT, SOFT_WHITE);

        if (!game.isRunning && !game.isGameOver)
            DrawText("Press Enter to continue...", SCREEN_WIDTH / 2 - 200, SCREEN_HEIGHT / 2 + 50, 30, SOFT_WHITE);
        if (game.isGameOver)
            game.DisplayWinner();

        game.Draw();
        game.DisplayScore();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
