#include<cstdio>
#include<cstdlib>
using namespace std;
const int N = 1e6 + 5;
int w[N];
int n;
int tmp;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", &w[i]);
	for (int i = 2; i <= n; i ++)
	{
		if (w[i] >= w[i - 1])
			continue;
		tmp = w[i];
		int j;
		for (j = i - 1; j; j --)
			if (w[j] > tmp)
				w[j + 1] = w[j];
			else
				break;
		j ++;
		w[j] = tmp;
	}
	for (int i = 1; i <= n; i ++)
		printf("%d ", w[i]);
	return 0;
}
