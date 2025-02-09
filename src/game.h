#ifndef GAME_H
#define GAME_H

#include "screen.h"
#include "gamestate.h"
#include <vector>

// enum Lifecycle
// {
//   ALIVE,
//   DYING,
//   DEAD
// };

// class Entity
// {
// public:
//   virtual void Update(GameState &gameState) = 0;
//   virtual void Draw(GameState &gameState) = 0;
//   virtual ~Entity();

//   float posX;
//   float posY;
//   float speed;
//   Lifecycle lifecycle;
// };

// class Player : public Entity
// {
// public:
//   Player(GameState &gameState);
//   void Update(GameState &gameState);
//   void Draw(GameState &gameState);
// };

// class Bullet : public Entity
// {
// public:
//   Bullet(GameState &gameState);
//   void Update(GameState &gameState);
//   void Draw(GameState &gameState);
// };

class Game : public Screen
{
public:
  Game(GameState &gameState);
  void Update(GameState &gameState);
  void Draw(GameState &gameState);

private:
  //   Player player;
  //   std::vector<Bullet> bullets;
  float blinkerAlpha;
  bool isBlinkIncreasing;
};

#endif