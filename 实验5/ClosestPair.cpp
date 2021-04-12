#include<bits/stdc++.h>
using namespace std;    
const double pi = acos((double)(-1));
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define eps 1e-8
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
int sgn(double x){
    if(fabs(x) < eps) return 0;
    else return x < 0?-1:1;
}
int dcmp(double x, double y){ 
    if(fabs(x - y) < eps) return 0;
    else return x < y?-1:1;
}
struct Point{
    double x,y;
    int id;
    Point(){}
    Point(double x,double y):x(x),y(y){}
    Point operator + (Point B){return Point(x + B.x,y + B.y);}
    Point operator - (Point B){return Point(x - B.x,y - B.y);}
    Point operator * (double k){return Point(x*k,y*k);}
    Point operator / (double k){return Point(x/k,y/k);}
    bool operator == (Point B){return sgn(x - B.x) == 0 && sgn(y - B.y) == 0;}
    bool operator < (const Point &b)const{           //凸包排序
        if(x == b.x) return y < b.y;
        return x < b.x;
    }
}P[maxn];
Point ch[maxn];

typedef Point Vector;
double Dist(Point A,Point B){
    return sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
}
double Cross(Vector A,Vector B){return A.x*B.y - A.y*B.x;}

int cmp(Point a,Point b){     //极角排序
    return Cross(a - P[0], b - P[0]) > 0;  
}

bool cmpy(Point A, Point B){
    return sgn(A.y - B.y) < 0;
}

Point tmp_P[maxn];
int pos[5];
double dis = inf;
void Closest_Pair(int left, int right, int flag) {       //最近点对距离  先对x排序，flag表示禁用的点
    if(left == right) return ;    //只剩1个点
    if(left + 1 == right){
        if(P[left].id != flag && P[right].id != flag){
            if(dis > Dist(P[left], P[right])){
                dis = Dist(P[left], P[right]);
                if(flag == -1){
                    pos[0] = P[left].id;
                    pos[1] = P[right].id;
                }
            }
        }
        return ;
    }
    int mid = (left + right) / 2;           //分治
    Closest_Pair(left, mid, flag);    // 求s1(集合)中的最近点对
    Closest_Pair(mid + 1, right, flag);   //求s2中的最近点对
    int k = 0;
    for(int i = left; i <= right; i++){        //在s1和s2中间附近找可能的最近点对
        if(abs(P[mid].x - P[i].x) <= dis && P[i].id != flag)      //按x坐标来找
            tmp_P[k++] = P[i];
    }
    sort(tmp_P, tmp_P + k, cmpy);     //对y排序 用于剪枝
    for(int i = 0; i < k; i++){
        for(int j = i + 1; j < k && tmp_P[j].y - tmp_P[i].y < dis; j++){
            if(dis > Dist(tmp_P[i], tmp_P[j])){
                if(flag == -1){
                    pos[0] = tmp_P[i].id;
                    pos[1] = tmp_P[j].id;
                }
                dis = Dist(tmp_P[i], tmp_P[j]);
            }
        }
    }
}

int n;
int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);cout.tie(0);
    // cin>>t;
    while(~scanf("%d", &n)){
        if(n == 0) break;
        for(int i = 0; i < n; i++) scanf("%lf %lf", &P[i].x, &P[i].y);
        sort(P, P + n);
        double sum = 0;
        dis = INF;
        Closest_Pair(0, n - 1, -1);
        sum =  dis / 2;
        printf("%.2f\n", sum);
    }
    return 0; 
}