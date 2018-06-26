#include <sample_cmake/game_interface.h>

int main()
{
	GameInterface g(3);
	g.play(0);
	g.play(1);
	g.play(2);
	g.play(4);
	return 0;
}