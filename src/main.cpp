#include "raylib.h"

int main()
{
    InitWindow(800, 600, "Space Invaders - Raylib");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_ESCAPE))
        {
            CloseWindow();
        }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Hello, Space Invaders!", 250, 300, 20, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}