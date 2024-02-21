#include<bits/stdc++.h>
using namespace std;

int n, h, s[2][250003], val, i;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	memset(s, -1, sizeof(s));
	s[0][0] = 0;

	cin >> n;
	while (n--) {
		cin >> h;
		int ni = i ^ 1;
		for (int j = 0; j <= 250000; j++) {
			if ((val = s[i][j]) >= 0) {
				int a = j + h, b = abs(j - h);
				s[ni][j]=max(s[ni][j], val);
				if (a <= 250000)s[ni][a] = max(s[ni][a], val + h);
				if (b <= 250000)s[ni][b] = max(s[ni][b], val + (j < h ? b : 0));
			}
		}
		i = ni;
	}

	cout << (s[i][0] > 0 ? s[i][0] : -1);
	return 0;
}