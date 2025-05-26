#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, q;
    cin >> n >> q;
    map<int, multiset<int>> box;
    map<int, set<int>> card; 
    rep(index, q){
        int n;
        cin >> n;
        n--;
        if(n == 0){
            int i, j;
            cin >> i >> j;
            box[j].insert(i);
            card[i].insert(j);
        }else if(n == 1){
            int i;
            cin >> i;
            for(auto x : box[i]) cout << x << " ";
            cout << "\n";
        } else{
            int i;
            cin >> i;
            for(auto x : card[i]) cout << x << " ";
            cout << "\n";
        }
    }
}