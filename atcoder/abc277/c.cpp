#include <iostream>
#include <map>
#include <queue>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, vector<int>> lads;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        lads[a].push_back(b);
        lads[b].push_back(a);
    }
    queue<int> que;
    set<int> reach;
    que.push(0);
    reach.insert(0);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int i = 0; i < lads[v].size(); i++) {
            if (!reach.count(lads[v][i])) {
                reach.insert(lads[v][i]);
                que.push(lads[v][i]);
            }
        }
    }
    cout << (*reach.rbegin() + 1) << endl;
}