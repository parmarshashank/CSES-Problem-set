#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp(501, vector<int>(501, INT_MAX-1));
int main(){
    int a, b;
    cin>> a >> b;

    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){
            if(i==j){
                dp[i][j]=0;
                continue;
            }
            for(int v=1; v<i; v++){
                dp[i][j]= min(dp[i][j], dp[v][j]+dp[i-v][j]+1);
            }
            for(int h=1; h<j; h++){
                dp[i][j]= min(dp[i][j], dp[i][h]+dp[i][j-h]+1);
            }
        }
    }
    cout<< dp[a][b];
    return 0;

}