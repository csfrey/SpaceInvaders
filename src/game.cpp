#include "raylib.h"
#include "game.h"
#include <vector>
#include <iostream>

Entity::~Entity() {}

Bullet::Bullet(int x, int y, int s)
{
  posX = x;
  posY = y;
  speed = s;
}

void Bullet::Update(GameState &gameState)
{
  posY += speed;
}

void Bullet::Draw(GameState &gameState)
{
  DrawRectangle(posX - 1, posY, 2, 5, BLUE);
}

Player::Player()
{
  posX = GetScreenWidth() / 2;
  posY = 500;
  speed = 8;
  lifecycle = ALIVE;
}

void Player::Update(GameState &gameState)
{
  if ((IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) && posX < GetScreenWidth() - 20)
  {
    posX += speed;
  }
  else if ((IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) && posX > 0)
  {
    posX -= speed;
  }
}

void Player::Draw(GameState &gameState)
{
  DrawRectangle(posX, posY, 20, 20, RED);
}

Game::Game(GameState &gameState)
{
  Player player;
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

  if (IsKeyPressed(KEY_SPACE))
  {
    Bullet bullet(player.posX + 10, player.posY, -15);
    bullets.push_back(bullet);
  }

  if (gameState.gameSceneState == RUN)
  {
    player.Update(gameState);
    for (auto &bullet : bullets)
      bullet.Update(gameState);
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

    player.Draw(gameState);
    for (auto &bullet : bullets)
      bullet.Draw(gameState);

    bullets.erase(std::remove_if(bullets.begin(), bullets.end(),
                                 [](Bullet &b)
                                 { return b.posY < 0; }),
                  bullets.end());
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