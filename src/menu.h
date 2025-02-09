#ifndef MENU_H
#define MENU_H

#include "screen.h"

class Menu : public Screen
{
public:
  Menu();
  void Update(GameState &gameState) override;
  void Draw(GameState &gameState) override;

private:
  int currentOption;
};

#endif