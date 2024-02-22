#include <bits/stdc++.h>
using namespace std;

int arr[1000003];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,q=0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int m;
		cin >> m;
		auto p = lower_bound(arr + 1, arr + 1 + q, m);
		*p = m;
		if (p == arr + q + 1) q++;	

	}
	cout << q;
	return 0;
}