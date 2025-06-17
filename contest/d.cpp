#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));

    int global_max = 0;

    // Step 1: Read matrix and find global max
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            global_max = max(global_max, a[i][j]);
        }

    // Step 2: Count occurrences of global_max in each row and column
    vector<int> row_count(n, 0), col_count(m, 0);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j] == global_max) {
                row_count[i]++;
                col_count[j]++;
            }

    // Step 3: Find the row and column with the most global_max values
    int best_row = max_element(row_count.begin(), row_count.end()) - row_count.begin();
    int best_col = max_element(col_count.begin(), col_count.end()) - col_count.begin();

    cout << best_col << ' ' << best_row << endl;
    for (int j = 0; j < m; ++j) a[best_row][j]--;
    for (int i = 0; i < n; ++i)
        if (i != best_row) a[i][best_col]--;

    // Step 5: Find new max in the matrix
    int new_max = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            new_max = max(new_max, a[i][j]);

    cout << new_max << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
