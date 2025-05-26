#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 100100101;

int main()
{
    int n, m, h, k;
    string s;
    cin >> n >> m >> h >> k >> s;
    set<P> st;
    rep(i, m){
        int x, y;
        cin >> x >> y;
        st.emplace(x, y);
    }
    P pos = P(0, 0);
    rep(i, s.size()){
        h--;
        if(h < 0){
            cout << "No" << endl;
            return 0;
        }
        if(s[i] == 'R') pos.first++;
        if(s[i] == 'L') pos.first--;
        if(s[i] == 'U') pos.second++;
        if(s[i] == 'D') pos.second--;
        if(st.count(pos)){
            if(h < k) {
                st.erase(pos);
                h = k;
            }
        }
    }
    cout << "Yes" << endl;
}