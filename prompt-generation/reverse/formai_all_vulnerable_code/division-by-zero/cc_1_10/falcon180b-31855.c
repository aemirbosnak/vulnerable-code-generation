//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to perform bucket sort
void bucket_sort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int bucket_size = max / n;
    int **bucket = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        bucket[i] = (int *)malloc(bucket_size * sizeof(int));
        for (int j = 0; j < bucket_size; j++) {
            bucket[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        int j = arr[i] / bucket_size;
        bucket[j][arr[i] % bucket_size]++;
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucket_size; j++) {
            if (bucket[i][j] > 0) {
                arr[index++] = j * bucket_size + i * bucket_size;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
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