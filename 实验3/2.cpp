#include<bits/stdc++.h>
using namespace std;
int T[15] = {0, 2, 4, 5, 6, 7, 9, 11, 12, 13, 15};
int main() {
    int x = 5;
    int index = lower_bound(T + 1, T + 11, x) - T;
    if(T[index] != x) index = 0;
    printf("%d\n", index);
    return 0;
}