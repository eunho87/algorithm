#include <bits/stdc++.h>
using namespace std;
int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<long long> tree(N);

	for (int i = 0; i < N; i++)
	{
		cin >> tree[i];
	}

	int a = 0;
	int b = N - 1;

	long long Max, Min;

	long long ans = LLONG_MAX;

	while (a < b)
	{
		long long sum = tree[a] + tree[b];

		if (abs(sum) < abs(ans))
		{
			Max = tree[b];
			Min = tree[a];
			ans = sum;
		}

		if (sum < 0)
		{
			a+=1;
		}

		else if (sum > 0)
		{
			b-=1;
		}

		else
		{
			break;
		}
	}

	cout << Min << ' ' << Max;
}