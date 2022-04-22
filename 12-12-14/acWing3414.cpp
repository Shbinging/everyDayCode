#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e3 + 7;
const int maxm = 1e5 + 7;
int a[maxn];
long long f[maxn];

const long long Mod = 1000000000+7;
struct hashNode{
    int his;
    hashNode(){
        his = -1;
    }
    bool find(int cur){
        if (cur != his) return 0;
        else return 1; 
    }
    void set(int cur){
        his = cur;
    }
};

hashNode useDiv[maxm];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    vector<vector<int>> divList;
    divList.resize(a[n] + 1);
    for(int i = 1; i <= a[n]; i++){
        for(int j = 2 * i; j <= a[n]; j += i){
            divList[j].push_back(i);
        }
    }
    f[0] = 1;
    for(int i = 2; i <= n ; i++){
        for(int j = i - 1; j >= 1; j--){
            int interval = a[i] - a[j];
            long long s = 0;
            for(auto &x :  divList[interval]){
                if (!useDiv[x].find(i)){
                    s++;
                    useDiv[x].set(i);
                }
            }
            f[i - 1] = (f[i - 1] % Mod + ((f[j - 1] * s) % Mod)) % Mod;
            useDiv[interval].set(i);
        }
    }
    printf("%lld\n", f[n - 1]);
    return 0;
}