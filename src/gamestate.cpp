#include "gamestate.h"

GameState::GameState()
{
  sceneState = MENU;
  difficulty = EASY;
  gameSceneState = START;
}

GameState::GameState(SceneState s, Difficulty d)
{
  sceneState = s;
  difficulty = d;
  gameSceneState = START;
}