#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int arr[23];
int dp[10003];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t) {
		int n,k;
		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		cin >> k;

		for (int i = 1; i <= k; i++) {
			dp[i] = 0;
		}
		dp[0] = 1;

		for (int i = 1; i <= n; i++) {
			for (int j = arr[i]; j <= k; j++) {
				dp[j] += dp[j - arr[i]];
			}
		}
		cout << dp[k] << "\n";
		t--;
	}
	
	return 0;
}