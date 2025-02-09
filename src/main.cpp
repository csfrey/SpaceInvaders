#include "raylib.h"
#include "gamestate.h"
#include "screen.h"
#include "menu.h"
#include "starfield.h"

int main()
{
    InitWindow(800, 600, "Space Invaders - Raylib");
    SetTargetFPS(60);

    Starfield starfield;
    GameState gameState;
    Menu menu;
    Screen *screen = &menu;

    while (!WindowShouldClose())
    {
        // do updates
        switch (gameState.sceneState)
        {
        case MENU:
            screen = &menu;
            break;

        case EXIT:
            CloseWindow();
            break;

        default:
            // handle error
            break;
        }

        starfield.Update();
        screen->Update(gameState);

        BeginDrawing();
        ClearBackground(BLACK);
        starfield.Draw();
        screen->Draw(gameState);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}