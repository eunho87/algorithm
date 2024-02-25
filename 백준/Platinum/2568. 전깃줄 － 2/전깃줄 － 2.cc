#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

struct  abc {
	int x, y;
}arr[100003];

int arr2[100003];
int chk[100003];
map <int, int> mp;
priority_queue <int> pq;
bool cmp(abc a, abc b) {
	return a.x < b.x ? true : false;
}

void Find(long long idx, long long num) {
	if (idx == 0)	return;
	if (chk[idx] == num) {
		Find(idx - 1, num - 1);
		pq.push(-arr[idx].x);
	}
	else {
		Find(idx - 1, num);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, q = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].x >> arr[i].y;
	}
	sort(arr + 1, arr + 1 + n, cmp);

	for (int i = 1; i <= n; i++) {
		int p = lower_bound(arr2 + 1, arr2 + q + 1, arr[i].y) - arr2;
		arr2[p] = arr[i].y;
		chk[i] = p;
		if (p == q + 1)	q++;
	}
	cout << n - q << '\n';
	Find(n, q);
	for (int i = 1; i <= n; i++) {
		if (-pq.top() == arr[i].x) {
			pq.pop();
		}
		else cout << arr[i].x << '\n';
	}
	return 0;
}