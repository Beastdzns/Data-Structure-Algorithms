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
    vector<ll> a(n);
    for(auto &x: a) cin >> x;

    ll moves = 0;
    for(int i=1;i<n;i++){
        ll m = 0;
        if(a[i] - a[i-1] < 0){
            m += abs(a[i]-a[i-1]);
            a[i] += m;
        }
        moves += m;
    }
    cout << moves << endl;
    return 0;
}