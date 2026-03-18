#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

long long arr[1000003];
long long arr2[1000003];
int d = 1000000007;

int main() {
    int n;
    scanf("%d", &n);

    arr[0] = 1;
    arr2[0] = 0;

    for (int i = 1; i <= n; i++) {
        arr[i] = (arr[i - 1] * 24 + arr2[i - 1] * 2) % d;
        arr2[i] = (arr2[i - 1] * 24 + arr[i - 1] * 2) % d;
    }

    printf("%lld", arr[n]);

    return 0;
}