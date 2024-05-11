#include <bits/stdc++.h>
using namespace std;

int arr[100003];

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);

	int n, k;
	long long sum = 0, t;
	cin >> n >> k;
	for (int i = 1; i <= k; i++)	sum += i;
	if (sum > n) {
		cout << "-1";
		return 0;
	}
	t = n - sum;
	if (t % k == 0) {
		cout << k - 1;
	}
	else {
		cout << k;
	}

	return 0;
}