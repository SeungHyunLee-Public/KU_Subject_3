#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double toc(double tstart);
#define DTYPE double
#define SWAP(aa, bb) { DTYPE tmp; tmp = aa; aa=bb; bb=tmp;}

DTYPE *mk_rand_data(int N);
void	shellsort(DTYPE arr[], int N);

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
	shellsort(arr, N);
	printf("shellsort:%f\n", toc(tstart));
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

void	shellsort(DTYPE arr[], int N)
{
	int i, j, k, h;
	DTYPE cur_el;
	int hk[]={2047, 701, 31, 15, 4, 1, 0};
	for (k = 0; hk[k] != 0; k++)
	{
		h = hk[k];
	}
//#pragma omp parallel for shared(arr, N, hk, h)
		for (i = h; i < N; i++)
		{
			cur_el = arr[i]; //정렬 안된 부분의 가장 왼쪽원소
			j = i - h;
			while ((j >= 0) && (arr[j] > cur_el))
			{
				arr[j + h] = arr[j]; //현재원소가 j위치에 삽입가능
				j = j - h;				 //num_op++;
			}
			arr[j + h] = cur_el;
		}
}
