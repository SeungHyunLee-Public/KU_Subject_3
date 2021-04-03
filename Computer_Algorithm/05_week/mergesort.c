#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double toc(double tstart);
#define DTYPE float
#define SWAP(aa, bb) {DTYPE tmp; tmp = aa; aa = bb; bb = tmp;}
DTYPE *mk_rand_data(int N);

void	mmergesort(DTYPE A[], int N, DTYPE tmp[]);
void	merge(DTYPE A[], int N, DTYPE C[]);

int		main(int argc, char *argv[])
{
	(void) argc;
	DTYPE *arr, *tmp;
	double	tstart;
	int		N;//, i;
	N = atoi(argv[1]);
	srand(clock());
	arr = mk_rand_data( N );
	tmp = (DTYPE *)malloc(sizeof(DTYPE) * N);
	printf("\n sort .... \n");
	tstart = clock();
	mmergesort(arr, N, tmp);
	printf("mergesort: %f\n", toc(tstart));
#if 0
	for (i = 0; i < N, i++)
		printf("%f \n", arr[i]);
#endif
	return (0);
}

double	toc (double tstart)
{
	return (clock() - tstart) / CLOCKS_PER_SEC;
}

DTYPE *mk_rand_data(int N)
{
	DTYPE *arr = (DTYPE *)malloc(sizeof(DTYPE) * N);
	for (int i = 0; i < N; i++)
		arr[i] = rand() / (DTYPE) RAND_MAX;
	return (arr);
}

void	mmergesort(DTYPE A[], int N, DTYPE tmp[])
{
	int		mid = N / 2;

	if (N > 1)
	{
		mmergesort(A, mid, tmp);
		mmergesort(A + mid, N - mid, tmp + mid);
		merge(A, N, tmp);
	}
}

void	merge(DTYPE A[], int N, DTYPE C[])
{
	int		i, j, k, mid = N / 2;

	i = 0; j = mid; k = 0;
	while ((i < mid) && (j < N))
		C[k++] = (A[i] < A[j]) ? A[i++] : A[j++];
	while (i < mid)
		C[k++] = A[i++];
	while (j < N)
		C[k++] = A[j++];
	for (k = 0; k < N; k++)
		A[k] = C[k];
}
