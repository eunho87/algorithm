#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int arr[4003];
int dp[4003];

int main() {
	int n, m, s, e, q;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i * 2 - 1]);
		arr[2 * i] = 0;
	}
	for (int i = 1; i <= n*2; i++) {
		for (int j = 1; j <= n*2; j++) {
			if (arr[i - j] == arr[i + j] && i - j > 0 && i + j < n*2) dp[i] += 1;
			else break;
		}
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &s, &e);
		s = s * 2 - 1;
		e = e * 2 - 1;
		q = (s + e) / 2;
		if (dp[q] >= q - s) {
			printf("1\n");
		}
		else printf("0\n");
	}
	return 0;
}