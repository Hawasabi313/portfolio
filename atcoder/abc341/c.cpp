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
    int h, w, n;
    cin >> h >> w >> n;
    string t; cin >> t;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];

    int res = 0;
    rep(i, 0, h) rep(j, 0, w){
        if(s[i][j] == '#') continue;
        int x = i, y = j;
        bool flag = false;
        rep(k, 0, n){
            int dx = 0, dy = 0;
            if(t[k] == 'U') dx = -1;
            if(t[k] == 'D') dx = 1;
            if(t[k] == 'L') dy = -1;
            if(t[k] == 'R') dy = 1;

            if(x+dx < 0 || h <= x+dx) {
                flag = true;
                break;
            }
            if(y+dy < 0 || w <= y+dy) {
                flag = true;
                break;
            }
            if(s[x+dx][y+dy] == '#') {
                flag = true;
                break;
            }
            x += dx; y += dy;
        }
        if(!flag) res++;
    }
    cout << res << endl;
}