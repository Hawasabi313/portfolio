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
    int n = s.size();

    vector<vector<ll>> cs(26, vector<ll>(n+1, 0));
    rep(i, 0, 26){
        rep(j, 0, n){
            cs[i][j+1] = cs[i][j];
            if(i == s[j]-'A') cs[i][j+1]++; 
        }
    }

    ll res = 0;
    rep(j, 1, n){
        rep(ap, 0, 26){
            res += cs[ap][j-1]*(cs[ap][n]-cs[ap][j]);
        }
    }
    cout << res << endl;
}