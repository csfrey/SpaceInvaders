#include "Menu.h"

int NUM_OPTIONS = 3;

Menu::Menu()
{
  selectedOption = 0; // "start" = 0, "difficulty" = 1, "exit" = 2
}

void Menu::Update(GameState &gameState, Difficulty &difficulty)
{
  // move down an option or wrap to top
  if (IsKeyPressed(KEY_DOWN))
    selectedOption = (selectedOption + 1) % NUM_OPTIONS;

  // move up an option or wrap to bottom
  else if (IsKeyPressed(KEY_UP))
    selectedOption = (selectedOption - 1 + NUM_OPTIONS) % NUM_OPTIONS;

  else if (IsKeyPressed(KEY_ENTER))
  {
    // change the game state or difficulty based on the current selected option
    switch (selectedOption)
    {
    case 0:
    {
      gameState = GAME;
      break;
    }
    case 1:
    {
      // ???
    }
    case 2:
    {
      CloseWindow();
      break;
    }
    default:
    {
      // handle errors
    }
    }
  }

  else if (selectedOption == 1)
  {
    // difficulty selector
    if (IsKeyPressed(KEY_RIGHT))
      difficulty = Difficulty((difficulty + 1) % (DIFFICULTY_MAX + 1));
    else if (IsKeyPressed(KEY_LEFT))
      difficulty = Difficulty((difficulty - 1 + (DIFFICULTY_MAX + 1)) % (DIFFICULTY_MAX + 1));
  }
}

void Menu::Draw(Difficulty &difficulty)
{
  BeginDrawing();
  ClearBackground(BLACK);

  DrawText("SPACE INVADERS", 200, 100, 40, WHITE);

  DrawText("Start Game", 200, 250, 30, selectedOption == 0 ? YELLOW : WHITE);
  DrawText("Difficulty:", 200, 300, 30, selectedOption == 1 ? YELLOW : WHITE);
  DrawText("Exit", 200, 350, 30, selectedOption == 2 ? YELLOW : WHITE);

  DrawText("Easy", 370, 300, 30, difficulty == EASY ? YELLOW : WHITE);
  DrawText("Medium", 450, 300, 30, difficulty == MEDIUM ? YELLOW : WHITE);
  DrawText("Hard", 560, 300, 30, difficulty == HARD ? YELLOW : WHITE);

  EndDrawing();
}