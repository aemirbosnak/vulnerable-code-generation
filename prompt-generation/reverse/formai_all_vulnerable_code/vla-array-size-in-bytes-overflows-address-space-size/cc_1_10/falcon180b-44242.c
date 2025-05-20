//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SIZE 1000000

void bucket_sort(int arr[], int n) {
    int i, j, k;
    int *bucket[MAX_SIZE];
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = (int *)malloc(sizeof(int) * n);
    }
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    for (i = 0; i < n; i++) {
        k = arr[i] * MAX_SIZE / 100;
        if (k == MAX_SIZE) {
            k--;
        }
        bucket[k] = (int *)realloc(bucket[k], sizeof(int) * (n + 1));
        bucket[k][n] = arr[i];
    }
    int index = 0;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < n; j++) {
            arr[index] = bucket[i][j];
            index++;
        }
    }
    for (i = 0; i < MAX_SIZE; i++) {
        free(bucket[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bucket_sort(arr, n);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}