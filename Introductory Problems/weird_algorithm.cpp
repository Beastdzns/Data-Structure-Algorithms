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
    cout << n << " ";
    while(n != 1){
        if(n & 1){
            n = n*3+1;
        } else {
            n /= 2;
        }
        cout << n << " ";
    }
    cout << endl;  
    return 0;
}