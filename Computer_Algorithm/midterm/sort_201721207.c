#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double toc(double tstart);
#define SWAP(aa, bb) {DTYPE tmp; tmp=aa; aa=bb; bb=tmp;}

typedef struct DATA {
   double x;
   double y;
} DTYPE;

DTYPE*	mk_rand_data(int N);
void	quicksort_201721207(DTYPE arr[], int N);
int		partition_201721207(DTYPE A[], int N);
void    insertionsort_201721207(DTYPE arr[], int N);
double	sum(DTYPE arr[]);

int      main(int argc, char* argv[])
{
   (void)argc;
   DTYPE* arr;
   double   tstart;
   int        N;
   N = atoi(argv[1]);
   srand(time(NULL));
   arr = mk_rand_data(N);
   printf("\n sort...\n");
   tstart = clock();
   quicksort_201721207(arr, N);
   printf("quicksort:%f\n", toc(tstart));
//#if 1
//   for (i = 0; i < N; i++)
//      printf("%f + %f  = %f\n", arr[i].x, arr[i].y, arr[i].x + arr[i]. y);
//#endif
//   return 0;
}

double   toc(double tstart)
{
   return (clock() - tstart) / CLOCKS_PER_SEC;
}

DTYPE* mk_rand_data(int N)
{
   DTYPE* arr = (DTYPE*)malloc(sizeof(DTYPE) * N);
   for (int i = 0; i < N; i++)
   {
		arr[i].x = rand() / (double)RAND_MAX;
		arr[i].y = rand() / (double)RAND_MAX;
   }
   return (arr);
}

void   quicksort_201721207(DTYPE A[], int N)
{
   int      piv;
   if (N > 25)
	{
		
      piv = partition_201721207(A, N);   //left <=..<right
      quicksort_201721207(A, piv);      //left <= .. < piv
      quicksort_201721207(A + piv + 1, N - piv - 1);   //piv + 1 <= ... < right
   }
   else
      insertionsort_201721207(A, N);
}

int      partition_201721207(DTYPE A[], int N)
{
   int      p = N / 2;
   int      i = 0, j = N;
   DTYPE   pivot;
   SWAP(A[p], A[0]);
   pivot = A[0];   //left = pivot element
   while (1)
   {
      while (sum(&A[++i]) > (sum(&pivot)) && (i < N));   //skip
      while (sum(&A[--j]) < (sum(&pivot)) && (j > 0));
      if (i >= j)
         break;
      SWAP(A[i], A[j]);
   }
   SWAP(A[0], A[j]);
   return j;
}

double sum(DTYPE arr[])
{
	return arr->x + arr->y;
}

void   insertionsort_201721207(DTYPE arr[], int N)
{
   int i, j;
   DTYPE cur_el;
   for (i = 1; i < N; i++)
   {
      cur_el = arr[i]; //정렬 안된 부분의 가장 왼쪽원소
      j = i - 1;
      while ((j >= 0) && (sum(&arr[j]) < sum(&cur_el)))
      {
         arr[j + 1] = arr[j]; //현재원소가 j위치에 삽입가능
         j--;             //num_op++;
      }
      arr[j + 1] = cur_el;
   }
}
