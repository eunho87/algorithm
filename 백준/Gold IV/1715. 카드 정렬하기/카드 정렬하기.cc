#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

priority_queue<int, vector<int> > pq;
int main() {
	int n,i;
	scanf("%d",&n);
	int m, sum = 0;

	for (i = 1; i <= n; i++) {
		scanf("%d", &m);
		pq.push(-m);
	}

	int chk;
	while (pq.size()>1) {
		chk = 0;
		chk = -pq.top();
		pq.pop();
		chk += -pq.top();
		pq.pop();
		sum += chk;
		pq.push(-chk);
	}

	printf("%d", sum);
	return 0;
}