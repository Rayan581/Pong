#include <raylib.h>
#include "game.h"

int SCREEN_WIDTH = 1200;
int SCREEN_HEIGHT = 600;

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pongo");
    SetTargetFPS(60);

    Game game;

    // Game Loop
    while (WindowShouldClose() == false)
    {
        // Event Handling
        if (IsKeyPressed(KEY_ENTER))
            game.Reset();

        // Updating Positions
        game.Update();

        // Checking collisions
        game.CheckCollisions();

        // Drawing
        BeginDrawing();
        ClearBackground(BLACK);

        DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), WHITE);
        DrawCircleLines(GetScreenWidth() / 2, GetScreenHeight() / 2, 200, WHITE);
        game.Draw();
        game.DisplayScore();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
