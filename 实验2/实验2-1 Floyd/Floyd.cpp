#include<bits/stdc++.h>
#define maxn 205 
#define inf 0x3f3f3f3f
using namespace std;
int n, m, e[maxn][maxn];
void floyd(){
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				e[i][j] = min(e[i][j], e[i][k] + e[k][j]);    
			}
		}
	}
}
int main(void){
     while(cin>>n>>m){
     	for(int i = 1; i <= n; i++){
     		for(int j = 1; j <= n; j++){
     			e[i][j] = inf;
				if(i == j) e[i][j] = 0;
			}
		}
		 for(int i = 1, u, v, w; i <= m; i++){
		 	scanf("%d%d%d", &u, &v, &w);
		 	w = min(e[u][v], w);
		 	e[u][v] = w;
		}
		floyd();
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(e[i][j] == inf) printf("inf ");
                else printf("%d ", e[i][j]);
            }
			puts("");
        }
	 }
}