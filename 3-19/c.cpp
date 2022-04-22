#include<bits/stdc++.h>
#define For(i, l, r) for(int i = l; i <= r; i++)
using namespace std;
#define FILE 1
#define FOLD 0
struct node{
    int type;
    long long fdSize, tSize;
    int fa;
};
struct edge{
    int p, next;
    edge(){
        next = 0;
    }
};
const int maxm = 3e6 + 7;
edge e[maxm];
const int maxn= 1e6 + 7;
int cnt = 0;
int head[maxn];
int treeList[maxn];
void addEdge(int u, int v){
    e[++cnt].next = head[u];
    e[cnt].p = v;
    head[u] = cnt;
}
int main(){
    int n;
    cin >> n;
    For(i, 1, n){
        char ch;
        cin >> ch;
        switch(ch){
            case 'Q':

            case 'R':
            
            case 'C':

        }
    }
    return 0;
}