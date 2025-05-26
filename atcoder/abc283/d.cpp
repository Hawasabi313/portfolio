#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    vector<bool> b(26);
    vector<char> stack;
    rep(i, s.size()){
        if(s[i] == ')') {
            while (true){
                char c = stack.back();
                stack.pop_back();
                if(c == '(') break;
                b[c - 'a'] = false;
            }
        } else {
            stack.push_back(s[i]);
            if(s[i] != '('){
                if(b[s[i] - 'a']) {
                    cout << "No" << endl;
                    return 0;
                }
                b[s[i] - 'a'] = true;
            }
        }
    }
    cout << "Yes" << endl;
}