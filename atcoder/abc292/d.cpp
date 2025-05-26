#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>());
    map<P, int> edge;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edge[P(u, v)]++;
        if (u != v) {
            graph[u].push_back(v);
            graph[v].push_back(u);
        } else {
            graph[u].push_back(v);
        }
    }
    bool flag = true;
    vector<bool> reach(n);
    queue<int> que;
    for (int i = 0; i < n; i++) {
        int g = 0, e = 0;
        if (!reach[i]) {
            g++;
            reach[i] = true;
            que.push(i);
            while (!que.empty()) {
                int u = que.front();
                que.pop();
                for (int& v : graph[u]) {
                    if (edge[P(u, v)] > 0) {
                        e++;
                        edge[P(u, v)]--;
                    }
                    if (edge[P(v, u)] > 0) {
                        e++;
                        edge[P(v, u)]--;
                    }
                    if (!reach[v]) {
                        g++;
                        reach[v] = true;
                        que.push(v);
                    }
                }
            }
        }
        if (g != e)
            flag = false;
    }
    if (flag)
        cout << "Yes\n";
    else
        cout << "No\n";
}