#include <stdio.h>
#include <limits.h>
#include <conio.h>
#include <string.h>

int sum(int freq[], int i, int j) {
    int s = 0, k;
    for (k = i; k <= j; k++)
        s += freq[k];
    return s;
}

int optimalBST(int keys[], int freq[], int i, int j, int dp[100][100]) {
    int r, cost;
    int minCost = INT_MAX;

    if (i > j)
        return 0;
    if (i == j)
        return freq[i];
    if (dp[i][j] != -1)
        return dp[i][j];

    int s = sum(freq, i, j);

    for (r = i; r <= j; r++) {
        cost = optimalBST(keys, freq, i, r - 1, dp) +
               optimalBST(keys, freq, r + 1, j, dp);

        if (cost < minCost)
            minCost = cost;
    }

    dp[i][j] = minCost + s;
    return dp[i][j];
}

int main() {
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n;
    int dp[100][100];
    int minOptimalCost;

    n = sizeof(keys) / sizeof(keys[0]);

    memset(dp, -1, sizeof(dp));

    minOptimalCost = optimalBST(keys, freq, 0, n - 1, dp);

    printf("Minimum cost of Optimal Binary Search Tree: %d\n", minOptimalCost);
    
    getch();
    return 0;
}