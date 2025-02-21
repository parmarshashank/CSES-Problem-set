#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll y, x;
        cin >> y >> x;
        ll maxVal = max(x, y);
        ll base = (maxVal - 1) * (maxVal - 1);  // Base value of the layer

        if (maxVal % 2 == 0) {  // Even maxVal spirals leftward-down
            if (y == maxVal) cout << base + x;
            else cout << maxVal * maxVal - (y - 1);
        } else {  // Odd maxVal spirals rightward-up
            if (x == maxVal) cout << base + y;
            else cout << maxVal * maxVal - (x - 1);
        }
        cout << '\n';
    }
    return 0;
}
