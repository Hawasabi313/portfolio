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
    vector<P> cards(n);
    map<int, int> mp;
    rep(i, 0, n){
        int a, c;
        cin >> a >> c;
        mp[c] = i;
        P p = P(c, a);
        cards[i] = p;
    }
    sort(all(cards));
    vector<P> ncards;
    ncards.push_back(cards[0]);
    rep(i, 1, n){
        P nc = ncards.back();
        if(nc.second < cards[i].second) ncards.push_back(cards[i]);
    }
    int l = ncards.size();
    vector<int> res(l);
    rep(i, 0, l) res[i] = mp[ncards[i].first];
    sort(all(res));
    cout << l << endl;
    rep(i, 0, l) cout << res[i] + 1 << endl;
}