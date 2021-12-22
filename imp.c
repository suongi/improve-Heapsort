#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *, int *);
void heapit(int *, int, int);
void heaptail(int *, int);

int main(void)
{
	int i;
	clock_t time_begin, time_end;
	int ar[] = { 61, 23, 65, 72, 88, 16, 55, 48, 9, 98, 22, 90, 28, 40, 11, 6, 35, 51, 87 };
	int l = (int) sizeof(ar) / sizeof(int);

	for (i = l / 2 - 1; i >= 0; i--)
		heapit(ar, i, l - 1);
	for (i = l - 1; i > 0; i--)
		heaptail(ar, i);
	for (i = 0; i < l; i++)
		printf("%d ", ar[i]);
	printf("\n");

	return 0;
}

void swap(int * x, int * y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

void heapit(int ar[], int s, int e)
{
	int succ;

	succ = s * 2 + 1;
	while (succ <= e)
	{
		if (succ < e && ar[succ] < ar[succ + 1])
			succ++;
		if (ar[s] >= ar[succ])
			return;
		else
		{
			swap(ar + s, ar + succ);
			s = succ;
			succ = s * 2 + 1;
		}
	}
}

void heaptail(int ar[], int e)
{
	int temp = ar[0];
	int now = 0;
	int next = now * 2 + 1;
	while (next <= e)
	{
		if (next < e && ar[next] < ar[next + 1])
			next++;
		ar[now] = ar[next];
		now = next;
		next = now * 2 + 1;
	}
	next = (now - 1) / 2;
	while (ar[next] < ar[e])
	{
		ar[now] = ar[next];
		now = next;
		next = (now -1) / 2;
	}
	ar[now] = ar[e];
	ar[e] = temp;
}
