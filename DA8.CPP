#include <stdio.h>
#include <conio.h>

/* This program represents a directed graph using an adjacency matrix.
 * It reads the number of nodes and edges from the user, builds the matrix,
 * and then calculates and displays the in-degree and out-degree of each node. */

#define MAX_NODES 10

int main() {
    int n, e, i, j, fromnode, tonode;
    int matrix[MAX_NODES][MAX_NODES];
    int indegree[MAX_NODES], outdegree[MAX_NODES];

    clrscr();

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    // Initialize arrays
    for (i = 0; i < n; i++) {
        indegree[i] = 0;
        outdegree[i] = 0;
        for (j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }

    // Read edges and build matrix
    for (i = 0; i < e; i++) {
        printf("Enter the edge %d: ", i + 1);
        scanf("%d %d", &fromnode, &tonode);
        matrix[fromnode][tonode] = 1;
        outdegree[fromnode]++;
        indegree[tonode]++;
    }

    // Print adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Print in-degree and out-degree
    printf("\nNode\tIndegree\tOutdegree\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", i, indegree[i], outdegree[i]);
    }

    getch();
    return 0;
}