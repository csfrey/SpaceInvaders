#include "raylib.h"
#include "game.h"
#include <vector>
#include <iostream>

// Entity::~Entity() {}

Game::Game(GameState &gameState)
{
  isBlinkIncreasing = true;
  blinkerAlpha = 0.5f;
}

void Game::Update(GameState &gameState)
{
  if (gameState.gameSceneState == START && IsKeyPressed(KEY_SPACE))
    gameState.gameSceneState = RUN;

  if (IsKeyPressed(KEY_P))
    if (gameState.gameSceneState == RUN)
      gameState.gameSceneState = PAUSE;
    else if (gameState.gameSceneState == PAUSE)
      gameState.gameSceneState = RUN;

  if (isBlinkIncreasing)
  {
    blinkerAlpha += 0.015f;
    if (blinkerAlpha >= 1.0f)
    {
      blinkerAlpha = 1.0f;
      isBlinkIncreasing = false;
    }
  }
  else
  {
    blinkerAlpha -= 0.015f;
    if (blinkerAlpha <= 0.1f)
    {
      blinkerAlpha = 0.1f;
      isBlinkIncreasing = true;
    }
  }
}

void Game::Draw(GameState &gameState)
{
  switch (gameState.gameSceneState)
  {
  case START:
  {
    int titleSize = 40;
    char *title = "CONTROLS";
    int titleWidth = MeasureText(title, titleSize);
    DrawText(title, (GetScreenWidth() - titleWidth) / 2, 100, titleSize, WHITE);

    int gap = 20;
    int center = GetScreenWidth() / 2;
    int textSize = 30;
    std::vector<char *> actions = {"Move", "Fire", "Pause"};
    std::vector<char *> controls = {"A + D or <- + ->", "SPACE", "P"};

    for (int i = 0; i < actions.size(); i++)
    {
      int posY = 200 + 80 * i;
      int textWidth = MeasureText(actions[i], textSize);
      DrawText(actions[i], center - gap - textWidth, posY, textSize, YELLOW);
      DrawText(controls[i], center + gap, posY, textSize, WHITE);
    }

    char *startMessage = "press SPACE to start";
    int startMessageWidth = MeasureText(startMessage, textSize);
    DrawText(startMessage, (GetScreenWidth() - startMessageWidth) / 2, 500, textSize, Fade(WHITE, blinkerAlpha));
    break;
  }

  case RUN:
  {
    int titleSize = 40;
    char *title = "GAME RUNNING";
    int titleWidth = MeasureText(title, titleSize);
    DrawText(title, (GetScreenWidth() - titleWidth) / 2, 100, titleSize, WHITE);
    break;
  }

  case PAUSE:
  {
    int titleSize = 40;
    char *title = "GAME PAUSED";
    int titleWidth = MeasureText(title, titleSize);
    DrawText(title, (GetScreenWidth() - titleWidth) / 2, 100, titleSize, WHITE);

        int textSize = 30;
    char *startMessage = "press P to resume";
    int startMessageWidth = MeasureText(startMessage, textSize);
    DrawText(startMessage, (GetScreenWidth() - startMessageWidth) / 2, 500, textSize, Fade(WHITE, blinkerAlpha));
  }
  default:
    // HANDLE
    break;
  }
}