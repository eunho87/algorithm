#include <bits/stdc++.h>
using namespace std;

vector <pair<int,int> > v[20003];
vector <int> chk(20003, INT_MAX);
priority_queue <pair<int,int> > pq;
int n, m,k;
long long sum;

void dikstra(int a) {
	pq.push({ 0,a });
	chk[a] = 0;
	while (!pq.empty()) {
		int q = -pq.top().first;
		int t = pq.top().second;
		pq.pop();
		if (q > chk[t])	continue;
		for (int i = 0; i < v[t].size(); i++) {
			int r = v[t][i].first;
			int w = v[t][i].second + q;
			if (w < chk[r]) {
				chk[r] = w;
				pq.push({ -w,r });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;

	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		//v[b].push_back({ a,c });
	}
	dikstra(k);

	for (int i = 1; i <= n; i++) {
		if (i == k)	cout << 0<<'\n';
		else if (chk[i] == INT_MAX)	cout << "INF"<<'\n';
		else cout << chk[i]<<'\n';
	}
	
	return 0;
}