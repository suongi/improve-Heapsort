#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}

void max_heapify(int arr[], int start, int end)
{
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end)
	{
		if (son + 1 <= end && arr[son] < arr[son + 1])
			son++;
		if (arr[dad] > arr[son])
			return;
		else
		{
			swap(&arr[dad], &arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

void heap_sort(int arr[], int len)
{
	int i;
	for (i = len / 2 - 1; i >= 0; i--)
		max_heapify(arr, i, len - 1);
	for (i = len - 1; i > 0; i--)
	{
		swap(&arr[0], &arr[i]);
		max_heapify(arr, 0, i - 1);
	}
}
int main(void)
{
	int arr[] = { 61, 23, 65, 72, 88, 16, 55, 48, 9, 98, 22, 90, 28, 40, 11, 6, 35, 51, 87 };
	int len = (int) sizeof(arr) / sizeof(int);
	heap_sort(arr, len);
	int i;
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
