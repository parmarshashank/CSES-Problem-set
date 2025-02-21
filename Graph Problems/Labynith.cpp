#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool dfs(vector<vector<char>> &grid, int i, int j, string &ans, string curr) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '#')
        return false;
    
    if (grid[i][j] == 'B') {
        if (ans.empty() || curr.size() < ans.size()) {
            ans = curr;
        }
        return true;
    }
    
    grid[i][j] = '#'; 

    bool found = false;
    if (dfs(grid, i + 1, j, ans, curr + 'D')) found = true;
    if (dfs(grid, i - 1, j, ans, curr + 'U')) found = true;
    if (dfs(grid, i, j + 1, ans, curr + 'R')) found = true;
    if (dfs(grid, i, j - 1, ans, curr + 'L')) found = true;
    
    grid[i][j] = '.';
    
    return found;
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++)
            cin >> grid[i][j];

    string ans = "";
    bool found = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                found = dfs(grid, i, j, ans, "");
                break;
            }
        }
        if (found) break;
    }

    if (found) {
        cout << "YES\n" << ans << endl;
    } else {
        cout << "NO\n";
    }

    return 0;
}
