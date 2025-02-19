#include<bits/stdc++.h>
using namespace std;
bool isValid(int x, int m){
    return x>=1 && x<=m;
}
int main(){
    int n, m;
    cin>> n >> m;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>> a[i];
    }
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1; i<=m; i++){
        if(a[0]==0 || a[0]==i)
            dp[1][i]=1;
    }

    for(int i=2; i<=n; i++){
        for(int k=1; k<=m; k++){
            if(a[i-1]!=0 && a[i-1]!=k){
                dp[i][k]=0;
                continue;
            }
            for(int j: {k-1, k, k+1}){
                if(isValid(j, m))
                    dp[i][k]= (dp[i][k]+dp[i-1][j])%1000000007;
            }
        }
    }
    int ans=0;
    for(int i=1; i<=m; i++){
        ans= (ans+dp[n][i])%1000000007;
    }
    cout<<ans<<endl;
    return 0;
}

