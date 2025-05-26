#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<char, int>;

vector<P> runLength(string str){
    vector<P> vec;
    int cnt = 1;
    rep(i, str.size()){
        if(str[i - 1] != str[i]){
            vec.push_back(P(str[i], cnt));
            cnt = 0;
        }
        cnt++;
    }
    vec.push_back(P(str.back(), cnt));
    return vec;
}

int main()
{
    string s, t;
    cin >> s >> t;
    vector<P> sl, tl;
    sl = runLength(s);
    tl = runLength(t);
    if(sl.size() != tl.size()){
        cout << "No" << endl;
        return 0;
    }
    rep(i, sl.size()){
        if(sl[i].first != tl[i].first){
            cout << "No" << endl;
            return 0;
        }
        if(sl[i].second > tl[i].second){
            cout << "No" << endl;
            return 0;
        }
        if(sl[i].second == 1 && tl[i].second > 1){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}