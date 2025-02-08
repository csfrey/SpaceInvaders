#ifndef MENU_H
#define MENU_H

#include "raylib.h"
#include "GameState.h"

class Menu
{
public:
  Menu();
  void Update(GameState &gameState, Difficulty &difficulty);
  void Draw(Difficulty &difficulty);

private:
  int selectedOption;
};

#endif