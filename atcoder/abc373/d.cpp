#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define fore(i, a) for (auto& i : a)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int, ll>;
// const int INF = 100100101;
const int INF = INT_MAX / 2;
const ll INFL = 1LL << 60;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<P>> graph(n);
    rep(i, 0, m){
        ll u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        graph[u].push_back(P(v, w));
        graph[v].push_back(P(u, -w));
    }

    vector<ll> x(n, 0);
    vector<bool> reached(n, false);
    rep(i, 0, n){
        if(!reached[i]){
            reached[i] = true;
            queue<int> que;
            que.push(i);
            while(!que.empty()){
                int u = que.front();
                que.pop();
                for(auto& v : graph[u]){
                    if(!reached[v.first]){
                        reached[v.first] = true;
                        x[v.first] = x[u] + v.second;
                        que.push(v.first);
                    }
                }
            }
        }
    }
    rep(i, 0, n)
        cout << x[i] << " ";
}