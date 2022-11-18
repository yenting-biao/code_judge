#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    for(auto i:v){
        cout << i << ' ';
    }
    return 0;
}