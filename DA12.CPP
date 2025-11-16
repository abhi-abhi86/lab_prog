#include <stdio.h>
#include <limits.h>

#define MAX 100

// This program finds the Minimum Spanning Tree (MST) using Kruskal's algorithm.

int parent[MAX];

int find(int i) {
    while (parent[i] != i) {
        i = parent[i];
    }
    return i;
}

void union1(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskal(int cost[][MAX], int n) {
    int mincost = 0, edge_count = 0, i, j;

    for (i = 0; i < n; i++)
        parent[i] = i;

    while (edge_count < n - 1) {
        int min = INT_MAX, a = -1, b = -1;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (find(i) != find(j) && cost[i][j] != 0 && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        union1(a, b);
        printf("Edge %d: (%d, %d) cost: %d\n", edge_count++, a, b, min);
        mincost += min;
    }

    printf("Minimum cost: %d\n", mincost);
}

int main() {

    int n, cost[MAX][MAX], i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    }

    kruskal(cost, n);

    return 0;
}