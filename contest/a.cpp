#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x; cin >> x;
    while(true){
        if (x%2 == 0){
            x = x/2;
        } else if (x > 3) {
            x = x-3;
        } else {
            break;
        }
    }
    cout << x << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; 
    cin >> t;
    while (t--) solve();
    return 0;
}
