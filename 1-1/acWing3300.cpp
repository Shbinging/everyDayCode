#include<bits/stdc++.h>
#define For(i, l, r) for(int i = l; i <= r; i++)
using namespace std;

const int maxn = 107;
const int maxk = 13;
int a[maxn][maxk];
int mxT[maxn][maxk];
int f[4096];
int cnt = 0;
struct node{
  int v, dis, next;
  node(){next = 0;}
  node(int _v, int _dis, int _next){
      v = _v;
      dis = _dis;
      next = _next;
  }
};
node e[maxn * 2];
int head[maxn];
void init(){
    memset(head, 0, sizeof(head));
}
void addEdge(int u, int v, int dis){
    e[++cnt] = node(v, dis, head[u]);
    head[u] = cnt;
}
void add(int u, int v, int dis){
    addEdge(u, v, dis);
    addEdge(v, u, dis);
}

void dfs(int level, int u, int fa, int& totalDis, int& maxDis){
    totalDis = 0;
    maxDis = 0;
    for(int i = head[u]; i; i = e[i].next){
        int v = e[i].v;
        if (v == fa) continue;
        int td, md;
        dfs(level, v, u, td, md);
        if (td || a[v][level]){
            totalDis += td + e[i].dis * 2;
            maxDis = max(maxDis, md + e[i].dis);
        }
    }
}
int n, m, k;
int canRun[maxn];
bool check(int mt){
    memset(canRun, 0, sizeof(canRun));
    For(i, 1, n){
        For(j, 1, k){
            canRun[i] *= 2;
            if (mxT[i][j] <= mt){
                canRun[i] += 1;
            }
        }
    }
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    For(i, 1, n){
        for(int j = (1 << k) - 1; j >= 0; j--){
            f[j | canRun[i]] = min(f[j | canRun[i]], f[j] + 1);
        }
    }
    return f[(1 << k) - 1] <= m;
}
int main(){
    
    scanf("%d%d%d", &n, &m, &k);
    For(i, 1, n){
        For(j, 1, k){
            scanf("%d", &a[i][j]);
        }
    }
    init();
    For(i, 1, n - 1){
        int u, v, dis;
        scanf("%d%d%d", &u, &v, &dis);
        add(u, v, dis);
    }
    int l = 0, r = 0;
    For(i, 1, n){
        For(j, 1, k){
            int maxDis, totalDis;
            dfs(j, i, -1, totalDis, maxDis);
            mxT[i][j] = totalDis - maxDis;
            //printf("%d %d %d\n", i, j, mxT[i][j]);
            r = max(r, mxT[i][j]);
        }
    }
    
    while(l + 1 < r){
        int mid = (l + r) / 2;
        if (check(mid)){
            r = mid;
        }else{
            l = mid;
        }
    }
    printf("%d\n", r);
    return 0;
}