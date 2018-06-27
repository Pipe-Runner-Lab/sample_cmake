#include <stdlib.h>
#include <time.h>

int getRandom()
{
	srand(time(0));
	return (rand() % 3);
}