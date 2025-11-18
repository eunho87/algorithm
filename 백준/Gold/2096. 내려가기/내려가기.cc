#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int dp[6];
int dp2[6];
int arr[6];
int main() {
	int n,p,q,r;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			scanf("%d", &arr[j]);
			if (i == 1)  dp[j] = dp2[j] = arr[j];
		}
		if (i != 1) {
			p= max(dp[1], dp[2]);
			q= max(dp[1], max(dp[2], dp[3]));
			r = max(dp[2], dp[3]);
			dp[1] = arr[1] + p;
			dp[2] = arr[2] + q;
			dp[3] = arr[3] + r;

			p= min(dp2[1], dp2[2]);
			q= min(dp2[1], min(dp2[2], dp2[3]));
			r= min(dp2[2], dp2[3]);
			dp2[1] = arr[1] + p;
			dp2[2] = arr[2] + q;
			dp2[3] = arr[3] + r;
		}
	}
	printf("%d %d", max(max(dp[1], dp[2]), dp[3]), min(min(dp2[1], dp2[2]), dp2[3]));
	return 0;
}