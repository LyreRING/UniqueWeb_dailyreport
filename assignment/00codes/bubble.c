#include<stdio.h>
int n;
int w[6000005];
int main()
{
	scanf("%d", &n);
	while(n --)
	{
		int t;
		scanf("%d", &t);
		int i, j;
		for (i = 1; i <= 10; i ++)
			scanf("%d", &w[i]);
		for (i = 1; i <= 9; i ++)
			for (j = 1; j <= 10 - i; j ++)
			if (t)
			{
				if (w[j] > w[j + 1])
				{
					int x = w[j];
					w[j] = w[j + 1];
					w[j + 1] = x;
				 } 
			}
			else
			{
				if (w[j] < w[j + 1])
				{
					int x = w[j];
					w[j] = w[j + 1];
					w[j + 1] = x;
				 } 
			}
		if (t)
			printf("Ascending order:");
		else
			printf("Descending order:");
		for (i = 1; i <= 10; i ++)
			printf(" %d", w[i]);
		printf(" \n");
	}
	return 0;
}
