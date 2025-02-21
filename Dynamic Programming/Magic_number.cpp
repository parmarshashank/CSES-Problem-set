#include<bits/stdc++.h>
using namespace std;
const int divide = 1e9+7;
int dp[2001][2][2001];

string subtractOne(const string &numStr) {
    if(numStr == "0") return "0"; 
    string result = numStr;
    int i = result.size() - 1;
    while (i >= 0) {
        if (result[i] > '0') {
            result[i]--;
            break;
        } else {
            result[i] = '9';
            i--;
        }
    }
    if (result[0] == '0' && result.size() > 1) {
        result.erase(result.begin());
    }
    return result;
}

int rec(const string &lim, int ind, bool smaller, int mod, int m, int d){
    if(ind == lim.size()) {
        if(mod == 0 && (lim.size() > 1 || d == 0)){
            return 1;
        }
        return 0;
    }
    
    if(dp[ind][smaller][mod] != -1) return dp[ind][smaller][mod];
    
    long long ans = 0;  
    int limit = (smaller ? 9 : lim[ind]-'0');
    
    if(ind % 2 != 0){
        if(d <= limit)
            ans = (ans + rec(lim, ind+1, smaller || d < limit, 
                           (int)((1LL * mod * 10 + d) % m), m, d)) % divide;
    }
    else{
        for(int i = 0; i <= limit; i++){
            if(ind == 0 && i == 0) continue;
            if(i == d) continue;
            int nsmaller = (smaller || i < limit);
            int nmod = (int)((1LL * mod * 10 + i) % m);  
            ans = (ans + rec(lim, ind+1, nsmaller, nmod, m, d)) % divide;
        }
    }
    return dp[ind][smaller][mod] = (int)ans;
}

int main(){
    int m, d;
    string l, r;
    cin >> m >> d >> l >> r;
    if(l.size() == 1 && r.size() == 1)
    {   int cnt=0;
        int li= stoi(l);
        int ri= stoi(r);
        for(int i=li; i<=ri; i++){
            if(i%m==0 && i!=d){
                cnt++;
            }
        }
        cout<< cnt<<endl;
        return 0;
    }
    
    string l1 = subtractOne(l);
    
    if(l1.size() != l.size()){
        memset(dp, -1, sizeof(dp));
        cout << rec(r, 0, 0, 0, m, d);
        return 0;
    }
    
    memset(dp, -1, sizeof(dp));
    int left = rec(l1, 0, 0, 0, m, d);
    
    memset(dp, -1, sizeof(dp));
    int right = rec(r, 0, 0, 0, m, d);
    
    int result = (right - left) % divide;
    if(result < 0) result += divide;
    
    cout << result << endl;
    return 0;
}