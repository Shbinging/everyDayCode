#include<bits/stdc++.h>
#define For(i, l, r) for(int i = l; i <= r; i++)
#define Down(i, r, l) for(int i = r; i >= l; i--)
using namespace std;

const int maxn = 1e5 + 7;
bool f[maxn];
int mxList[maxn];
struct node{
    int a, b, index;
    int index1;
};
node c[maxn];
int n;
bool cmp(node a1, node a2){
    return a1.a < a2.a;
}

void solve(int l, int mi){
    int p = 0;
    Down(i, l, 1){
        if (c[i].b >= mi){
            p = i;
        }
    }
    if (p == 0) return;
    For(i, p, l){
        f[c[i].index] |= 1;
        mi = min(mi, c[i].b);
    }
    if (p - 1 == 0) return;
    solve(p - 1, mi);
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        int mx1 = 0, mx2 = 0;
        For(i, 1, n){
            f[i] = 0;
            int tmp;
            scanf("%d", &tmp);
            mx1 = max(mx1, tmp);
            c[i].a = tmp;
            c[i].index = i;
        }
        For(i, 1, n){
            int tmp;
            scanf("%d", &tmp);
            mx2 = max(mx2, tmp);
            c[i].b = tmp;
        }
        solve(n, mx1);
        For(i, 1, n){
            swap(c[i].a, c[i].b);
        }
        solve(n, mx2);
        For(i, 1, n){
            if (f[i]) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}