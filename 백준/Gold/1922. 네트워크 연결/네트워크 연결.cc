#include <bits/stdc++.h>
#define p pair<int, pair<int, int>>
using namespace std;

int parent[1003], n, m;
vector<p> v;
vector<p> mst;

int find_root(int x) {
	return parent[x] == x ? x : parent[x] = find_root(parent[x]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(NULL);
	cin >> n >> m;
	int a, b, c;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		v.push_back({ c,{a,b} });
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= n; i++) parent[i] = i;

	for (int i = 0; i < v.size(); i++) {

		int f = v[i].second.first;
		int s = v[i].second.second;

		if (find_root(f) == find_root(s)) continue;

		mst.push_back(v[i]);
		int x = find_root(f);
		int y = find_root(s);
		if (x != y) parent[y] = x;

		if (mst.size() == n - 1) break;
	}
	long long sum = 0;
	for (int i = 0; i < mst.size(); i++) {
		sum += mst[i].first;
	}
	cout << sum << '\n';
	return 0;
}