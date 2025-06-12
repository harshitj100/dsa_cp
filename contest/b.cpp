#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    for(int i = 0 ; i < n ; i++){
        if (s[i] == 0){
            if (i-1 >= 0 && s[i-1] == 1) {
                s[i-1] = 2;
                continue;
            } else if (I+1 < n && s[i+1] == 1){
                s[i+1] = 2;
                continue;
            } else {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; 
    cin >> t;
    while (t--) solve();
    return 0;
}
