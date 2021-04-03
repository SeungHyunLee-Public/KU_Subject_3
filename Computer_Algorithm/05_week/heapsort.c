#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double toc(double tstart);
#define DTYPE float
#define SWAP(aa, bb) { DTYPE tmp; tmp = aa; aa = bb; bb = tmp;}
DTYPE *mk_rand_data(int N);
void	hheapsort(DTYPE arr[], int N);
void	downheap(DTYPE data[], int cur, int end);

int		main(int argc, char *argv[])
{
	(void) argc;
	DTYPE *arr;
	double	tstart;
	int		N; //i
	N = atoi(argv[1]);
	srand(clock());
	arr = mk_rand_data(N);
	printf("\n sort....\n");
	tstart = clock();
	hheapsort(arr, N);
	printf("heapsort: %f\n", toc(tstart));
#if 0
	for (i = 0; i < N; i++)
		printf("%f \n", arr[i]);
#endif
	return (0);
}

double toc (double tstart)
{
	return (clock() - tstart) / CLOCKS_PER_SEC;
}


DTYPE *mk_rand_data(int N)
{
	DTYPE *arr = (DTYPE *)malloc(sizeof(DTYPE) * N);
	for (int i = 0; i < N; i++)
		arr[i] = rand() / (DTYPE) RAND_MAX;
	return arr;
}

void	hheapsort(DTYPE data[], int heap_size)
{
	int		k, i;

	for (i = (heap_size - 1) / 2; i >= 0; i--)
		downheap(data, i, heap_size);
	for (k = heap_size - 1; k > 0; k--)
	{
		SWAP (data[0], data[k]);
		downheap(data, 0, k);
	}
}

void	downheap(DTYPE data[], int cur, int end)
{
	int		left, right, p;
	left = cur * 2 + 1;
	right = cur * 2 + 2;
	if (left >= end)
		return;
	p = left;
	if (right < end)
	{
		if (data[p] < data[right])
			p = right;
	}
	if (data[cur] < data[p])
	{
		SWAP(data[cur], data[p]);
		downheap(data, p, end);
	}
	else
		return;
}

void	make_heap(DTYPE data[], int n)
{
	int		i;

	for (i = (n - 1) / 2; i >= 0; i--)
		downheap(data, i, n);
}
