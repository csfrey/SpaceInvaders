#include "raylib.h"
#include "menu.h"

int NUM_OPTIONS = 2;

Menu::Menu()
{
  currentOption = 0;
}

void Menu::Update(GameState &gameState)
{
  if (IsKeyPressed(KEY_UP))
    currentOption = (currentOption + 1) % NUM_OPTIONS;
  else if (IsKeyPressed(KEY_DOWN))
    currentOption = (currentOption - 1 + NUM_OPTIONS) % NUM_OPTIONS;
  else if (IsKeyPressed(KEY_RIGHT))
  {
    if (currentOption == 0)
    {
      gameState.difficulty = Difficulty((gameState.difficulty + 1) % DIFFICULTY_SIZE);
    }
  }
  else if (IsKeyPressed(KEY_LEFT))
  {
    if (currentOption == 0)
    {
      gameState.difficulty = Difficulty((gameState.difficulty - 1 + DIFFICULTY_SIZE) % DIFFICULTY_SIZE);
    }
  }
  else if (IsKeyPressed(KEY_ENTER))
  {
    switch (currentOption)
    {
    case 0:
      gameState.sceneState = GAME;
      break;
    case 1:
      gameState.sceneState = EXIT;
      break;
    default:
      // handle
      break;
    }
  }
}

void Menu::Draw(GameState &gameState)
{
  DrawText("SPACE INVADERS", 200, 100, 40, WHITE);
  DrawText("Start Game:", 200, 200, 30, currentOption == 0 ? YELLOW : WHITE);
  DrawText("Exit", 200, 250, 30, currentOption == 1 ? YELLOW : WHITE);

  switch (gameState.difficulty)
  {
  case EASY:
    DrawText("EASY", 420, 200, 30, GREEN);
    break;

  case MEDIUM:
    DrawText("MEDIUM", 420, 200, 30, YELLOW);
    break;

  case HARD:
    DrawText("HARD", 420, 200, 30, RED);
    break;

  default:
    break;
  }
}