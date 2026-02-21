#include<bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)

using ll = long long;
using ull = unsigned long long;
using ld = long double;

const ll INF = 1e18;
const int MOD = 1e9 + 7;

vector<int> coins;
vector<vector<ll>> dp;


int main() {
    fastio();

    int n, x;
    cin >> n >> x;
    coins.resize(n);
    for(auto &v: coins) cin >> v;

    dp.assign(n, vector<ll>(x + 1, 0));
    dp[]
    
    cout << ways << endl;
    return 0;
}