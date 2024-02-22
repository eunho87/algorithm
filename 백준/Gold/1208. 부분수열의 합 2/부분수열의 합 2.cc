#include <bits/stdc++.h>
using namespace std;

map <int, int> Find;
int arr[43];

int n, m;
long long ans = 0;

void left(int s, int sum) {
	if (s == n / 2) {
		ans += Find[m - sum];
		return;
	}
	left(s + 1, sum);
	left(s + 1, sum + arr[s]);
}

void right(int mid, int sum) {
	if (mid == n) {
		Find[sum]++;
		return;
	}

	right(mid + 1, sum);
	right(mid + 1, sum + arr[mid]);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	right(n/2,0);
	left(0,0);

	if (!m) cout << ans-1;
	else cout << ans;
	return 0;
}