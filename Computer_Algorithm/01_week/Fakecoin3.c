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

	fake = rand()%(n); //	가짜 동전 위치
	coins[fake] = 5;

	bad_coin = find_bad_coin(coins, n);
	printf("coins [%d]=%d:,coins[%d]=%d\n", fake, coins[fake], (int)(bad_coin-coins), *bad_coin);
}

int		*find_bad_coin(int *coins, int n)
{
	int i, one3rd, sum1 = 0, sum2 = 0, sum3 = 0, *coins2, *coins3;
	static int count = 0;
	if (n <= 1)
	{
		printf("Found it! with %d iteration", count);
		count = 0;
		return coins; // (coins[0] < coins[1]) ? coins : coins+1;
	}

	if (n % 3 == 0)
	{
		one3rd = n / 3;
	}
	else if (n % 3 == 1)
		one3rd = (n + 2) / 3;
	else
		one3rd = (n + 1) / 3;

	coins2 = coins + one3rd;
	coins3 = coins + (n - 2*one3rd);

	for (i = 0; i < one3rd; i++)
	{
		sum1 += coins[i];
		sum2 += coins2[i];
		sum3 += coins3[i];
	}
	count++;
	if (sum1 < sum2)
		return find_bad_coin(coins, one3rd);
	else if (sum1 > sum2)
		return find_bad_coin(coins2, one3rd);
	else //if (sum1 == sum2)
		return find_bad_coin(coins3, n - 2*one3rd);
}
