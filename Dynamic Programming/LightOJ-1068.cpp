#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct State {
    int pos, smaller, mod, sum;
    // custom equality and hash for unordered_map
    bool operator==(const State &other) const {
        return pos == other.pos && smaller == other.smaller &&
               mod == other.mod && sum == other.sum;
    }
};

struct StateHash {
    std::size_t operator()(const State &s) const {
        return (((((s.pos * 3) ^ s.smaller) * 10007 + s.mod) * 200) ^ s.sum);
    }
};

unordered_map<State, ll, StateHash> memo;

ll rec(const string &lim, int pos, int smaller, int mod, int sum, int k) {
    if (pos == lim.size())
        return (mod == 0 && sum % k == 0) ? 1LL : 0LL;
    
    State st{pos, smaller, mod, sum};
    if(memo.find(st) != memo.end())
        return memo[st];
    
    ll ans = 0;
    int limit = (smaller ? 9 : lim[pos] - '0');
    for (int d = 0; d <= limit; d++) {
        int nsmaller = (smaller || (d < limit));
        int nmod = (mod * 10 + d) % k;
        int nsum = sum + d;
        // You can add a pruning condition if nsum exceeds maximum possible.
        ans += rec(lim, pos + 1, nsmaller, nmod, nsum, k);
    }
    
    memo[st] = ans;
    return ans;
}

ll F(ll X, int k) {
    string s = to_string(X);
    memo.clear();
    return rec(s, 0, 0, 0, 0, k);
}

void solve() {
    ll l, r;
    int k;
    cin >> l >> r >> k;
    // Optional early check: if k > 9 * number_of_digits, then no positive number qualifies.
    int maxDigits = to_string(r).size();
    if (k > 9 * maxDigits) {
        cout << 0;
        return;
    }
    ll rightCnt = F(r, k);
    ll leftCnt = F(l - 1, k);
    cout << rightCnt - leftCnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++){
        cout << "Case " << i << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}
