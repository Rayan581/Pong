#include <raylib.h>
#include "game.h"

int SCREEN_WIDTH = 1200;
int SCREEN_HEIGHT = 600;

Color LIGHT_GREEN = {129, 204, 184, 255};
Color DARK_GREEN = {20, 160, 133, 255};
Color SOFT_WHITE = {255, 255, 255, 150};
Color MINT_GREEN = {38, 185, 154, 255};

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
        ClearBackground(DARK_GREEN);

        DrawRectangle(0, 0, GetScreenWidth() / 2, GetScreenHeight(), MINT_GREEN);
        DrawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, 150, LIGHT_GREEN);
        DrawCircleLines(GetScreenWidth() / 2, GetScreenHeight() / 2, 150, SOFT_WHITE);
        DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), SOFT_WHITE);

        game.Draw();
        game.DisplayScore();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
