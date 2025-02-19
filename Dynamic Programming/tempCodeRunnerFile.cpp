#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>> n;
    vector<int> dp(10, INT_MAX-1);
    dp[0]=0;
    int ans=0;
    for(int i=1; i<=n; i++){
        int number=i;
        while(number){
            int digit= number%10;
            if(i-digit>=0)
                dp[i]= min(dp[i], dp[i-digit]+1);
            number/=10;
        }
        ans= min(dp[i], ans);
    }
    cout<< ans <<endl;
    return 0;
}