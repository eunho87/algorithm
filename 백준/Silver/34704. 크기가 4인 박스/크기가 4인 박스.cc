#include <bits/stdc++.h>
using namespace std;

int arr[5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, p, ans = 0;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> p;
		arr[p]++;
	}

	ans += arr[4] + (arr[2] / 2) + (arr[1] < arr[3] ? arr[1] : arr[3]);
	arr[2] %= 2;
	if (arr[1] == arr[3]) {
		arr[1] = arr[3] = 0;
	}
	if (arr[1] < arr[3]) {
		arr[3] -= arr[1];
		arr[1] = 0;
	}
	else {
		arr[1] -= arr[3];
		arr[3] = 0;
	}
	if (arr[1] > 0) {
		while (arr[1] > 0 && arr[2] > 0) {
			ans++;
			arr[1] = max(0, arr[1] - 2);
			arr[2]--;
		}
		if (arr[2] > 0)	ans += arr[2];
		else ans += (arr[1] + 3) / 4;
	}
	else if (arr[3] > 0) {
		ans += arr[3];
		ans += arr[2];
	}
	else if (arr[2] > 0)	ans++;

	cout << ans;

	return 0;
}