#include<bits/stdc++.h>
using namespace std;
#define maxn 105
#define inf 0x3f3f3f3f
#define pb push_back
int n, m, d[maxn], vis[maxn];
struct node{
    int to, w;
    node(int _to = 0, int _w = 0) {
        to = _to, w = _w;
    }
};
vector<node>G[maxn];
void Dijkstra(int s, int e) {
    d[s] = 0;
    while(1) {
        int minn = inf, index = -1;
        for(int i = 1; i <= n; i++) {
            if(d[i] < minn && !vis[i]) {
                minn = d[i];
                index = i;
            }
        }
        if(index == -1) break;
        vis[index] = 1;
        for(auto i : G[index]) {
            int v = i.to, w = i.w;
            d[v] = min(d[v], d[index] + w);
        }
    }
}
int main(){
    scanf("%d %d", &n, &m);
    memset(d, inf, sizeof(d));
    for(int i = 1, u, v, w; i <= m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        G[u].pb(node(v, w));
    }
    Dijkstra(1, n);
    printf("%d\n", d[n]);
    system("pause");
	return 0;
}