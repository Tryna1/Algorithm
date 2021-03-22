#include<bits/stdc++.h>
using namespace std;
int T[15] = {0, 2, 4, 5, 6, 7, 9, 11, 12, 13, 15};
int main() {
    int index = 0, x = 5;
    for(int i = 1; i <= 10; i++) {
        if(T[i] == x) {
            index = i;
            break;
        }
    }
    printf("%d\n", index);
    system("pause");
    return 0;
}
