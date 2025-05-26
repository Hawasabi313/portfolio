#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define fore(i, a) for (auto& i : a)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int, int>;
// const int INF = 100100101;
const int INF = INT_MAX / 2;
const ll INFL = 1LL << 60;

int main()
{
    int n; cin >> n;
    vector<int> q(n), a(n), b(n);
    rep(i, 0, n) cin >> q[i];
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    P anc = P(INF, INF), bnc = P(INF, INF);
    rep(i, 0, n) {
        if(a[i] != 0){
            int na = q[i] / a[i];
            if(na < anc.second) anc = P(i, na);
        }
        if(b[i] != 0){
            int nb = q[i] / b[i];
            if(nb < bnc.second) bnc = P(i, nb);
        }
    }

    int res = 0;
    int cnt = INF;
    rep(i, 0, bnc.second+1){
        vector<int> nq(n);
        rep(j, 0, n) nq[j] = q[j] - i*b[j];
        rep(j, 0, n) if(a[j] != 0) cnt = min(cnt, nq[j]/a[j]);
        res = max(res, cnt+i);
    }
    cout << res << endl;
}