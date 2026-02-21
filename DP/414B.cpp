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

    int n, k;
    cin >> n >> k;

    vector<int> factors[n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j*j<=i;j++){
            if(i%j == 0){
                factors[i].push_back(j);
                if(i / j != j){
                    factors[i].push_back(i/j);
                }
            }
        }
    }

    int dp[k+1][n+1]; 

    for(int i=1;i<=n;i++){
        dp[1][i] = 1;
    }

    for(int i=2;i<=k;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = 0;
            for(auto x: factors[j]){
                dp[i][j] = (dp[i][j] + dp[i-1][x]) % MOD;
            }
        }
    }
    int ans = 0;

    for(int i=1;i<=n;i++){
        ans = (ans + dp[k][i]) % MOD;
    }

    cout << ans << endl;
    return 0;
}


// Multiples approach instead of factors approach
/*
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

    int n, k;
    cin >> n >> k;

    int dp[k+1][n+1]; 
    memset(dp, 0, sizeof(dp));
    for(int i=1;i<=n;i++){
        dp[1][i] = 1;
    }

    for(int i=2;i<=k;i++){
        for(int j=1;j<=n;j++){
            for(int mul=j;mul<=n;mul+=j){
                dp[i][mul] = (dp[i][mul] + dp[i-1][j]) % MOD;
            }
        }
    }
    int ans = 0;

    for(int i=1;i<=n;i++){
        ans = (ans + dp[k][i]) % MOD;
    }

    cout << ans << endl;
    return 0;
}
*/