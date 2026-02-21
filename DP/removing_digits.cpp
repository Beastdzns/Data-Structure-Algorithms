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
    vector<int> dp(n+1, 1e9);
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        string num = to_string(i);
        for(char c: num){
            int digit = c - '0';
            if(digit != 0){
                dp[i] = min(dp[i], 1 + dp[i-digit]);
            }
        }
    }

    cout << dp[n] << endl;
    return 0;
}






// Recursion without memoization
/*
#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
    // Base case
    if (n == 0) return 0;

    int ans = 1e9;

    string num = to_string(n);
    for (char c : num) {
        int digit = c - '0';
        if (digit != 0) {
            ans = min(ans, 1 + solve(n - digit));
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
*/

// Recursion with memoization
/*
#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

int solve(int n) {
    // Base case
    if (n == 0) return 0;

    // If already computed
    if (dp[n] != -1) return dp[n];

    int ans = 1e9;

    string num = to_string(n);
    for (char c : num) {
        int digit = c - '0';
        if (digit != 0) {
            ans = min(ans, 1 + solve(n - digit));
        }
    }

    return dp[n] = ans;
}

int main() {
    int n;
    cin >> n;

    dp.resize(n + 1, -1);

    cout << solve(n) << endl;
    return 0;
}
*/