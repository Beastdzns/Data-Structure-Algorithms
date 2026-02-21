#include<bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)

const int IINF = 1e9;

vector<int> a, dp;

int solve(int sum) {
    if (sum < 0) return IINF;
    if (sum == 0) return 0;

    if (dp[sum] != -1) return dp[sum];

    int ans = IINF;
    for (int c : a) {
        ans = min(ans, 1 + solve(sum - c));
    }
    return dp[sum] = ans;
}

int main() {
    fastio();

    int n, x;
    cin >> n >> x;

    a.resize(n);
    for (auto &v : a) cin >> v;

    dp.assign(x + 1, -1);

    int coins = solve(x);
    cout << (coins >= IINF ? -1 : coins) << endl;
}
