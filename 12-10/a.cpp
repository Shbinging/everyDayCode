#include<bits/stdc++.h>
#define For(i, l, r) for(int i = l; i <= r; i++)
#define Down(i, r, l) for(int i = r; i >= l; i--)

using namespace std;

const int maxn = 20;
const int maxm = 300;
double f[1048580/4][100];
double p[maxn];
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    memset(f, 0, sizeof(f));
    For(i, 0, n - 1) scanf("%lf", &p[i]);
    double ans = 0;
    f[0][0] = 1.0;
    For(i, 1, (1 << n) - 1){
        int check = 0;
        For(j, 0, n - 1){ 
            check += ((1 << j) & i) > 0 ? 1 : 0;
        }
        int l = check;
        int r = check + (n - check) * k + k - 1;
        For(j, l, r){
            For(y, 0, n - 1){
                if (((1 << y) & i) > 0){
                    f[i][j] += f[i - (1 << y)][j - 1] * p[y];
                    if ((j <= check + (n - check) * k)){
                        f[i][j] += f[i][j - 1] * p[y];
                    }
                }
            }
            //assert(f[i][j] <= 1.0);
            if (j >= check + (n - check) * k){
                ans += f[i][j] * j;
                //printf("%d %d %f\n", i, j, f[i][j] * j);
            }
        }
    }

    printf("%f\n", ans);
    return 0;
}