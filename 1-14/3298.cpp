#include<bits/stdc++.h>
#define For(i, l, r) for(int i = l; i <= r; i++)
#define Down(i, r, l) for(int i = r; i >= l; i--)
using namespace std;

const int maxn = 1e5 + 7;
char st[maxn];
int sta[maxn];
int ref(int x){
    switch(x){
        case 2:
            return 1;
        case 4:
            return 2;
        case 16:
            return 4;
        case 64:
            return 6;
        default:
            return 0; 
    }
}
pair<int, int> check(vector<int>& a){
    bool ok = 1;
    int n = a.size();
    int depth = 0;
    for(int i = 0; i < n; i++){
        sta[i] = a[i];
    }
    while(ok && n > 1){
        int tmp = 0;
        int tmpn = 0;
        depth++;
        for(int i = 0; i < n; i++){
            int tmpOld = tmp;
            tmp = tmp * 10 + a[i];
            if (!ref(tmp) && tmpOld){
                ok = 0;
                break;
            }else{
                if (ref(tmp)){
                    a[tmpn++] = ref(tmp);
                    tmp = 0;
                }
            }
        }
        n = tmpn;
    }
    if (!ok) return make_pair(0, 0);
    else return make_pair(depth, a[0]);
}

bool deduce(vector<int>& a, vector<int>& ans){
    int n = a.size();
    bool ok = 1;
    int tmp = 0;
    for(int i = 0; i < n; i++){
        if (a[i] == 0) continue;
        int tmpOld = tmp;
        tmp = tmp * 10 + a[i];
        if (!ref(tmp) && tmpOld){
                ok = 0;
                break;
            }else{
                if (ref(tmp)){
                    ans.push_back(ref(tmp));
                    tmp = 0;
                }
            }
    }
    if (tmp) ok = 0;
    return ok;
}

const long long MOD = 998244353;
long long f[5];
long long calc(int n, int key){
    long long ans;
    switch(key){
        case 2:
            f[0] = 1;
            f[1] = 0;
            f[2] = 0;
            f[3] = 1;
            break;
        case 1:
            f[0] = 0;
            f[1] = 0;
            f[2] = 1;
            f[3] = 0;
            break;
        case 4:
            f[0] = 0;
            f[1] = 1;
            f[2] = 0;
            f[3] = 1;
            break;    
        case 6:
            f[0] = 0;
            f[1] = 0;
            f[2] = 1;
            f[3] = 1;
            break;
    }
    for(int i = 4; i < n; i++){
        f[i % 4] = (f[(i - 1) % 4] + f[(i - 2) % 4] + f[(i - 3) % 4]  - f[(i - 4) % 4] + MOD) % MOD;
    }
    return f[(n - 1) % 4];
}
void dfs(int depth, vector<int> a, vector<pair<int, int>>& calcList, int n){
    if (depth > n) return;
    if (a.size() == 1){
        calcList.push_back(make_pair(depth, a[0]));
    }else{
        vector<int> head = {0}, tail = {0};
        int l = a.size() - 1;
        if (a[0] == 6){
            head.push_back(1);
        }
        if (a[0] == 4){
            head.push_back(6);
        }
        if (a[l] == 1){
            tail.push_back(6);
        }
        if (a[l] == 6){
            tail.push_back(4);
        }
        for(int i = 0; i < head.size(); i++){
            for(int j = 0; j < tail.size(); j++){
                vector<int> tmp(a);
                tmp.insert(tmp.begin(), head[i]);
                tmp.insert(tmp.end(), tail[j]);
                vector<int> tmpNext;
                if (deduce(tmp, tmpNext)){
                    dfs(depth + 1, tmpNext, calcList, n);
                }
            }
        }
    }
}
int main(){
    int n;
    scanf("%d", &n);
    scanf("%s", st);
    vector<pair<int, int>> calcList;
    int l = strlen(st);
    vector<int> a;
        For(i, 0, l - 1){
            a.push_back(st[i] - '0');
        }
    dfs(0, a, calcList, 10);
    long long ans = 0;
    for(int i = 0; i < calcList.size(); i++){
        ans = (ans + calc(n - calcList[i].first, calcList[i].second)) % MOD;
    }
    printf("%lld\n", (ans + MOD) % MOD);
    return 0;
}