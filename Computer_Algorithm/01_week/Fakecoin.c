#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int		*find_bad_coin(int *coins, int n);
int		main(int argc, char *argv[])
{
	int		i, n, fake;
	int		*coins, *bad_coin;

	(void) argc;
	n = atoi(argv[1]);
	//	fake = atoi(argv[2]);
	srand(time(NULL));
	coins = (int *)malloc((n) * sizeof(int));

	for(i = 0; i < n; i++) // 여분 짝수로
		coins[i] = 10;

	fake = rand()%n; //	가짜 동전 위치
	coins[fake] = 5;

	bad_coin = find_bad_coin(coins, n);
	printf("coins [%d]=%d:,coins[%d]=%d\n", fake, coins[fake], (int)(bad_coin-coins), *bad_coin);
}

int		*find_bad_coin(int *coins, int n)
{
	int i, mid = n / 2, sum1 = 0, sum2 = 0, *coins2;
	static int count = 0;

	if (n <= 1)
	{
		printf("Found it! with %d iteration", count);
		count = 0;
		return coins; // (coins[0] < coins[1]) ? coins : coins+1;
	}

	coins2 = coins + mid;
	for (i = 0; i < mid; i++)
	{
		sum1 += coins[i];
		sum2 += coins2[i];
	}
	count++;
	if (sum1 < sum2)
		return find_bad_coin(coins, mid);
	else
		return find_bad_coin(coins2, mid);
}

