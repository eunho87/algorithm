#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N; cin >> N;
	int K; cin >> K;
	string table; cin >> table;

	int count = 0;
	for (int i = 0; i < N; i++)
	{
		if (table[i] == 'P')
		{
			for (int j = i - K; j <= i + K; j++)
			{
				if (j >= 0 && j < N && table[j] == 'H')
				{
					count++; table[j] = 'E';
					break;
				}
			}
		}
	}
	cout << count;
}