#include <bits/stdc++.h>
using namespace std;

void matrix_order(int *p, int n, int m[6][6], int s[6][6]){
    int q = 0;
    int j = 0;
    for (int i = 0; i < n; i++)
        m[i][i] = 0;
    for (int l = 2; l <= n; l++)
        for (int i = 0; i < n - l + 1; i++){
            j = i + l - 1;
            m[i][j] = 1000000;
            for (int k = i; k < j; k++){ //在i,j中遍历每一个分割的位置
                q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1]; //计算代价
                if (q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
}

void print_parens(int s[6][6], int i, int j){
    if (i == j)
        printf("A%d", i);
    else{
        printf("(");
        print_parens(s, i, s[i][j]);
        print_parens(s, s[i][j] + 1, j); //递归调用
        printf(")");
    }
}

int main(){
    int p[7] = {30, 35, 15, 5, 10, 20, 25};
    int m[6][6] = {0};
    int s[6][6] = {0};
    int n = 6;
    matrix_order(p, n, m, s);
    printf("最终加括号的形式为： ");
    print_parens(s, 0, 5);
    printf("\n");
}
