#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define mod 1000000007 
using namespace std;

int dp[103][103][103];

int main() {
	int n, l, r;
	cin >> n >> l >> r;
	dp[1][1][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= l; j++) {
			for (int k = 1; k <= r; k++) {
				dp[i][j][k] = ((long long)dp[i - 1][j][k] * (i - 2) + dp[i - 1][j][k - 1] + dp[i - 1][j - 1][k]) % mod;
			}
		}
	}
	cout << dp[n][l][r];
}
