#include <bits/stdc++.h>
using namespace std;

long long tree[100003];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	long long n, ta, ans_a, ans_b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
	}
	sort(tree, tree + n);
	long long ans = LLONG_MAX;
	int a = 0, b = n - 1;
	while (a < b) {
		ta = tree[a] + tree[b];
		if (ans > abs(ta)) {
			ans_a = tree[a];
			ans_b = tree[b];
			ans = abs(ta);
		}

		if (ta > 0)	b -= 1;
		else if (ta < 0)	a += 1;
		else break;
	}
	cout << ans_a << " " << ans_b;
	return 0;
}