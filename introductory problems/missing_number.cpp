#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n-1, 0);
    for(int i=0; i<n-1; i++){
        cin>> v[i];
    }
    int x=0;
    for(int i=0; i<n-1; i++){
        x^=v[i];
        x^=(i+1);
    }
    cout<< (x^n) <<endl;
    return 0;
}