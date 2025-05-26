#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 100100101;

int main()
{
    string s;
    cin >> s;
    string g = "atcoder";
    int len = s.size();
    map<char, int> mp;
    rep(i, len) mp[g[i]] = i + 1;
    int res = 0;
    rep(i, len){
        for(int j = i + 1; j < len; j++){
            if(mp[s[i]] > mp[s[j]]) {
                swap(s[i], s[j]);
                res++;
            }
        }
    }
    cout << res << endl;
}