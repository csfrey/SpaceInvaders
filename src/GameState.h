#ifndef GAMESTATE_H
#define GAMESTATE_H

enum GameState
{
  MENU,
  GAME,
  PAUSE
};

enum Difficulty
{
  EASY,
  MEDIUM,
  HARD,
  DIFFICULTY_MAX = HARD,
};

#endif