#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

typedef long long ll;

ll arr[1000003];
ll tree[4000003];
ll lazy[4000003];

ll init(int node, int start, int end) {
    if (start == end) {
        return tree[node] = arr[start];
    }
    else {
        int mid = (start + end) / 2;
        return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
    }
}

void propagate(int node, int start, int end) {
    if (lazy[node] != 0) { 
        tree[node] += (end - start + 1) * lazy[node];  // lazy 값 반영

        if (start != end) {  // 리프 노드가 아니면 자식에게 lazy 값 전달
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }

        lazy[node] = 0;  
    }
}

ll sum(int node, int start, int end, int left, int right) {
    propagate(node, start, end);  //lazy 값 반영

    if (right < start || end < left) {  
        return 0;
    }

    if (left <= start && end <= right) {  
        return tree[node];
    }

    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int left, int right, ll diff) {
    propagate(node, start, end);  // lazy 값 먼저 반영

    if (right < start || end < left) {  // 구간이 겹치지 않으면 리턴
        return;
    }

    if (left <= start && end <= right) {  // 구간이 완전히 포함되면 lazy 갱신
        tree[node] += (end - start + 1) * diff;

        if (start != end) {  // 리프 노드가 아니라면 자식 노드의 lazy에 diff 추가
            lazy[node * 2] += diff;
            lazy[node * 2 + 1] += diff;
        }
        return;
    }

    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, diff);
    update(node * 2 + 1, mid + 1, end, left, right, diff);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];  // 자식 노드의 합으로 현재 노드 갱신
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
        int b, c;
        ll d;
        scanf("%d", &a);

        if (a == 1) {
            scanf("%d %d %lld", &b, &c, &d);
            update(1, 1, n, b, c, d);
        }
        else if (a == 2) {
            scanf("%d %d", &b, &c);
            printf("%lld\n", sum(1, 1, n, b, c));
        }
    }

    return 0;
}

