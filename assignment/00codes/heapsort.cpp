#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int N = 1e6 + 5;
int n;
int node[N];
int cnt;
inline void rev(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
inline void insert(int t)
{
	while(t != 1)
	{
		if (node[t] < node[t / 2])
			rev(&node[t], &node[t / 2]);
		else 
			break;
		t = t / 2;
	}
}
inline void heapsort(int cnt)
{
	if (! cnt)
		return;
	printf("%d ", node[1]);
	node[1] = node[cnt];
	cnt --;
	int t = 1;
	while(t * 2 <= cnt)
	{
		int minn = node[t * 2];
		int pos = t * 2;
		if (t * 2 + 1 <= cnt)
		{
			if (node[t * 2 + 1] < minn)
			{
				minn = node[t * 2 + 1]; 
				pos = t * 2 + 1;
			}
		}
		if (node[t] > minn)
		{
			rev(&node[t], &node[pos]);
			t = pos;
		}
		else
			break;
	}
	heapsort(cnt);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", &node[i]);
		insert(i);
	}
	cnt = n;
	heapsort(cnt);
	printf("\n");
	return 0;
 } 
