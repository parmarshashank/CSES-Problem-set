#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n= s.length();
    int ans=1;
    int curr=1;
    for(int i=1; i<n; i++){
        if(s[i]==s[i-1]){
            curr++;
            ans= max(ans, curr);
        }
        else{
            curr=1;
        }
    }
    cout<<ans<<endl;
    return 0;
}