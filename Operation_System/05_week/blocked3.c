#include <unistd.h>

int		main(void)
{
	int		i;

	do {
		sleep(1);
		for (i = 0; i < 100000000; i++)
		;
	} while(1);
}

