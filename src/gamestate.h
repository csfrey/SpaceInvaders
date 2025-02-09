#ifndef GAMESTATE_H
#define GAMESTATE_H

enum SceneState
{
  MENU,
  GAME,
  EXIT,
  SCENES_SIZE,
};

enum Difficulty
{
  EASY,
  MEDIUM,
  HARD,
  DIFFICULTY_SIZE,
};

enum GameSceneState
{
  START,
  RUN,
  PAUSE,
  QUIT,
  GAME_SCENE_SIZE,
};

class GameState
{
public:
  GameState();
  GameState(SceneState s, Difficulty d);
  SceneState sceneState;
  Difficulty difficulty;
  GameSceneState gameSceneState;
};

#endif