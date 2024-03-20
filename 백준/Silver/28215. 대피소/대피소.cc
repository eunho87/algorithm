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
	int chk=0;
	cin >> n >> k;

	for (int i = 1; i <= n; ++i) {
		cin >> arr[i].x >> arr[i].y;
	}

	sort(arr + 1, arr + 1 + n, cmp);

	if (k == 1) {
		for (int j = 1; j <= n; j++) {
			int cost = 0;
			for (int p = 1; p <= n; p++) {
				cost += abs(arr[j].x - arr[p].x) + abs(arr[j].y - arr[p].y);
			}
			if (sum > cost) {
				sum = cost;
				chk = 0;
				for (int p = 1; p <= n; p++) {
					int w;
					w = abs(arr[j].x - arr[p].x) + abs(arr[j].y - arr[p].y);
					if (chk < w)	chk = w;
				}
			}
		}
	}
	if (k == 2) {
		for (int j = 1; j <= n; j++) {
			for (int p = 1; p <= j - 1; p++) {
				int cost = 0;
				for (int q = 1; q <= n; q++) {
					cost += min(abs(arr[j].x - arr[q].x) + abs(arr[j].y - arr[q].y), abs(arr[p].x - arr[q].x) + abs(arr[p].y - arr[q].y));
				}
				if (sum > cost) {
					sum = cost;
					chk = 0;
					for (int q = 1; q <= n; q++) {
						int w;
						w= min(abs(arr[j].x - arr[q].x) + abs(arr[j].y - arr[q].y), abs(arr[p].x - arr[q].x) + abs(arr[p].y - arr[q].y));
						if (chk < w)	chk = w;
					}
				}
			}
		}
	}
	if (k == 3) {
		for (int j = 1; j <= n; j++) {
			for (int p = 1; p <= j - 1; p++) {
				for (int q = 1; q <= p - 1; q++) {
					int cost = 0;
					for (int l = 1; l <= n; l++) {
						cost += min(abs(arr[j].x - arr[l].x) + abs(arr[j].y - arr[l].y), min(abs(arr[p].x - arr[l].x) + abs(arr[p].y - arr[l].y), abs(arr[l].x - arr[q].x) + abs(arr[l].y - arr[q].y)));
					}
					if (sum > cost) {
						sum = cost;
						chk = 0;
						for (int l = 1; l <= n; l++) {
							int w;
							w = min(abs(arr[j].x - arr[l].x) + abs(arr[j].y - arr[l].y), min(abs(arr[p].x - arr[l].x) + abs(arr[p].y - arr[l].y), abs(arr[l].x - arr[q].x) + abs(arr[l].y - arr[q].y)));
							if (chk < w)	chk = w;
						}
					}
				}

			}
		}
	}

	cout << chk;

	return 0;
}