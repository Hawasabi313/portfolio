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
    string s;
    cin >> s;
    ll n = s.size();
    map<char, ll> mp;
    ll cnt = 0;
    rep(i, 0, n){
        cnt += mp[s[i]];
        mp[s[i]]++;
    }
    ll res = (n*(n-1)) / 2;
    if(cnt != 0) res -= (cnt - 1);
    cout << res << endl;
}