#include <bits/stdc++.h>
using namespace std;

int arr[1003][1003];
bool v[1003][1003];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> arr[i][j];
    }

    int p;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> p;
            arr[i][j] = p - arr[i][j];
        }
    }
    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        if (arr[r][c] != 0) {
            cout << "No";
            return 0;
        }
        v[r][c] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!v[i][j]) {
                long long B = 0, W = 0;
                queue<pair<int, int>> q;

                q.push({ i, j });
                v[i][j] = true;

                while (!q.empty()) {
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();
                    if ((r + c) % 2 == 0) W += arr[r][c];
                    else B += arr[r][c];

                    for (int t = 0; t < 4; t++) {
                        int nr = r + dx[t];
                        int nc = c + dy[t];
                        if (nr >= 1 && nr <= n && nc >= 1 && nc <= m && !v[nr][nc]) {
                            v[nr][nc] = true;
                            q.push({ nr, nc });
                        }
                    }
                }
                if (B != W) {
                    cout << "No";
                    return 0;
                }
            }
        }
    }

    cout << "Yes";
    return 0;
}