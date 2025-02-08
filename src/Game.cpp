#include "Game.h"

Game::Game() {}

void Game::Update()
{
  if (IsKeyPressed(KEY_ESCAPE))
  {
    CloseWindow();
  }
}

void Game::Draw()
{
  BeginDrawing();
  ClearBackground(BLACK);
  DrawText("Hello, Space Invaders!", 250, 300, 20, WHITE);
  EndDrawing();
}
