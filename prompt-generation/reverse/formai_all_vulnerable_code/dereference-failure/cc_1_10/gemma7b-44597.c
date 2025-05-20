//Gemma-7B DATASET v1.0 Category: Sorting ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int **arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (*(arr[i]) > *(arr[j])) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

int main() {
    int n = 5;
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        arr[i] = (int *)malloc(10 * sizeof(int));
    }

    arr[0][0] = 3;
    arr[0][1] = 1;
    arr[0][2] = 5;
    arr[0][3] = 4;
    arr[0][4] = 2;

    arr[1][0] = 2;
    arr[1][1] = 4;
    arr[1][2] = 1;
    arr[1][3] = 3;
    arr[1][4] = 6;

    sort(arr, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}