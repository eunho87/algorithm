#include <stdio.h>
#include <math.h>

typedef long long ll;

ll arr[1000003];
ll tree[4000003];

ll init(int node, int start, int end) {
    if (start == end) {
        // 리프 노드에 배열의 값을 저장
        return tree[node] = arr[start];
    } else {
        // 자식 노드를 재귀적으로 초기화하고, 현재 노드에 자식 노드의 합 저장
        int mid = (start + end) / 2;
        return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
    }
}

ll sum(int node, int start, int end, int left, int right) {
    if (right < start || end < left) {
        return 0;
    }
    // 범위 안에 있는 경우
    if (left <= start && end <= right) {
        return tree[node];
    }
    // 걸쳐 있는 경우, 자식 노드로 분할하여 합 계산
    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx, ll diff) {
    if (idx < start || idx > end) return;

    // 현재 노드에 diff를 더함
    tree[node] += diff;
    
    // 리프 노드가 아닌 경우 자식 노드도 갱신
    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, idx, diff);
        update(node * 2 + 1, mid + 1, end, idx, diff);
    }
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &arr[i]);
    }
    init(1, 1, n);

    for (int i = 0; i < m + k; i++) {
        int a;
        int b;
        ll c;
        scanf("%d %d %lld", &a, &b, &c);

        if (a == 1) { 
            ll diff = c - arr[b]; 
            arr[b] = c; 
            update(1, 1, n, b, diff); 
        } else if (a == 2) { 
            printf("%lld\n", sum(1, 1, n, b, c));
        }
    }

    return 0;
}
