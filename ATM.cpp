#include <bits/stdc++.h>
using namespace std;
long n,a[20],k[20];
long long s;
void inp(){
    cin >> n >> s;
    for(int i = 0; i < n; i++)
        cin >> a[i];
}
void out(){
    vector <int> q;
    for(int i = 0; i < n; i++)
        if (k[i] == 1)
            q.push_back(a[i]);
    cout << *q.begin();
    for(auto it = q.begin()+1; it != q.end(); it++)
        cout << " " << *it;
}
void solve(){
    long long t = 0;
    for(int i = 0; i < n; i++)
        if (k[i] == 1)
            t += a[i];
    if (t == s){
        out();
        exit(0);
    }
}
void dfs(int i){
    for(int j = 0; j <= 1; j++){
        k[i] = j;
        if (i == n-1)
            solve();
        else
            dfs(i+1);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ATM.INP","r",stdin);
    freopen("ATM.OUT","w",stdout);
    inp();
    dfs(0);
    cout << -1 << endl;
    return 0;
}
