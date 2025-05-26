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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    rep(i, 0, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        if(b == 0) b = n;
        graph[a].emplace_back(b);
    }

    vector<int> node(n+1, INF);
    node[0] = 0;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int u = que.front();
        que.pop();
        for(auto& v : graph[u]){
            if(node[v] == INF){
                node[v] = node[u] + 1;
                que.push(v);
            }
        }
    }
    ll res = node[n];
    if(res == INF) res = -1;
    cout << res << endl;
}