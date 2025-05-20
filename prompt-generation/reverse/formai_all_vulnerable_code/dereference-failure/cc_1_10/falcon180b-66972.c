//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000000

typedef struct {
    int data;
    int index;
} element_t;

void quick_sort(element_t arr[], int left, int right) {
    int i = left, j = right;
    element_t tmp;
    element_t pivot = arr[(left + right) / 2];

    /* partition */
    while (i <= j) {
        while (arr[i].data > pivot.data)
            i++;
        while (arr[j].data < pivot.data)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }

    /* recursion */
    if (left < j)
        quick_sort(arr, left, j);
    if (i < right)
        quick_sort(arr, i, right);
}

int main() {
    element_t arr[MAX_SIZE];
    int n, i;
    clock_t start, end;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        arr[i].data = rand() % 1000;
        arr[i].index = i;
    }

    start = clock();
    quick_sort(arr, 0, n - 1);
    end = clock();

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i].data);

    printf("\nTime taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}