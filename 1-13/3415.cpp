#include<bits/stdc++.h>
#define For(i, l, r) for(int i = l; i <= r; i++)
#define Down(i, r, l) for(int i = r; i >= l; i--)

using namespace std;
const int maxn = 610;
int s[maxn][maxn];
int main(){
    int n, L, r, t;
    scanf("%d%d%d%d", &n, &L, &r, &t);
    For(i, 1, n){
        For(j, 1, n){
            int tmp;
            scanf("%d", &tmp);
            s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + tmp;
        }
    }
    int ans = 0;
    For(i, 1, n){
        For(j, 1, n){
            int lh = max(1, i - r);
            int rh = min(n, i + r);
            int ll = max(1, j - r);
            int rl = min(n, j + r);
            int tSum = s[rh][rl] - s[lh - 1][rl] - s[rh][ll -1] + s[lh -1][ll -1];
            int tNum = (rh - lh + 1) * (rl - ll + 1);
            if (1.0 * tSum / tNum <= t) ans++;
        }
    }
    // For(i, 1, n){
    //     For(j, 1, n){
    //         printf("%d ", s[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%d\n", ans);
    return 0;
}