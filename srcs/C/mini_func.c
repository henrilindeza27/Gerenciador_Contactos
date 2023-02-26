#include "default.h"

void	cleanScrean(void)
{
	system("clear");
}

void	cleanBuffer(void)
{
	while (getchar() != '\n')
		;
}