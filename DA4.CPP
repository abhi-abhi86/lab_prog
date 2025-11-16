#include <stdio.h>
#include <stdlib.h> 

// Define a constant for the maximum number of vertices
#define MAX 10

/* --- BFS Functions --- */

// No recursive function needed, logic is now iterative in bfs_main

void bfs_main() {
    // All variables are now local to bfs_main
    int n, i, j, v;
    int visited[MAX];
    int q[MAX];
    int f = -1, r = -1; // Queue front and rear
    int a[MAX][MAX];

    printf("--- Breadth-First Search ---\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Initialize visited array and queue
    for (i = 1; i <= n; i++) {
        q[i] = 0;
        visited[i] = 0;
    }

    printf("Enter the adjacency matrix (1-based indexing):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &v);

    // Enqueue the starting vertex and mark as visited
    q[++r] = v;
    visited[v] = 1; 
    f = 0; // Set front pointer

    // --- Iterative BFS Logic ---
    // Replaces the old recursive function
    while (f <= r) {
        int u = q[f++]; // Dequeue vertex u
        
        // Find all adjacent vertices of u
        for (i = 1; i <= n; i++) {
            // If adjacent, not visited, and in the graph
            if (a[u][i] && !visited[i]) {
                q[++r] = i;         // Enqueue
                visited[i] = 1;     // Mark as visited
            }
        }
    }
    // --- End of Iterative BFS ---

    printf("The nodes reachable are: \n");
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
         printf("!!! Not all nodes are reachable !!!!!!\n");
    }
}


/* --- DFS Functions --- */

// DFS function now takes parameters instead of using globals
void DFS_recursive(int vertex, int n, int graph[MAX][MAX], int visited[MAX]) {
    int i;
    printf("Visited %d \n", vertex);
    visited[vertex] = 1;

    for (i = 1; i <= n; i++) { // Using 1-based indexing
        if (graph[vertex][i] == 1 && !visited[i]) {
            // Pass parameters in the recursive call
            DFS_recursive(i, n, graph, visited);
        }
    }
}

void dfs_main() {
    // All variables are now local to dfs_main
    int v, i, j, n;
    int graph[MAX][MAX];
    int visited[MAX];

    printf("--- Depth-First Search ---\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (1-based indexing):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    // Initialize visited array
    for (i = 1; i <= n; i++) {
        visited[i] = 0;
    }

    printf("Enter the starting vertex (1 to %d): ", n);
    scanf("%d", &v);

    printf("Depth First Search starting from vertex %d:\n", v);
    // Pass local variables as parameters
    DFS_recursive(v, n, graph, visited);
    
    printf("\n");
}


/* --- Main Menu --- */

void main() {
    int choice;
    printf("Graph Traversal Algorithms\n");
    printf("1. Breadth-First Search (BFS)\n");
    printf("2. Depth-First Search (DFS)\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            bfs_main();
            break;
        case 2:
            dfs_main();
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
}