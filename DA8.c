#include <stdio.h>
#include <conio.h>

void simple_merge(int a[], int low, int mid, int high);

void mergesort(int a[], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        simple_merge(a, low, mid, high);
    }
}

void simple_merge(int a[], int low, int mid, int high) {
    int i, j, k, c[20];
    k = low;
    i = low;
    j = mid + 1;

    while ((i <= mid) && (j <= high)) {
        if (a[i] < a[j])
            c[k++] = a[i++];
        else
            c[k++] = a[j++];
    }

    while (i <= mid)
        c[k++] = a[i++];
    while (j <= high)
        c[k++] = a[j++];

    for (i = low; i < k; i++) { 
        a[i] = c[i];
    }
}

void main() {
    int i, n, a[20];
    
    printf("enter the value for n: ");
    scanf("%d", &n);

    printf(" enter n values\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    mergesort(a, 0, n - 1);

    printf("the sorted array is \n");
    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);
}