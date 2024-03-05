#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int k; 
    cin >> k;
    int n = log2((k - 1) / 2 + 1);
    int c = k - pow(2, n) * 2 + 1;
    string s = "";
    bitset<32> ans = c;

    for (int i = 0; i <= n; i++) {
        if (ans[i]) s.append("7");
        else s.append("4");
    }
    reverse(s.begin(), s.end());
    cout << s << '\n';
    return 0;
}