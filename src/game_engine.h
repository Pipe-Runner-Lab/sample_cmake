#pragma once

class GameEngine
{
  private:
	int chance;

  public:
	GameEngine(int chance);
	void guess(int num);
};