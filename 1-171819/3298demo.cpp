#include <iostream>

#include <vector>

#include <string>

#include <map>

#include <set>

#include <queue>

#include <algorithm>

#include <cstdio>

#include <cstring>

#define rep(i, start, end) for (int i = start; i <= end; i++)

using namespace std;

typedef long long LL;

typedef pair<LL, LL> pa;

const int mod = 998244353;

int x;

string sub;

const int N = 14;

int w[N][N]; //转移矩阵

int id[100];

vector<int> v{1, 2, 4, 6, 16, 26, 41, 42, 44, 46, 61, 62, 64, 66};

vector<vector<int>> vv{

                       {2},
                       {4},
                       {1, 6, 16},
                       {6, 4, 64},
                       {26},
                       {46},
                       {62},
                       {64},
                       {61},
                       {66},
                       {42},
                       {44},
                       {41},
                       {46}

};

void init()

{
    

        memset(id, -1, sizeof(id));

    for (int i = 0; i < N; i++)

        id[v[i]] = i;

    //求出来转移矩阵

    for (int i = 0; i < N; i++)
    {
        

            for (auto t : vv[i])

                w[i][id[t]]++;
    }
}

void multi(int c[][N], int a[][N], int b[][N])

{
    

        //求c=a*b

        int tmp[N][N];

    memset(tmp, 0, sizeof(tmp));

    for (int i = 0; i < N; i++)

        for (int j = 0; j < N; j++)

            for (int k = 0; k < N; k++)

                tmp[i][j] = (tmp[i][j] + (LL)a[i][k] * b[k][j]) % mod;

    memcpy(c, tmp, sizeof(tmp));
}

int qpow(int x, int id)

{
    

        if (id == -1) return 0; //代表出现不可能的数

    int ans[N][N];

    int tr[N][N]; //转移矩阵，因为可能不止一次使用w,所有不可以直接改变w的值

    memset(ans, 0, sizeof(ans));

    for (int i = 0; i < N; i++)
        ans[i][i] = 1; //单位矩阵

    memcpy(tr, w, sizeof(w));

    while (x)
    {
        

            if (x & 1) multi(ans, ans, tr);

        multi(tr, tr, tr);

        x >>= 1;
    }

    return ans[0][id];
}

string get(string str)

{
    

        string ans;

    int n = str.size();

    for (int i = 0; i < n; i++)
    {
        

            //遍历str的元素

            if (str[i] == '1')
        {
            

                if (i + 1 == n || str[i + 1] == '6') ans += '4',
                i++; //16同时出现。代表上一轮是4

            else return "";
        }

        else if (str[i] == '2') ans += '1';

        else if (str[i] == '4') ans += '2';

        else
        {
            

                if (i + 1 == n || str[i + 1] == '4') ans += '6',
                i++;

            else return "";
        }
    }

    return ans;
}

LL dfs(int x, string &sub)

{
    

        if (sub.size() <= 2) return qpow(x, id[stoi(sub)]); //如果长度小于等于2

    LL res = 0;

    for (string s : {"", "1", "6"})
    { //可能是完整的，也可能前面少个1 6

        string tmp = get(s + sub);

        if (tmp.size())
            res = (res + dfs(x - 1, tmp)) % mod;
    }

    return res;
}

int main()

{
    

        //freopen("in.txt","r",stdin);

        //freopen("out.txt","w",stdout);

        std::ios::sync_with_stdio(false);

    init();

    cin >> x >> sub;

    cout << dfs(x, sub) << endl;
}
