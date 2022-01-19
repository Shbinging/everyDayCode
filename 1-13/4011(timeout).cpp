#include<bits/stdc++.h>
#define For(i, l, r) for(int i = l; i <= r; i++)
#define Down(i, r, l) for(int i = r; i >= l; i--)
using namespace std;

template<class T>
struct node{
    int t;
    T w;
    node(){}
    node(int _t, T _w){
        t = _t;
        w = _w;
    }
};
struct edge{
    int v, D;
    double w;
    edge(){}
    edge(int _v, double _w, int _D){
        v = _v;
        w = _w;
        D = _D;
    }
};

template<class T>
bool operator < (node<T> a, node<T>  b){
    return a.t > b.t;
}


const int maxn = 2000;
class linkNode;
class genNode;
linkNode* nodeList;
genNode* genList;
double deltaT;

// template<class T>
// class priority_unique_queue{
// public:
//     priority_queue<node<T>> q;
//     set<node<T>> s;
//     void push(node<T> a){
//         if (s.insert(a).second){
//             q.push(a);
//         }
//     }
//     node<T> top(){
//         return q.top();
//     }
//     void pop(){
//         q.pop();
//     }
//     bool empty(){
//         return q.empty();
//     }
// };
// priority_unique_queue<int> calcQue;

class outPart{
public:
    int n;
    int outS;
    outPart(){
        outS = 0;
    }
    vector<edge> toEdge;
    void addEdge(int _v, double _w, int _D){
        toEdge.push_back(edge(_v, _w, _D));
        n = toEdge.size();
    }
};


class linkNode:public outPart{
public:
    linkNode():outPart(){}
    double u, v, a, b, c, d;
    priority_queue<node<double>> q;
    void init(double _u, double _v, double _a, double _b, double _c, double _d){
        u = _u; v = _v; a = _a; b = _b; c = _c; d = _d;
    }
    void addIntense(int t, double w){
        q.push(node<double>(t, w));
    }
    void run(int t){
        double I = 0;
        while(!q.empty()){
            if (q.top().t <= t){
                I += q.top().w;
                q.pop();
            }else break;
        }
        double vNew, uNew;
        vNew = v + deltaT * (0.04 * v * v + 5 * v + 140 - u) + I;
        uNew = u + deltaT * a * (b * v - u);
        v = vNew;
        u = uNew;
        if (v >= 30){
            v = c;
            u += d;
            update(t);
        }
    }
    void update(int t){
        int n = toEdge.size();
        outS++;
        for(int i = 0; i < n; i++){
            nodeList[toEdge[i].v].addIntense(t + toEdge[i].D, toEdge[i].w);
        }
    }
};

class genNode:public outPart{
public:
    genNode():outPart(){}
    int r;
    void init(int _R){
        r = _R;
    }
    void run(int t, int cur){
        if (r > cur) update(t);
    }
    void update(int t){
        int n = toEdge.size();
        for(int i = 0; i < n; i++){
            nodeList[toEdge[i].v].addIntense(t + toEdge[i].D, toEdge[i].w);
        }
        outS++;
    }
};
// struct genNode{
//     int id, r;
// };
// bool cmp(genNode a, genNode b){
//     return a.r < b.r;
// }
// vector<vector<edge>>genNodeEdge;
// genNode genList[maxn];
static unsigned long nex = 1;
const int inf = 0xffffff;
int myrand() {
    nex = nex * 1103515245 + 12345;
    return((unsigned)(nex/65536) % 32768);
}
int main(){
    int T, N, S, P;
    scanf("%d%d%d%d", &N, &S, &P, &T);
    scanf("%lf", &deltaT);
    nodeList = new linkNode[N + 1];
    int k = N;
    int i = 0;
    while(k){
        int Rn;
        double _u, _v, _a, _b, _c, _d;
        scanf("%d%lf%lf%lf%lf%lf%lf", &Rn, &_v, &_u, &_a, &_b, &_c, &_d);
        For(j, 1, Rn){
            nodeList[i++].init(_u, _v, _a, _b, _c, _d);           
        }
        k -= Rn;
    }
    genList = new genNode[P + 1];
    For(i, 0, P - 1){
        int _r;
        scanf("%d", &_r);
        genList[i].init(_r);
    }

    For(i, 1, S){
        int _s, _t, _D;
        double _w;
        scanf("%d%d%lf%d", &_s, &_t, &_w, &_D);
        if (_s < N){
            nodeList[_s].addEdge(_t, _w, _D);
        }else{
            genList[_s - N].addEdge(_t, _w, _D);
        }
    }
    
    For(i, 1, T){
        For(j, 0, P - 1){
            int r = myrand();
            genList[j].run(i, r);
        }
        For(j, 0, N - 1){
            nodeList[j].run(i);
        }
        // For(j, 0, N - 1){
        //     printf("%d %f %f\n", j, nodeList[j].u, nodeList[j].v);
        // }
    }
    double miAns = inf, mxAns = -inf;
    int miSum = inf, mxSum = 0;
    For(i, 0, N - 1){
        miAns = min(miAns, nodeList[i].v);
        mxAns = max(mxAns, nodeList[i].v);
    }
    For(i, 0, N - 1){
        miSum = min(miSum, nodeList[i].outS);
        mxSum = max(mxSum, nodeList[i].outS);
    }
    printf("%.3f %.3f\n", miAns, mxAns);
    printf("%d %d\n", miSum, mxSum);
    return 0;
}

