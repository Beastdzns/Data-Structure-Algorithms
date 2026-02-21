#include<bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)

using ll = long long;
using ull = unsigned long long;
using ld = long double;

const ll INF = 1e18;
const int MOD = 1e9 + 7;

int main() {
    fastio();

    string s;
    cin >> s;

    int n = s.size();
    int cnt = 1, maxCnt = 1;
    for(int i=1;i<n;i++){
        if(s[i] == s[i-1]){
            cnt++;
        } else {
            cnt = 1;
        }
        maxCnt = max(maxCnt, cnt);
    }
    cout << maxCnt << endl;
    return 0;
}