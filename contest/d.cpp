#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        
        int c = 0 ,c2 = 0;
        for(int i = 0 ; i < n ; i++){
            if (a[i] > x) {
                c2 = a[i]-x;
            } else if (b[i] < x){
                c++;
                x--;
            } 

            if (c2 >= c){
                cout << 0 << endl;
                return 0;
            }

        }
        if (c2 >= c){
            cout << 0 << endl;
        } else {
            cout << c-c2 << endl;
        }
    }

    return 0;
}
