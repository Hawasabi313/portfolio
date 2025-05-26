#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 100100101;

int main()
{
    ll d;
    cin >> d;
    ll res = 1000000000000000000ll;
    rep(x, sqrt(d)+1){
        ll y = round(sqrt(d-x*x));
        res = min(res, (ll)abs(x*x + y*y - d));
    }
    cout << res << endl;
}