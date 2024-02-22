#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;

ll arr[2001][2001];
int m;

vector<int> Getluca(ll a, int mod) {
    vector<int> ret;
    while (a) {
        int r = a % mod;
        ret.push_back(r);
        a /= mod;
    }
    return ret;
}

ll comb(int n, int r) {
    if (n < r) return 0;
    if (n / 2 < r) r = n - r;

    ll& ret = arr[n][r];
    if (ret != -1) return ret;

    if (r == 0) return ret = 1;
    else if (r == 1) return ret = n;

    return ret = (comb(n - 1, r - 1) + comb(n - 1, r)) % m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(arr, -1, sizeof(arr));

    ll n, k, res = 1;

    cin >> n >> k >> m;

    vector<int> lucaN, lucaK;
    lucaN = Getluca(n, m);
    lucaK = Getluca(k, m);

    int idx = min(lucaN.size(), lucaK.size());
    for (int i = 0; i < idx; i++) {
        int n = lucaN[i];
        int r = lucaK[i];

        res = res * comb(n, r);
        res %= m;
    }

    cout << res;

    return 0;
}