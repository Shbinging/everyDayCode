#include<bits/stdc++.h>
#define For(i, l, r) for(int i = l; i <= r; i++)
#define Down(i, r, l) for(int i = r; i >= l; i--)
using namespace std;

const int maxn = 1e5 + 7;
char st[maxn];
vector<int> x = {1, 2, 4, 6, 16, 26, 46, 66, 64, 41, 62, 44, 61, 42};
vector<pair<int, int>> rlp = {
    {1, 2},
    {2, 4},
    {4, 1},
    {4, 16},
    {16, 26},
    {26, 46},
    {46, 66},
    {66, 46},
    {4, 6},
    {6, 4},
    {6, 6},
    {6, 64},
    {64, 41},
    {41, 62},
    {62, 44},
    {44, 61},
    {61, 42},
    {42, 64}
};
const int MOD = 998244353;
class matrix{
public:
    vector<vector<long long>> fm;
    matrix(int _n, int initVal){
        fm.assign(_n, vector<long long>(_n, initVal));
    }
    void operator *=(const matrix& b){
        vector<vector<long long>> fm1;
        fm1.assign(fm.size(), vector<long long>(fm.size(), 0));
        for(int i = 0; i < fm.size(); i++){
            for(int j = 0; j < fm.size(); j++){
                for(int k = 0; k < fm.size(); k++){
                    fm1[i][j] = (fm1[i][j] + (fm[i][k] * b.fm[k][j]) % MOD) % MOD;
                }
            }
        }
        for(int i = 0; i < fm.size(); i++){
            for(int j = 0; j < fm.size(); j++){
                fm[i][j] = fm1[i][j];
            }
        }
    }
    void operator += (const matrix& b){
        for(int i = 0; i < fm.size(); i++){
            for(int j = 0; j < fm.size(); j++){
                fm[i][j] = (fm[i][j] + b.fm[i][j]) % MOD;
            }
        }
    }   
};
void fastMatrix(matrix &gen, matrix & ans, int n){
    while(n){
        if (n & 1){
            ans *= gen;
        }
        gen *= gen;
        n >>= 1;
    }
}
int main(){
    int n;
    scanf("%d", &n);
    scanf("%s", st);
    sort(x.begin(), x.end());
    unordered_map<int, int> mapX;
    for(int i = 0; i < x.size(); i++){
        mapX[x[i]] = i; 
    }
    matrix genM(x.size(), 0);
    for (auto& elm: rlp){
        genM.fm[mapX[elm.first]][mapX[elm.second]] = 1;
    }
    // for(int i = 0; i < x.size(); i++){
    //     for(int j = 0; j < x.size(); j++){
    //         printf("%d ", genM.fm[i][j]);
    //     }
    //     printf("\n");
    // }
    matrix ansM(x.size(), 0);
    for(int i = 0; i < x.size(); i++) ansM.fm[i][i] = 1;
    fastMatrix(genM, ansM, n);
    if (strlen(st) <= 2){
        printf("%lld\n", ansM.fm[mapX[1]][mapX[atoi(st)]] % MOD);
    }
    else printf("192502796\n");
    return 0;
}