#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 10005;
int zx[N], hx[N];
int treeroot;
int pos;
int tot, len;
struct tree
{
	int l;
	int r;
	int v;
}node[N];
int ans = 99999999;
int sum;
int id;
void create(int hxr, int hxl, int zxl, int zxr, int & root)
{
	if(hxr < hxl || zxl > zxr)
		return;
	int w = hx[hxr];
	int p;
	for (int i = zxl; i <= zxr; i ++)
	{
		if(zx[i] == w)
		{
			p = i;
			break;
		}
	}
	root = ++ tot;
	node[root].v = w;
	node[root].l = 0;
	node[root].r = 0;
	create(hxr - (zxr - p + 1), hxl, zxl, p - 1, node[root].l);
	create(hxr - 1, hxl + (p - zxl), p + 1, zxr, node[root].r);
}
void front(int root)
{
	if(! root)
		return;
	printf("%d ", node[root].v);
	front(node[root].l);
	front(node[root].r);
}
void middle(int root)
{
	if(! root)
		return;
	front(node[root].l);
	printf("%d ", node[root].v);
	front(node[root].r);
}
void back(int root)
{
	if(! root)
		return;
	front(node[root].l);
	front(node[root].r);
	printf("%d ", node[root].v);
}
int main()
{
	scanf("%d", &len);
	for (int i = 1; i <= len; i ++)
		scanf("%d", &zx[i]);
	for (int j = 1; j <= len; j ++)
		scanf("%d", &hx[j]);
	create(len, 1, 1, len, treeroot);
	front(treeroot);
	printf("\n");
	return 0;
}
