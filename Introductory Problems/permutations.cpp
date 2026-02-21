#include<bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)

using ll = long long;
using ull = unsigned long long;
using ld = long double;

const ll INF = 1e18;
const int MOD = 1e9 + 7;

void print(vector<int>& a){
    for(int x: a)
        cout << x << " ";
    cout << endl;
}

int main() {
    fastio();

    int n;
    cin >> n;
    vector<int> a;

    if(n == 3 || n == 2){
        cout << "NO SOLUTION";
        return 0;
    } else {
        int cx = 1;
        for(int i=2;i<=n;i+=2){
            a.push_back(i);
        }
        for(int i=1;i<=n;i+=2){
            a.push_back(i);
        }
    }
    print(a);
    return 0;
}