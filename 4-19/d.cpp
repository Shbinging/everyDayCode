#include<bits/stdc++.h>
#define For(i, l, r) for(int i = l; i <= r; i++)
#define Down(i, r, l) for(int i = r; i >= l; i--)
using namespace std;

struct node{
    long long val;
    int pos;
};
const int maxn = 1e6 + 7;
node a[maxn];
bool cmp(node a, node b){
    if (a.val < b.val) return 1;
    else if (a.val > b.val) return 0;
    return a.pos < b.pos;
}
int ans = 0;
int f[maxn];
int prevPos[maxn];
long long b[maxn];
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        a[0].val = 0;
        a[0].pos = 0;
        For(i, 1, n){
            int tmp;
            scanf("%d", &tmp);
            b[i] = tmp;
            a[i].pos = i;
            a[i].val = tmp;
            a[i].val += a[i - 1].val;
        }
        sort(a, a + n + 1, cmp);
        For(i, 1, n) prevPos[i] = -1;
        int i;
        int miPos = n + 1;
        for(int i = 0; i <= n; i++){
            long long prevVal = a[i].val;
            int miPos1 = n + 1;
            while(i <= n && a[i].val == prevVal){
                if (miPos < a[i].pos){
                    prevPos[a[i].pos] = miPos;
                }
                miPos1 = min(miPos1, a[i].pos);
                i++;
            }
            i--;
            if (i > n) break;
            miPos = min(miPos, miPos1);
        }
        f[0] = 0;
        For(i, 1, n){
            int delta;
            if (b[i] > 0) delta = 1;
            else if (b[i] == 0) delta = 0;
            else delta = -1; 
            f[i] = f[i - 1] + delta;
            if (prevPos[i] != -1){
                f[i] = max(f[i], f[prevPos[i]] + i - prevPos[i]);
            }
        }
        printf("%d\n", f[n]);
    }
    return 0;
}