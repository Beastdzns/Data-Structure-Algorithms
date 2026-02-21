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

    int n;
    cin >> n;
    vector<ll> dp(n+1, 0);
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        for(int d=1;d<=6;d++){
            if(i-d >=0)
                dp[i] = (dp[i] + dp[i-d]) % MOD;
            else break;
        }
    }
    cout << dp[n] << endl;
    return 0;
}