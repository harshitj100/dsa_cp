#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    
    int global_max = 0;
    int i1 = 0, j1 = 0;

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (global_max < a[i][j]) {
                global_max = a[i][j];
            }
        }
    }

    
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; 
    cin >> t;
    while (t--) solve();
    return 0;
}
