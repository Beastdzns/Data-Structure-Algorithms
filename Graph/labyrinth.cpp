#include<bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)

using ll = long long;
using ull = unsigned long long;
using ld = long double;

const ll INF = 1e18;
const int MOD = 1e9 + 7;

using pii = pair<int, int>;
const vector<char> dir = {'U', 'R', 'D', 'L'};
const vector<int> delRow = {-1, 0, 1, 0};
const vector<int> delCol = {0, 1, 0, -1};

int main() {
    fastio();

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for(int i=0;i<n;i++){
        cin >> grid[i];
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<char>> prev(n, vector<char>(m, 0));

    pii start, end;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 'A')   
                start = {i,j};
            else if(grid[i][j] == 'B')
                end = {i,j};
        }
    }

    queue<pii> q;
    vis[start.first][start.second] = true;
    q.push(start);
    bool found = false;

    while(!q.empty() && !found){
        auto [r,c] = q.front();
        q.pop();

        for(int d=0;d<4;d++){
            int nr = r + delRow[d];
            int nc = c + delCol[d];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] != '#'){
                vis[nr][nc] = true;
                prev[nr][nc] = dir[d];
                q.push({nr, nc});

                if(make_pair(nr, nc) == end){
                    found = true;
                    break;
                }
            }
        }
    }

    if(!vis[end.first][end.second]){
        cout << "NO\n";
        return 0;
    }

    string path;
    pii current = end;

    while(current != start){
        char direction = prev[current.first][current.second];
        path.push_back(direction);

        int idx = find(dir.begin(), dir.end(), direction) - dir.begin();
        current.first -= delRow[idx];
        current.second -= delCol[idx];
    }

    reverse(path.begin(), path.end());

    cout << "YES\n" << path.size() << "\n" << path << "\n";
    return 0;
}