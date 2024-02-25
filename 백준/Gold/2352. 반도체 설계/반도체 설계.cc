#include <bits/stdc++.h>
using namespace std;

long long arr[40003];
int arr2[40003];
int arr3[40003];

void Find(long long idx,long long num) {
	if (idx == 0)	return;
	if (arr2[idx] == num) {
		Find(idx - 1, num - 1);
		cout << arr3[idx] << " ";
	}
	else {
		Find(idx - 1, num);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,q=0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr3[i];
		int p = lower_bound(arr + 1, arr + 1 + q, arr3[i]) - arr;
		arr[p] = arr3[i];
		arr2[i] = p;
		if (p == q + 1) q++;	

	}
	cout << q<<"\n";
	//Find(n,q);
	return 0;
}