#include<bits/stdc++.h>
using namespace std;
int dp[20][4][2];
int rec(const string &lim, int ind, int non_zero, bool smaller){
    if(non_zero>3) return 0;
    if(ind==lim.size()) return 1;
    if(dp[ind][non_zero][smaller]!=-1) return dp[ind][non_zero][smaller];
    int ans= rec(lim, ind+1, non_zero, smaller?smaller:lim[ind]!='0');
    if(smaller){
        ans+= 9*rec(lim, ind+1, non_zero+1, smaller);
    }
    else{
        int lesser= lim[ind]-'0'-1;
        if(lesser>0){
            ans+= lesser*rec(lim, ind+1, non_zero+1, true);
        }
        if(lim[ind]!='0'){
            ans+= rec(lim, ind+1, non_zero+1, false);
        }
    }
    return dp[ind][non_zero][smaller]=ans;
}
void solve(){
    long long l,r;
    cin>>l>>r;
    memset(dp, -1, sizeof(dp));
    int leftCnt=rec(to_string(l-1), 0, 0, 0);
    memset(dp, -1, sizeof(dp));
    int rightCnt=rec(to_string(r), 0, 0, 0);
    cout<<rightCnt-leftCnt<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}