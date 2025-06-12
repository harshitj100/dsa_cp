#include <bits/stdc++.h>
using namespace std;

int func(int a, int b) {
    int x = a ^ b;
    for (int i = 30; i >= 0; i--) {
        if ((x >> i) & 1) {
            return i; 
        }
    }
    return -1; 
}


void solve() {
    int n; cin >> n; 
    vector<int> a(n); for(int i = 0 ; i < n ; i++) cin >> a[i];
    int maxi = a[0];
    int count = 0;
    int ans = 0;
    for(int i = 1 ; i < n ; i++){
        if (a[i] >= maxi){
            maxi = a[i];
            continue;
        } else {
            count = func(maxi , a[i]);
            ans = max(ans , count);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; 
    cin >> t;
    while (t--) solve();
    return 0;
}
