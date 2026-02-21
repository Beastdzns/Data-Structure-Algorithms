#include<bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)

using ll = long long;
using ull = unsigned long long;
using ld = long double;

const ll INF = 1e18;
const int IINF = 1e9;
const int MOD = 1e9 + 7;

int main() {
    fastio();

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for(auto &v: coins) cin >> v;

    vector<int> dp(x+1);
    dp[0] = 1;
    for(int i=1;i<=x;i++){
        for(int c: coins){
            if(i-c >= 0)
                dp[i] = (dp[i] + dp[i-c]) % MOD;
        }
    }
    cout << dp[x] << endl;  
    return 0;
}