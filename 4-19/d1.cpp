#include <bits/stdc++.h>

using namespace std;
const int max_n=500005, inf=10000000;
int t, n, a[max_n], dp[max_n], ord[max_n], fen[max_n];
long long pref[max_n];


// Fenwick tree with prefix maximum
int lsb(int a) {
    return (a & -a);
}
void add(int pos, int val) {
    while (pos<=n) {
        fen[pos]=max(fen[pos], val);
        pos+=lsb(pos);
    }
}
int ask(int pos) {
    int val=-inf;
    while (pos) {
        val=max(fen[pos], val);
        pos-=lsb(pos);
    }
    return val;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        vector<pair<long long, int> > v;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
            pref[i]=pref[i-1]+a[i];
            v.push_back({pref[i], -i});
        }
        sort(v.begin(), v.end());
        for (int i=0; i<n; i++) {
            ord[-v[i].second]=i+1;
        }
        // smaller prefix sum, smaller ord[i]
        // if j<i they have equal prefix sums, than ord[i]<ord[j], this way we cannot count [j+1, ... i] as a winning segment


        for (int i=1; i<=n; i++) {
            fen[i]=-inf;
        }

        for (int i=1; i<=n; i++) {
            dp[i]=(dp[i-1]+(a[i]<0 ? -1 : a[i]>0 ? 1 : 0));
            // The last segment is 1 long.

            dp[i]=max(dp[i], ask(ord[i])+i);
            if (pref[i]>0) dp[i]=i;
            // Segment [1, ... i] is winning, so dp[i]=i;

            add(ord[i], dp[i]-i);
        }
        cout << dp[n] << "\n";

        for (int i=0; i<=n; i++) {
            a[i]=0, dp[i]=0, ord[i]=0, fen[i]=0, pref[i]=0;
        }
    }
    return 0;
}