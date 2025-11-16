#include <stdio.h>
#include <stdlib.h> 

void bfs(int v);
int n, i, j, visited[10], q[10], f = -1, r = -1;
int a[10][10];

void main() {
    int v;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        q[i] = 0;
        visited[i] = 0;
    }

    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &v);

    q[++r] = v;
    visited[v] = 1; 

    bfs(v);

    printf("The node which are reachable are: \n");
    int all_visited = 1;
    for (i = 1; i <= n; i++) {
        if (visited[i]) {
            printf("%d\t", i);
        } else {
            all_visited = 0;
        }
    }
    printf("\n");

    if (!all_visited) {
         printf("!!! BFS is not possible. Not all nodes are reachable !!!!!!\n");
    }
}

void bfs(int v) {
    for (i = 1; i <= n; i++) {
        if (a[v][i] && !visited[i]) {
            q[++r] = i;
            visited[i] = 1; 
        }
    }
        
    if (f < r) { 
        f++;
        bfs(q[f]);
    }
}