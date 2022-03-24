#include <bits/stdc++.h>
using namespace std;

void permute(string &a) {
    int n = a.size();
    while (true) {
        cout << a << '\n';
        int k, l;
        for (k = n-2; k>=0; k--)
            if (a[k] < a[k+1])
                break;
        if (k<0)
            break;
        for (l = n-1; l>k; l--)
            if (a[k] < a[l])
                break;
        swap(a[k], a[l]);
        for (int i=k+1, j=n-1; i<j; i++, j--)
            swap(a[i], a[j]);
    }
}
void solve(string s){
    //dung ham next_permuataion
    int cnt = 1;
    sort(s.begin(),s.end());
    cout << s << "\n";
    while (next_permutation(s.begin(),s.end())){
        cout << s << "\n";
        cnt++;
    }
    cout << cnt << endl;
}
void out(string s){
    sort(s.begin(), s.end());
    int res = 1;
    for (int i=1; i<=(int)s.size(); i++)
        res *= i;
    for (int i=1, c = 1; i<(int)s.size(); i++)
        if (s[i] == s[i-1])
            c++, res /= c;
        else c = 1;
    cout << res << '\n';
    permute(s);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    out(s);
    //solve(s);
    return 0;
}

