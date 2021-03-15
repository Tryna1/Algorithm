#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
const int maxn = 110;
int n, m, G[maxn][maxn], vis[maxn], d[maxn];
void Prim(int n, int m) {
	memset(vis, 0, sizeof(vis));
	int sum = 0;
	int index = 1;
	d[index] = 0;
	for(int i = 1; i <= n; i++)
		d[i] = G[index][i];
	vis[index] = 1;
	for(int i = 1; i < n; i++) {
		int minn = inf;
		for(int j = 1; j <= n; j++) {
			if(!vis[j] && d[j] < minn) {
				minn = d[j];
				index = j;
			}
		}
		vis[index] = 1;
		for(int j = 1; j <= n; j++) {
			if(!vis[j] && d[j] > G[index][j]) {
				d[j] = G[index][j];
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		if(d[i] == inf) {
			puts("?");
			return ;
		} 
		else sum += d[i];
	}
	printf("%d\n", sum);
}
int main() {
	while(~scanf("%d %d", &n, &m)) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(j == i) G[i][j] = 0;
				else G[i][j] = inf;
			}
		}
		for(int i = 1, u, v, w; i <= m; i++) {
			scanf("%d %d %d", &u, &v, &w);
			G[u][v] = G[v][u] = min(G[u][v], w);
		}
		Prim(n, m);
	}
	// system("pause");
	return 0;
}