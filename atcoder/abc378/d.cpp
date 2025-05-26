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

int h, w, k;
vector<string> s;
vector<int> dx = {0, 1, 0, -1}, dy = {-1, 0, 1, 0};
set<P> st;
ll res = 0;

int dfs(int x, int y, int nk){
    if(nk == 0) {
        res++;
        return 0;
    }
    st.emplace(P(x, y));
    
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || w <= nx) continue;
        if(ny < 0 || h <= ny) continue;
        if(st.count(P(nx, ny))) continue;
        if(s[ny][nx] == '#') continue;

        dfs(nx, ny, nk-1);
    }
    st.erase(P(x, y));
    return 0;
}

int main()
{
    cin >> h >> w >> k;
    s.resize(h);
    rep(i, 0, h) cin >> s[i];
    rep(y, 0, h){
        rep(x, 0, w){
            if(s[y][x] == '#') continue;
            dfs(x, y, k);
        }
    }
    cout << res << endl;
}