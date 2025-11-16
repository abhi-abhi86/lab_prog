#include <stdio.h>
#include <conio.h> 

/* This program sorts an array of integers in ascending order
 * using the Selection Sort algorithm. */

void main() {
    int i, n, j, temp, a[10], pos;
    
    printf("Enter the number of elements\n");
    scanf("%d", &n);

    printf("Enter %d elements\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 0; i <= n - 2; i++) {
        pos = i;
        for (j = i + 1; j <= n - 1; j++) {
            if (a[j] < a[pos]) {
                pos = j;
            }
        }
        temp = a[i];
        a[i] = a[pos];
        a[pos] = temp;
    }

    printf("The Sorted elements are \n");
    for (i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
}