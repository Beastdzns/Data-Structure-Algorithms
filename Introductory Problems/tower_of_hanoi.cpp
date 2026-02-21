#include<bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)

using ll = long long;
using ull = unsigned long long;
using ld = long double;

const ll INF = 1e18;
const int MOD = 1e9 + 7;

void solve(int n, int from, int to, int aux){
    if(n == 0) return;

    solve(n-1, from, aux, to);

    cout << from << " " << to << endl;

    solve(n-1, aux, to, from);
}

int main() {
    fastio();

    int n;
    cin >> n;
    
    cout << ( (1LL << n) - 1) << endl;

    solve(n, 1, 3, 2);
    
    return 0;
}