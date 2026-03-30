#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int INF = 1e9;

int dist[40003];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    vector<int> coins;
    for (int i = 0; i < N; i++) {
        int p;
        scanf("%d", &p);
        if (p != 0) {
            coins.push_back(p);
        }
    }

    sort(coins.begin(), coins.end());
    coins.erase(unique(coins.begin(), coins.end()), coins.end());
    
    for (int i = 0; i <= 40000; i++) {
        dist[i] = INF;
    }

    queue<int> q;
    dist[20000] = 0;
    q.push(0);

    if (M == 0) {
        printf("0");
        return 0;
    }

    bool found = false;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int coin : coins) {
            int next = curr + coin;

            if (next >= -20000 && next <= 20000) {
                if (dist[next + 20000] == INF) {
                    dist[next + 20000] = dist[curr + 20000] + 1;

                    if (next == M) {
                        found = true;
                        break;
                    }
                    q.push(next);
                }
            }
        }
        if (found) break;
    }

    if (dist[M + 20000] == INF) {
        printf("-1");
    }
    else {
        printf("%d", dist[M + 20000]);
    }

    return 0;
}