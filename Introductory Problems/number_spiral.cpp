#include<bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)

using ll = long long;
using ull = unsigned long long;
using ld = long double;

const ll INF = 1e18;
const int MOD = 1e9 + 7;

void solve(){
    ll y, x;
    cin >> y >> x;
    if(y <= x){
        if(x&1){
            cout << x*x - (y-1) << endl;
        } else {
            cout << (x-1)*(x-1) + y << endl;
        }
    } else {
        if(y & 1){
            cout << (y-1)*(y-1) + x << endl;
        } else {
            cout << y*y - (x-1) << endl;
        }
    } 
}

int main() {
    fastio();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

// y<=x -> 1. x is odd  -> x*x - (y-1)
    //         2. x is even -> (x-1)*(x-1) + y

    // y>x ->  1. y is odd  -> (y-1)*(y-1) + x
    //         2. y is even ->  y*y - (x-1)