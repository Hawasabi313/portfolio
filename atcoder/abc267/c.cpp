#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 100100101;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll cnt = 0, sub = 0;
    rep(i, m){
        cnt += (i+1) * a[i];
        sub += a[i];
    }

    ll res = cnt;
    rep(i, n-m){
        cnt = cnt - sub + m*a[i+m];
        sub = sub - a[i] + a[i+m];
        res = max(res, cnt);
    }
    cout << res << endl;
}