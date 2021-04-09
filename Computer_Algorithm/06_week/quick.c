#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double toc(double tstart);
#define DTYPE float
#define SWAP(aa, bb) {DTYPE tmp; tmp=aa; aa=bb; bb=tmp;}
DTYPE *mk_rand_data(int N);
void	quicksort(DTYPE arr[], int);
int		partition (DTYPE A[], int );
int     cmp(const void *a, const void *b);
void    insertionsort(DTYPE arr[], int N);

int		main(int argc, char *argv[])
{
	(void) argc;
	DTYPE *arr;
	double	tstart;
	int		N;
	N = atoi(argv[1]);
	srand(time(NULL));
	arr = mk_rand_data (N);
	printf("\n sort...\n");
	tstart = clock();
//	qsort(arr, N, sizeof(DTYPE), cmp);
	quicksort(arr, N);
	printf("quicksort:%f\n", toc(tstart));
/*#if 1
	for (i = 0; i < N; i++)
		printf("%f \n", arr[i]);	*/
/*#endif
	return 0;					*/
}

int		cmp(const void *a, const void *b)
{
	return *(DTYPE *)a < *(DTYPE *)b;
}
double	toc(double tstart)
{
	return (clock() - tstart) / CLOCKS_PER_SEC;
}

DTYPE *mk_rand_data(int N)
{
	DTYPE *arr = (DTYPE *) malloc(sizeof(DTYPE) * N);
	for (int i = 0; i < N;i++)
		arr[i] = rand() / (DTYPE) RAND_MAX;
	return arr;
}

void	quicksort(DTYPE A[], int N)
{
	int		piv;
	if (N > 25)
	{
		piv = partition(A, N);	//left <=..<right
		quicksort(A, piv);		//left <= .. < piv
		quicksort(A + piv + 1, N - piv - 1);	//piv + 1 <= ... < right
	}
	else
		insertionsort(A, N);
}

int		partition(DTYPE A[], int N)
{
	int		p = N / 2;
	int		i = 0, j = N;
	DTYPE	pivot;
	SWAP(A[p], A[0]);
	pivot = A[0];	//left = pivot element
	while (1)
	{
		while ((A[++i] < pivot) && (i < N));	//skip
		while ((A[--j] > pivot) && (j > 0));
		if (i >= j)
			break;
		SWAP(A[i], A[j]);
	}
	SWAP(A[0], A[j]);
	return j;
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

