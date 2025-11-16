#include <stdio.h>
#include <limits.h>

#define N 4 

int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp(int graph[N][N], int mask, int pos) {
    int newMask, newCost, minCost, i;

    if (mask == (1 << N) - 1) {
        return graph[pos][0];
    }

    minCost = INT_MAX;

    for (i = 0; i < N; i++) {
        if ((mask & (1 << i)) == 0) {
            newMask = mask | (1 << i);
            newCost = graph[pos][i] + tsp(graph, newMask, i);
            minCost = min(minCost, newCost);
        }
    }

    return minCost;
}

int main() {
    int minCost, graph[N][N] = {
        {0, 2, 5, 7},
        {2, 0, 8, 3},
        {5, 8, 0, 1},
        {7, 3, 1, 0}
    };

    minCost = tsp(graph, 1, 0);

    printf("Minimum cost of the TSP: %d\n", minCost);

    return 0;
}