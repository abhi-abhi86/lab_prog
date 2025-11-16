#include <stdio.h>
#include <conio.h>

void main() {
    int a[50], n, i, j, t;
    clrscr();

    printf("Enter the Number of elements:\n");
    scanf("%d", &n);

    printf("Enter Elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 0; i < n - 1; i++)
        for(j = i + 1; j < n; j++)
            if(a[i] > a[j]) {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }

    printf("Sorted Elements:\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    getch();
}
