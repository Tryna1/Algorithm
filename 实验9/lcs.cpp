#include<bits/stdc++.h>
using namespace std; 
const int maxn = 1e3 + 10;
char a[maxn],b[maxn];  
int dp[maxn][maxn];    
int main()  {   
    while(~scanf("%s%s",&a,&b))  {  
        int lena = strlen(a);  
        int lenb = strlen(b);  
        memset(dp, 0, sizeof(dp));  
        for(int i = 1; i <= lena; i++)  {  
            for(int j = 1; j <= lenb; j++)  {  
                if(a[i - 1] == b[j - 1])  
                    dp[i][j] = dp[i - 1][j - 1] + 1;  
                else  
                	dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  
            }  
        }  
        printf("%d\n",dp[lena][lenb]);  
    }  
    return 0;  
}