#include<bits/stdc++.h>
#define For(i, l, r) for(int i = l; i <= r; i++)

using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n, m;
        scanf("%d%d", &n, &m);
        long long ans = 0;
        long long mi = 1e9 + 7, mx = 0;
        For(i, 1, n){
            long long tmp;
            scanf("%lld", &tmp);
            ans += tmp;
            mi = min(mi, tmp);
            mx = max(mx, tmp);
        }
        if (n == 1){
            if (n + mi * 2 <= m) puts("YES");
            else puts("NO");
        }else{
            if (n + ans - mi + mx <= m) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}