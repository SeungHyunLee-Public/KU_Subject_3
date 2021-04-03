#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double toc(double tstart);
#define DTYPE float
#define SWAP(aa, bb) { DTYPE tmp; tmp = aa; aa=bb; bb=tmp;}

DTYPE *mk_rand_data(int N);
void	insertionsort(DTYPE arr[], int N);

int		main(int argc, char *argv[])
{
	DTYPE	*arr;
	double	tstart;
	int		N;//, i;

	(void) argc;
	N = atoi(argv[1]);
	srand(time(NULL));
	arr = mk_rand_data(N);
	printf("\n sort ....\n");
	tstart = clock();
	insertionsort(arr, N);
	printf("insertionsort:%f\n", toc(tstart));
//	for(i = 0; i < N; i++)
//		printf("%f \n", arr[i]);
	return (0);
}

double	toc(double tstart)
{
	return (clock() - tstart) / CLOCKS_PER_SEC;
}

DTYPE *mk_rand_data(int N)
{
	DTYPE *arr = (DTYPE *) malloc(sizeof(DTYPE) * N);
	for (int i = 0; i < N; i++)
		arr[i] = rand() / (DTYPE) RAND_MAX;
	return arr;
}

void	insertionsort(DTYPE arr[], int N)
{
	int i, j;
	DTYPE cur_el;
	for (i = 1; i < N; i++)
	{
		cur_el = arr[i]; //정렬 안된 부분의 가장 왼쪽원소
		j = i - 1;
		while ((j >= 0) && (arr[j] > cur_el))
		{
			arr[j + 1] = arr[j]; //현재원소가 j위치에 삽입가능
			j--;				 //num_op++;
		}
		arr[j + 1] = cur_el;
	}
}
