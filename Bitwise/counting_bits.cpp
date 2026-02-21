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

    ll n;
    cin >> n;
    int ans = 0;
    for(ll i=1;i<=n;i++){
        ans += __builtin_popcount(i);
    }
    cout << ans << endl;
    return 0;
}