#include <stdio.h>
#include <limits.h> 

// This program finds the Minimum Spanning Tree (MST) using Prim's algorithm.

int main(void) {
    int n, i, j, min, ne = 1, min_cost = 0;
    int cost[20][20], a = 0, u = 0, v = 0, b = 0, source, visited[20];

    
    printf("Enter the no. of nodes:");
    scanf("%d", &n);

    printf("\nEnter the cost matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);

    for (i = 1; i <= n; i++)
        visited[i] = 0;

    printf("\nEnter the root node:");
    scanf("%d", &source);
    visited[source] = 1;

    printf("\nMinimum cost spanning tree is\n");

    
    while (ne < n) {
        min = INT_MAX;

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    if (visited[i] != 0) {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        if (visited[v] == 0) {
            printf("\nEdge %d\t(%d->%d)=%d\n", ne++, a, b, min);
            min_cost = min_cost + min;
            visited[b] = 1;
        }

        cost[a][b] = cost[b][a] = INT_MAX;
    }

    printf("\nMinimum cost=%d\n", min_cost);

    return 0;
}