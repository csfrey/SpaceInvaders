#include "raylib.h"
#include "game.h"
#include <vector>

// Entity::~Entity() {}

Game::Game(GameState &gameState)
{
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

    int gap = 50;
    int center = GetScreenWidth() / 2;
    std::vector<char *> actions = {"Move", "Fire", "Pause"};
    std::vector<std::string> controls = {"A D or ← →", "SPACE", "P"};

    for (int i = 0; i < actions.size(); i++)
    {
      int textSize = 30;
      int textWidth = MeasureText(actions[i], textSize);
    }

    break;
  }
  case RUN:
    DrawText("P to pause", 200, 100, 40, WHITE);
    break;
  case PAUSE:
    DrawText("P to resume", 200, 100, 40, WHITE);
    break;
  default:
    // HANDLE
    break;
  }
}