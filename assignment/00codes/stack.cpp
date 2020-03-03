#include<cstdio>
#include<cstdlib>
using namespace std;
int t, n;
const int N = 1e6+5;
int v[N];
int cnt;
struct stack
{
	void push(int x)
	{
		v[++ cnt] = x;
	}
	void pop()
	{
		cnt --;
	}	
	bool empty()
	{
		return cnt ? false : true;
	}
	int top()
	{
		return v[cnt];
	}
}s;
int main()
{
	scanf("%d", &n);
	while (n --)
	{
		scanf("%d", &t);
		if (t == 1)
		{
			int x;
			scanf("%d", &x);
			s.push(x);
		}
		if (t == 2)
			if (! s.empty())
				printf("%d\n", s.top());
		if (t == 3)
			if (! s.empty())
				s.pop();
	}
}
