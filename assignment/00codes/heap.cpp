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
inline void update()
{
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
}
int main()
{
	scanf("%d", &n);
	while(n --)
	{
		int x;
		scanf("%d", &x);
		if (x == 1)
		{
			int t;
			scanf
			("%d", &t);
			node[++ cnt] = t;
			insert(cnt);
		 } 
		if (x == 2)
		 	printf("%d\n", node[1]);
		if (x == 3)
		{
			node[1] = node[cnt];
			cnt --;
			update();
		 } 
	}
	return 0;
 } 
