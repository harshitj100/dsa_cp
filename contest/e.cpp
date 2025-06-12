#include <bits/stdc++.h>
using namespace std;

bool canParryK(int k, int X, const vector<int>& A, const vector<int>& B, int N) {
    vector<pair<int, int>> attacks;

    cout << "\nChecking if we can parry " << k << " attacks with skill " << X << "...\n";

    for (int i = 0; i < N; ++i) {
        if (X < A[i]) {
            cout << "Chef can't dodge attack " << i << " (A[i] = " << A[i] << "), so fight is lost.\n";
            return false;
        }

        if (X >= B[i]) {
            attacks.emplace_back(B[i], A[i]);
            cout << "Attack " << i << " is eligible for parry (A[i] = " << A[i] << ", B[i] = " << B[i] << ")\n";
        }
    }

    if ((int)attacks.size() < k) {
        cout << "Only " << attacks.size() << " attacks can be parried, which is less than " << k << ".\n";
        return false;
    }

    sort(attacks.begin(), attacks.end()); // greedy: easiest parries first

    for (int i = 0; i < k; ++i) {
        int skillAfterParries = X - i;
        cout << "Parry #" << i + 1 << ": Required dodge skill = " << attacks[i].second 
             << ", Chef's current skill = " << skillAfterParries << '\n';

        if (skillAfterParries < attacks[i].second) {
            cout << "Chef's skill too low to survive attack after parrying.\n";
            return false;
        }
    }

    cout << "Chef can successfully parry " << k << " attacks.\n";
    return true;
}

int maxParries(int N, int X, const vector<int>& A, const vector<int>& B) {
    int low = 0, high = N, ans = 0;
    cout << "\nStarting binary search to find max parries...\n";
    while (low <= high) {
        int mid = (low + high) / 2;
        cout << "\nTrying mid = " << mid << "...\n";
        if (canParryK(mid, X, A, B, N)) {
            ans = mid;
            cout << "Possible to parry " << mid << ", trying for more.\n";
            low = mid + 1;
        } else {
            cout << "Not possible to parry " << mid << ", trying less.\n";
            high = mid - 1;
        }
    }
    cout << "Maximum parries possible = " << ans << "\n";
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int N, X;
        cin >> N >> X;
        vector<int> A(N), B(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        for (int i = 0; i < N; ++i) cin >> B[i];

        cout << "\n==== Test Case #" << tc << " ====\n";
        cout << "Initial Skill: " << X << ", Number of Attacks: " << N << '\n';
        cout << "A (Dodge Skill): ";
        for (int val : A) cout << val << " ";
        cout << "\nB (Parry Skill): ";
        for (int val : B) cout << val << " ";
        cout << '\n';

        int result = maxParries(N, X, A, B);
        cout << "Result: " << result << "\n";
    }

    return 0;
}
