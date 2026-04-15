#include <bits/stdc++.h>
using namespace std;
long long arr[400003];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q, chk = 1;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i + n] = arr[i];
	}
	for (int i = 1; i <= 2 * n; i++)
		arr[i] += arr[i - 1];
	for (int i = 1; i <= q; i++) {
		int r;
		cin >> r;
		if (r == 2) {
			int q;
			cin >> q;
			if (chk + q <= n) chk += q;
			else chk = chk + q - n;
		}
		if (r == 1) {
			int q;
			cin >> q;
			if (chk - q >= 1) chk -= q;
			else chk = chk + n - q;
		}
		if (r == 3) {
			int a, b;
			cin >> a >> b;
			a = chk + a - 1;
			b = chk + b - 1;
			cout << arr[b] - arr[a-1] << "\n";
		}
	}
	return 0;
}