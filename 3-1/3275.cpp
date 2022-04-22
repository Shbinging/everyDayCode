#include<bits/stdc++.h>

using namespace std;

int main(){
    int T, n;
    cin >> T >> n;
    getchar();
    while(T--){
        string st;
        for(int i = 1; i <= n; i++){
            getline(cin, st);
            cout << st <<endl;
        }
    }
    return 0;
}