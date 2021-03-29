#include<bits/stdc++.h>
using namespace std;
void Merge(int a[],int b[], int start, int mid, int end){
    int left = start, right=mid+1, tmp = start;
    while(left<mid+1 && right<end+1){
        if(a[left] > a[right])
            b[tmp++] = a[right++];
        else
            b[tmp++] = a[left++];
    }
    while(left < mid+1)
        b[tmp++] = a[left++];
    while(right < end+1)
        b[tmp++] = a[right++];
    for(left=start; left<=end; left++)
        a[left] = b[left];
}
void MergeSort(int a[], int b[], int start, int end){
    int mid;
    if(start < end){
        mid = start + (end-start) / 2;
        MergeSort(a, b, start, mid);
        MergeSort(a, b, mid+1, end);
        Merge(a, b, start, mid, end);
    }
}
int main() {
    int a[20] = {0, 5, 2, 11, 4, 7, 8, 19, 2, 1, 4, 10, 13, 14, 9, 5, 3};
    int b[20];
    MergeSort(a, b, 1, 16);
    for(int i = 1; i <= 16; i++)
        printf("%d%c", a[i], " \n"[i == 16]);
    return 0;
}
