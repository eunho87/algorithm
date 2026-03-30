#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int arr[1000003];
int main() {
    int n;
    ll k;
    scanf("%d %lld", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int ans = 0;
    int i = 0;

    while (i < n) {
        ans++;
        int p = i;
        int min_a = arr[i];
        int max_a = arr[i];

        i++;
        while (i < n) {
            min_a = min(min_a, arr[i]);
            max_a = max(max_a, arr[i]);
            ll width = (ll)max_a - min_a + 1;
            ll height = (ll)i - p + 1;
            if (width * height <= k) {
                max_a = max_a;
                i++;
            }
            else {
                break;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}