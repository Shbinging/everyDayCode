#include<bits/stdc++.h>
#define For(i, l, r) for(int i = l; i <= r; i++)

using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n, m;
        scanf("%d%d", &n, &m);
        int mx = max(n, m), mi = min(n, m);
        if (mi ==1 && mx >=3){
            puts("-1");
            continue;
        }
        mx -= 1; mi -= 1;
        int delta = mx - mi;
        int ans = 0;
        if (delta % 2  == 1) ans = delta + delta - 1;
        else ans = 2 * delta;
        ans += mi * 2;
        printf("%d\n", ans);
    }
    return 0;
}