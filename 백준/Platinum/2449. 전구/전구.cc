#include <bits/stdc++.h>
using namespace std;

int dp[203][203];
int arr[203];

int solve(int a, int b) {
	if(a == b)	return 0;

	int &ret = dp[a][b];
	if (ret != -1) return ret;

	ret = 1e9+7;

	for (int i = a; i <= b; i++) {
		int t = (arr[a] == arr[i + 1] ? 0 : 1);
		ret = min(ret, solve(a, i) + t + solve(i + 1, b));
	}
	return ret;
}

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	memset(dp, -1, sizeof(dp));

	cout << solve(1, n);
}