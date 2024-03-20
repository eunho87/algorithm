#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

struct abc {
	int x, y;
}arr[53];

bool cmp(abc a, abc b) {
	return a.x != b.x ? a.x < b.x : a.y < b.y;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	int sum = INT_MAX;
	int chk=INT_MAX;
	cin >> n >> k;

	for (int i = 1; i <= n; ++i) {
		cin >> arr[i].x >> arr[i].y;
	}

	sort(arr + 1, arr + 1 + n, cmp);

	if (k == 1) {
		for (int j = 1; j <= n; j++) {
			int cost = 0;
			for (int p = 1; p <= n; p++) {
				cost= max(cost,abs(arr[j].x - arr[p].x) + abs(arr[j].y - arr[p].y));
			}
			chk= min (chk, cost);
		}
	}
	if (k == 2) {
		for (int j = 1; j <= n; j++) {
			for (int p = 1; p <= j - 1; p++) {
				int cost = 0;
				for (int q = 1; q <= n; q++) {
					cost= max(abs(arr[j].x - arr[q].x) + abs(arr[j].y - arr[q].y), abs(arr[p].x - arr[q].x) + abs(arr[p].y - arr[q].y));
				}
				chk = min(chk, cost);
			}
		}
	}
	if (k == 3) {
		for (int j = 1; j <= n; j++) {
			for (int p = 1; p <= j - 1; p++) {
				for (int q = 1; q <= p - 1; q++) {
					int cost = 0;
					for (int l = 1; l <= n; l++) {
						cost += max(abs(arr[j].x - arr[l].x) + abs(arr[j].y - arr[l].y), max(abs(arr[p].x - arr[l].x) + abs(arr[p].y - arr[l].y), abs(arr[l].x - arr[q].x) + abs(arr[l].y - arr[q].y)));
					}
					chk = min (chk, cost);
				}

			}
		}
	}

	cout << chk;

	return 0;
}