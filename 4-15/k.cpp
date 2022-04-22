#include<bits/stdc++.h>
#define For(i, l, r) for(int i = l; i <= r; i++)
#define Down(i, r, l) for(int i = r; i >= l; i--)
using namespace std;


const int maxn = 2e5 + 7;
vector<int> g[maxn];
int heavySon[maxn];
int isExsist[maxn];
int dfnList[2 * maxn];
int dfn;
int L[maxn], R[maxn];
int ans[maxn];
int currentS = 0;
int dfs1(int u, int fa){
    dfnList[++dfn] = u;
    L[u] = dfn;
    int mxSon = 0;
    int totalNode = 1;
    heavySon[u] = 0;
    for(auto v : g[u]){
        if (v == fa) continue;
        int s = dfs1(v, u);
        totalNode += s;
        if (s > mxSon){
            mxSon = s;
            heavySon[u] = v;
        }
    }
    R[u] = dfn;
    return totalNode;
}
int n;

void add(int u){
    isExsist[u] = 1;
    if (u == 1){
        if (!isExsist[u + 1]) currentS++;
    }else if (u == n){
        if (!isExsist[u - 1]) currentS++;
    }else{
        if (isExsist[u - 1] && isExsist[u + 1]) currentS--;
        else if ((!isExsist[u - 1]) && (!isExsist[u + 1])) currentS++;
    }
}

void del(int u){
    isExsist[u] = 0;
    if (u == 1){
        if (!isExsist[u + 1]) currentS--;
    }else if (u == n){
        if (!isExsist[u - 1]) currentS--;
    }else{
        if (isExsist[u - 1] && isExsist[u + 1]) currentS++;
        else if ((!isExsist[u - 1]) && (!isExsist[u + 1])) currentS--;
    }
}

void dfs2(int u, int fa, int isHeavy){
    for(auto v : g[u]){
        if (v == heavySon[u] || v == fa) continue;
        dfs2(v, u, 0);
    }
    if (heavySon[u]) dfs2(heavySon[u], u, 1);
    for(auto v: g[u]){
        if (v == heavySon[u] || v == fa) continue;
        For(i, L[v], R[v]){
            add(dfnList[i]);
        }
    }
    add(u);
    ans[u] = currentS;
    if (!isHeavy){
        For(i, L[u], R[u]){
            del(dfnList[i]);
        }
    }
}
int main(){
    int T;
    scanf("%d", &T);
    For(t, 1, T){
        scanf("%d", &n);
        For(i, 1, n){g[i].clear();}
        memset(isExsist, 0, sizeof(isExsist));
        For(i, 1, n - 1){
            int u, v;
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfn = 0;
        currentS = 0;
        dfs1(1, 0);
        dfs2(1, 0, 1);
        printf("Case #%d:", t);
        For(i, 1, n){
            printf(" %d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}