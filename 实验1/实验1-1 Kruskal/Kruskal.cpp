#include<bits/stdc++.h>
// #include<cstdio>
// #include<vector>
// #include<map>
// #include<algorithm>
// #include<iostream>
// #include<cstring>
// #include<string>
// #include<cmath>
// #include<iomanip>
// #include<queue>
using namespace std;
#define inf 0x3f3f3f3f
#define ll long long
#define eps 1e-8
#define endl "\n"
const int maxn = 1e2 + 10;
const int mod = 998244353;
const double startT = 100;
const double pi = acos(-1.0);
int moven2[10][5] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1},{0, 0, -1}}; 
int moven1[10][5] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; 
int n, m, f[maxn];
struct Edge{
    int u, v, w;
    bool operator < (const Edge &r) const {
        return w < r.w;
    }
}E[maxn];
int find(int x) {
    return x == f[x]?x:f[x] = find(f[x]);
}
void Kruskal() {
    int num = 0;
    int result = 0;
    for(int i = 1; i <= n; i++)
        f[i] = i;
    sort(E + 1, E + 1 + m);
    for(int i = 1; i <= m; i++) {
        int f1 = find(E[i].u);
        int f2 = find(E[i].v);
        if(f1 != f2) {
            result += E[i].w;
            num++;
            f[f1] = f2;
        }
        if(num == n - 1)
            break;
    }
    if(num == n - 1)
        printf("%d\n", result);
    else
        puts("?");
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);cout.tie(0);
    while(~scanf("%d %d", &n, &m)) {
        if(n == 0)
            break;
        for(int i = 1; i <= m; i++) {
            scanf("%d %d %d", &E[i].u, &E[i].v, &E[i].w);
        }
        Kruskal();
    }
    system("pause");
	return 0;
}