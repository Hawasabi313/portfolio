#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<vector<ll>> dp(2, vector<ll>(n + 1));
    dp[0][n] = 1;
    dp[1][n] = x;
    for (int i = n - 1; i > 1; i--) {
        dp[0][i] = dp[0][i + 1] + dp[1][i + 1];
        dp[1][i] = x * dp[0][i + 1] + (x + y) * dp[1][i + 1];
    }
    if(n == 1) dp[1][1] = 0;
    else dp[1][1] = y * dp[1][2];
    cout << dp[1][1] << endl;
}