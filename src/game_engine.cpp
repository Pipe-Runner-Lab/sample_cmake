#include <iostream>
#include <game_engine.h>
#include <Logger/logger_util.h>
#include <Randomize/randomize_util.h>

GameEngine::GameEngine(int chance)
{
	this->chance = chance;
}

void GameEngine::guess(int num)
{
	if (this->chance > 0)
	{
		if (getRandom() == num)
		{
			log("Good guess");
		}
		else
		{
			log("Nope!");
		}
		this->chance--;
	}
	else
	{
		log("Out of chances, Sorry");
		// Log out of luck
	}
}