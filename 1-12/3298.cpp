#include<bits/stdc++.h>
#define For(i, l, r) for(int i = l; i <= r; i++)
#define Down(i, r, l) for(int i = r; i >= l; i--)
using namespace std;

class pos{
public:
    int a[110];
};

double sqr(double a){
    return a * a;
}
int n;
double dis(pos&a ,pos& b){
    double ans = 0;
    For(i, 1, n){
        ans += sqr(a.a[i] - b.a[i]);
    }
    return sqrt(ans);
}
const int maxm = 2100;
pos star[maxm];
double S2O[maxm];
int main(){
    int m;
    scanf("%d%d", &n, &m);
    int R;
    scanf("%d", &R);
    pos O;
    For(i, 1, n) scanf("%d", &O.a[i]);
    For(i, 1, m){
        For(j, 1, n){
            scanf("%d", &star[i].a[j]);
        }
    }
    For(i, 1, m){
        S2O[i] = dis(O, star[i]);
    }
    For(u, 1, m){
        double sum = 0;
        For(v, 1, m){
            if (u == v) continue;
            double c = dis(star[u], star[v]);
            double a = S2O[u];
            double b = S2O[v];
            if (a < b) swap(a, b);
            double p = (a + b + c) / 2;
            double s = sqrt(p * (p - a) * (p - b) * (p - c));
            double d = 2 * s / c;
            if (d >= R || (c <= sqrt(sqr(a) - sqr(R)))){
                sum += c;
            }else{
                double degC = acos((sqr(a) + sqr(b) - sqr(c)) / (2 * a * b));
                double degA = acos(R / a);
                double degB = acos(R / b);
                double degAphi = degC - degA - degB;
                sum += R * degAphi + sqrt(sqr(a) - sqr(R)) + sqrt(sqr(b) - sqr(R));
            }
        }
        printf("%.14f\n", sum);
    }
    return 0;
}