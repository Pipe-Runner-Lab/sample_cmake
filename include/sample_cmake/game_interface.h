#pragma once

#include <game_engine.h>

class GameInterface
{
  private:
	GameEngine *game;

  public:
	GameInterface(int length);
	void play(int num);
};