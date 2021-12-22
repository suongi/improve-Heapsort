#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *, int *);
void heapit(int *, int, int);

int main(void)
{
	int i;
	int l = 1000000;
	int ar[l];
	clock_t time_begin, time_end;

	srand((unsigned int) time(0));
	for (i = 0; i < l; i++)
		ar[i] = rand();
	time_begin = clock();
	for (i = l / 2 - 1; i >= 0; i--)
		heapit(ar, i, l - 1);
	for (i = l - 1; i > 0; i--)
	{
		swap(ar, ar + i);
		heapit(ar, 0, i - 1);
	}
	time_end = clock();
	printf("use time: %f secs\n", (double)(time_end - time_begin) / CLOCKS_PER_SEC);
	for (i = 0; i < l; i++)
	{
		if (i % 50000 == 0)
		{
			printf("Press ENTER-key to continue: ");
			getchar();
		}
		printf("%d ", ar[i]);
	}
	putchar('\n');

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
