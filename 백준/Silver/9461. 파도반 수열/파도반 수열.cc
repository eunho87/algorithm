#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

long long dp[103] = { 0,1,1,1,2,2,3,4,5,7 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 10; i <= 100; i++) {
		dp[i] = dp[i - 1]+ dp[i-5];
	}
	while (t) {
		int n;
		cin >> n;
		cout << dp[n] << '\n';
		t--;
	}
	return 0;
}