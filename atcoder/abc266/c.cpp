#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 100100101;

int f(vector<int> v, vector<int> u, vector<int> p){
    int ax = v[0], ay = v[1];
    int bx = u[0], by = u[1];
    int x = p[0], y = p[1]; 
    return (ax-bx)*y + (by-ay)*x -ax*by+ay*bx;
}

int main()
{
    vector<int> a(2), b(2), c(2), d(2);
    cin >> a[0] >> a[1];
    cin >> b[0] >> b[1];
    cin >> c[0] >> c[1];
    cin >> d[0] >> d[1];
    if(f(a, c, b)*f(a, c, d) > 0){
        cout << "No" << endl;
        return 0;
    }
    if(f(b, d, a)*f(b, d, c) > 0){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
}