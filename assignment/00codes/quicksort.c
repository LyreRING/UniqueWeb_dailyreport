#include<stdio.h>
#include<string.h>
int n;
int w[505];
void swap(int *c, int i, int j)
{
	int t = *(c + i);
	*(c + i) = *(c + j);
	*(c + j) = t; 
}
int partition(int *c, int left, int right, int cmp)
{
	int i = left, j = right + 1;
	int mid = (left + right) / 2;
	swap(c, left, mid);
	while (1)
	{
		if(cmp < 0)
		{
			while(*(c + (++ i)) <= *(c + left));
			while(*(c + (-- j)) > *(c + left));
		}
		else
		{
			while(*(c + (++ i)) >= *(c + left));
			while(*(c + (-- j)) < *(c + left));
		}
		if (i >= j)
			break;
		swap(c, i, j);
	}
	swap(c, left, j);
	return j;
}
void quicksort(int *c, int left, int right, int cmp)
{
	int split;
	if (left < right)
	{
		split = partition(c, left, right, cmp);
		quicksort(c, left, split - 1, cmp);
		quicksort(c, split + 1, right, cmp);
	}
}
int main(int argc, char *argv[])
{	
	int d;
	if (argc > 1 && !strcmp(argv[1], "-d"))
		d = 1;
	else
		d = -1;
	int *p = w;
	scanf("%d", &n);
	int i;
	for (i = 1; i <= n; i ++)
		scanf("%d", p + i);
	quicksort(p, 1, n, d);
	for (i = 1; i <= n; i ++)
		printf("%d ", *(p + i));
	printf("\n");
	return 0;
}
