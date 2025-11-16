#include <stdio.h>
#include <conio.h>

void main() {
    float W[50], P[50], R[50], Totalvalue = 0, temp, capacity, amount;
    int n, i, j;

    printf("Enter the number of items :");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Weight and Profit for item[%d] :\n", i);
        scanf("%f %f", &W[i], &P[i]);
    }

    printf("Enter the capacity of knapsack :\n");
    scanf("%f", &capacity);

    for (i = 0; i < n; i++) {
        R[i] = P[i] / W[i];
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (R[i] < R[j]) {
                temp = R[j];
                R[j] = R[i];
                R[i] = temp;

                temp = W[j];
                W[j] = W[i];
                W[i] = temp;

                temp = P[j];
                P[j] = P[i];
                P[i] = temp;
            }
        }
    }

    printf("\nKnapsack problems using Greedy Algorithm:\n");

    for (i = 0; i < n; i++) {
        if (W[i] > capacity)
            break;
        else {
            Totalvalue = Totalvalue + P[i];
            capacity = capacity - W[i];
        }
    }

    if (i < n) {
        Totalvalue = Totalvalue + (R[i] * capacity);
    }

    printf("\nThe maximum value is: %f\n", Totalvalue);
}