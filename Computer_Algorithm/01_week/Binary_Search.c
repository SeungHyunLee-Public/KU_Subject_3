//	1. 다음의 숫자들에 대해 35를 이진 탐색하는 코드를 실습해 보자.
//	[10, 25, 35, 45, 55, 60, 75, 80, 90, 95]

#include <stdio.h>

int		bsearch(int arr[], int key, int beg, int end);
int		main()
{
	int a[] = {10, 20, 25, 35, 45, 55, 60, 75, 80, 90, 95};
	int beg = 0, end, mid, key;
	//key = 55;

	end = sizeof(a) / sizeof(int);
	scanf("%d", &key);
	mid = bsearch(a, key, beg, end);
	if (mid == -1)
		printf("%d is not found\n", key);
	else
		printf("A[%d]=%d\n", mid, a[mid]);
}

int		bsearch(int arr[], int key, int beg, int end)
{
	int mid = (beg+end)/2;
	if (end - beg <= 1)
		return arr[mid] == key ? mid : -1;
	if (key < arr[mid])
		return bsearch(arr, key, beg, mid);
	else
		return bsearch(arr, key, mid, end);
}
