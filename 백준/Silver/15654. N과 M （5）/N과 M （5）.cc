#include <bits/stdc++.h>
using namespace std;

int arr[10];
bool V[10];
vector<int> v;
int n, m;

void solve() {
    if (v.size() == m) {
        for (int i = 0; i < m; i++) {
            cout << v[i] << (i == m - 1 ? "" : " ");
        }
        cout << "\n";
        return;
    }

    for (int j = 1; j <= n; j++) {
        if (!V[j]) {
            V[j] = true;
            v.push_back(arr[j]);

            solve();

            v.pop_back();
            V[j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr + 1, arr + 1 + n);

    solve();

    return 0;
}