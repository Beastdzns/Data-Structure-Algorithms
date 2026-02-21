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

    for(int k=1;k<=n;k++){
        ll total_cells = k*k;
        if(k==1){
            cout << 0 << endl;
        } else {
            ll total = total_cells * (total_cells-1) / 2;

            ll slabs = (k-2)*(k-1)*2*2;
            cout << total - slabs << endl;
        }
    }
    return 0;
}