//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000

int *bucket_sort(int *arr, int n) {
    int i, j, max_val = arr[0], min_val = arr[0], range, *bucket;
    int **count = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (i = 0; i < MAX_SIZE; i++) {
        count[i] = (int *)malloc(n * sizeof(int));
    }
    for (i = 0; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        } else if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }
    range = max_val - min_val + 1;
    for (i = 0; i < n; i++) {
        j = (arr[i] - min_val) / range * MAX_SIZE;
        count[j][count[j][0]++] = arr[i];
    }
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < count[i][0]; j++) {
            arr[j] = count[i][j];
        }
    }
    for (i = 0; i < MAX_SIZE; i++) {
        free(count[i]);
    }
    free(count);
    return arr;
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    arr = bucket_sort(arr, n);
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}