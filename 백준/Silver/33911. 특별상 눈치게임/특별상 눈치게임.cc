#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[101];

int main() {
    int n, m;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n * 3; i++) {
        scanf("%d", &m);
        if (m >= 1 && m <= 100) arr[m]++;
    }

    long long ans = 0;

    for (int i = 1; i <= 100; i++) {
        for (int j = i + 1; j <= 100; j++) {
            for (int k = j + 1; k <= 100; k++) {

                int other_q = 0;
                for (int x = 100; x >= 1; x--) {
                    if (x == i || x == j || x == k) continue;
                    if (arr[x] == 1) {
                        other_q = x;
                        break;
                    }
                }

                int my_p = 0;
                if (arr[k] == 0) my_p = k;
                else if (arr[j] == 0) my_p = j;
                else if (arr[i] == 0) my_p = i;

                if (my_p > other_q) {
                    ans++;
                }
            }
        }
    }

    printf("%lld", ans);
    return 0;
}