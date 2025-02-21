#include<bits/stdc++.h>
using namespace std;
int rec(const string& limit, int left, int right, bool smaller, string s){
    if(left==right){
        cout<<s<<endl;
        return (limit[left]-'0'+1);
    }
    if(left>right){
        cout<<s<<endl;
        return 1;
    }
    int ans=0;
    if(left!=0)
        ans+= rec(limit, left+1, right-1, smaller, s+"0");
    int Leftlim= limit[left]-'0';
    int rightlim= limit[right]-'0';
    for(int i=1; i<=9; i++){
        if(i<=Leftlim && i<=rightlim){
            ans+= rec(limit, left+1, right-1, i<Leftlim || smaller, s+to_string(i));
        }
    }
    return ans;
}
void solve(){
    int i, j;
    cin >> i >> j;
    if(i>j) swap(i, j);

    int left= rec(to_string(i-1), 0, to_string(i-1).length()-1, 0, "");
    cout<<left<<endl;
    int right= rec(to_string(j), 0, to_string(j).size()-1, 0, "");
    cout<<right<<endl;
    cout << right-left;
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