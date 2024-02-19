#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int arr[103];
int dp[100003];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= k; i++) {
		dp[i] = INT_MAX - 10;
	}
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		arr[i] = a;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = arr[i]; j <= k; j++) {
			dp[j] = min(dp[j - arr[i]]+1, dp[j]);
		}
	}
	if (dp[k] == INT_MAX - 10)	cout << -1;
	else cout << dp[k];
	return 0;
}