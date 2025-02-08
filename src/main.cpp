#include "raylib.h"
#include "GameState.h"
#include "Menu.h"

int main()
{
    GameState gameState = MENU;
    Difficulty difficulty = EASY;
    Menu menu;

    InitWindow(800, 600, "Space Invaders - Raylib");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        switch (gameState)
        {
        case MENU:
        {
            // do menu stuff
            menu.Update(gameState, difficulty);
            menu.Draw(difficulty);
        }

        case GAME:
        {
            // run the game
        }

        default:
        {
            // handle errors
        }
        }
    }

    CloseWindow();
    return 0;
}