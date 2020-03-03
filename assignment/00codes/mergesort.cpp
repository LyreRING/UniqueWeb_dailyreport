#include<cstdio>
#include<cstdlib>
using namespace std;
const int N = 1e6+5;
int w[N];
int n;
inline void merge(int a[], int l, int r, int m)
{
	int c[r - l + 5];
	for (int k = l; k <= r; k ++)
		c[k - l + 1] = a[k];
	int i = l - l + 1, j = m - l + 1;
	int pos = l;
	while(i < m - l + 1 && j <= r - l + 1)
	{
		while (c[i] <= c[j] && i < m - l + 1)
		{
			a[pos ++] = c[i];
			i ++;
		}
		while (c[j] <= c[i] && j <= r - l + 1)
		{
			a[pos ++] = c[j];
			j ++;
		}
	}
	while (i < m - l + 1)
	{
		a[pos ++] = c[i];
		i ++;
	}
	while (j <= r - l + 1)
	{
		a[pos ++] = c[j];
		j ++;
	}
}
inline void mergesort(int a[], int l, int r)
{
	int mid = (l + r + 1) / 2;
	if (l < mid - 1)
		mergesort(a, l, mid - 1);
	if (mid < r)
		mergesort(a, mid, r);
	merge(a, l, r, mid);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", &w[i]);
	mergesort(w, 1, n);
	for (int i = 1; i <= n; i ++)
		printf("%d ", w[i]);
	return 0;
}
