#include <stdio.h>

#define MAX 100

int graph[6][6] = {
    {0, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 1, 1},
    {0, 1, 1, 1, 0, 1},
    {0, 0, 0, 1, 1, 0}
};

int visited[6] = {0};
int vertices = 6;

void DFS(int vertex) {
    int i;
    printf("Visited %d \n", vertex);
    visited[vertex] = 1;

    for (i = 0; i < vertices; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

void main() {
    printf("Depth First Search starting from vertex 0:\n");
    DFS(0);
}