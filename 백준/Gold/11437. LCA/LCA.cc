#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

vector<int> a[100003];
int parent[100003], check[100003], depth[100003], p[100003][18];

int lca(int u, int v) {
	if (depth[u] < depth[v])	swap(u, v);

	int log = 1;
	for (log = 1; (1 << log) <= depth[u]; log++);

	log -= 1;
	for (int i = log; i >= 0; i--) {
		if (depth[u] - (1 << i) >= depth[v]) {
			u = p[u][i];
		}
	}

	if (u == v) {
		return u;
	}
	else {
		for (int i = log; i >= 0; i--) {
			if (p[u][i] != 0 && p[u][i] != p[v][i]) {
				u = p[u][i];
				v = p[v][i];
			}
		}
		return parent[u];
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}

	depth[1] = 0;
	check[1] = 1;
	queue<int>q;
	q.push(1);
	parent[1] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int y : a[x]) {
			if (!check[y]) {
				depth[y] = depth[x] + 1;
				check[y] = 1;
				parent[y] = x;
				q.push(y);

			}
		}
	}

	for (int i = 1; i <= n; i++) {
		p[i][0] = parent[i];
	}
	for (int j = 1; (1 << j) < n; j++) {
		for (int i = 1; i <= n; i++) {
			if (p[i][j - 1] != 0) {
				p[i][j] = p[p[i][j - 1]][j - 1];
			}
		}
	}

	int  m;

	scanf("%d", &m);

	while (m--) {
		int u, v;
		scanf("%d %d", &u, &v);
		printf("%d\n", lca(u, v));
	}
	return 0;
}