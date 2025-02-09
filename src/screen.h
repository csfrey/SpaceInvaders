#ifndef SCREEN_H
#define SCREEN_H

#include "gamestate.h"

class Screen
{
public:
  virtual void Update(GameState &gameState) = 0;
  virtual void Draw(GameState &gameState) = 0;
  virtual ~Screen();
};

#endif