#include <bits/stdc++.h>
using namespace std;
string n,m;
vector <int> ans;
long cnt[10];
void solve(){
    for(int i = 9; i >= 0; --i){
        //cout << i << " " << cnt[i] << "\n";
        if (cnt[i] == 0)
            continue;
        while (cnt[i]--){
            ans.push_back(i);
        }
    }
    while (ans[0] == 0)
        ans.pop_back();
    for(auto i:ans)
        cout << i;
}
void dfs(long i){
    //cout << i << "i\n";
    for(int j = m[i]-48; j >= 0; --j){
        if (cnt[j] > 0){
            cnt[j]--;
            ans.push_back(j);
            //cout << i << " " << j << "\n";
            if (j < (m[i]-48)){
                solve();
                exit(0);
            }
            if (i == m.length()-1){
                bool ok = false;
                for(int i = 0; i < ans.size(); ++i)
                    if ((m[i]-48) != ans[i]){
                        ok = true;
                        break;
                    }
                if (ok){
                    for(auto it:ans)
                        cout << it;
                    exit(0);
                }
            }
            dfs(i+1);
            cnt[j]++;
            ans.pop_back();
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("PERM.inp","r",stdin);
    //freopen("PERM.out","w",stdout);
    cin >> n >> m;
    //solve th n.length() = m.length()
    if (n.length() < m.length()){
        sort(n.begin(),n.end(),greater<char>());
        cout << n << "\n";
        return 0;
    }
    /*
    if (n.length() > m.length()){
        cout << "-1\n";
        return 0;
    }
    */
    int minn = 0;
    for(long i = 0; i < n.length(); ++i){
        cnt[n[i]-48]++;
        //if (n[i]-48 > 0)
            minn = min(minn,n[i]-48);
    }
    //minn dam bao la luon ton tai dap an => co the chay toi 0 trong dfs()
    if (minn > m[0])
        cout << "-1\n";
    else
        dfs(0);
    cout << "-1\n";
    return 0;
}
