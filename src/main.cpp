#include "raylib.h"
#include "gamestate.h"
#include "screen.h"
#include "menu.h"
#include "game.h"
#include "starfield.h"

int main()
{
    InitWindow(800, 600, "Space Invaders - Raylib");
    SetTargetFPS(60);
    SetExitKey(KEY_NULL);

    Starfield starfield;
    GameState gameState;
    Menu menu;
    Game game(gameState);
    Screen *screen = &menu; // Screen <- Menu

    while (!WindowShouldClose())
    {
        switch (gameState.sceneState)
        {
        case MENU:
            screen = &menu;
            break;

        case GAME:
            screen = &game;
            break;

        case EXIT:
            CloseWindow();
            break;

        default:
            // handle error
            break;
        }

        // update section
        starfield.Update();
        screen->Update(gameState);

        // draw section
        BeginDrawing();
        ClearBackground(BLACK);
        starfield.Draw();
        screen->Draw(gameState);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}