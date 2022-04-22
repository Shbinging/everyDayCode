#include<bits/stdc++.h>
#define For(i, l, r) for(int i = l; i <= r; i++)
#define Down(i, r, l) for(int i = r; i >= l; i--)
using namespace std;


const int maxn = 6e3;
long long a[maxn];
int main(){
    int n;
    scanf("%d", &n);
    For(i, 1, n){
        scanf("%lld", &a[i]);
    }
    long long ans = 0;
    For(i, 1, n){
        long long k = 0;
        long long base = 0;
        Down(j, i - 1, 1){
            base += 1;
            if (base % a[j] == 0){
                k += base / a[j];
            }else{
                k += base / a[j] + 1;
                base = (base / a[j] + 1) * a[j];
            }
        }
        base = 0;
        For(j, i + 1, n){
            base += 1;
            if (base % a[j] == 0){
                k += base / a[j];
            }else{
                k += base / a[j] + 1;
                base = (base / a[j] + 1) * a[j];
            }
        }
        if (ans == 0) ans = k; 
        else ans = min(ans, k);
    }
    printf("%lld\n", ans);
    return 0;
}