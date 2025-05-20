//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

void bucket_sort(int arr[], int n) {
    int i, j;
    int *bucket[MAX_SIZE];

    // Initialize all buckets to empty
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = NULL;
    }

    // Place each element in the correct bucket
    for (i = 0; i < n; i++) {
        j = arr[i] * MAX_SIZE / (n - 1);
        if (bucket[j] == NULL) {
            bucket[j] = (int *) malloc(sizeof(int));
        }
        int *temp = (int *) realloc(bucket[j], sizeof(int) * (++bucket[j][0]));
        bucket[j] = temp;
        bucket[j][bucket[j][0]] = arr[i];
    }

    // Concatenate all the buckets
    int index = 0;
    for (i = 0; i < MAX_SIZE; i++) {
        if (bucket[i]!= NULL) {
            for (j = 0; j < bucket[i][0]; j++) {
                arr[index++] = bucket[i][j];
            }
        }
    }
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    clock_t start = clock();
    bucket_sort(arr, n);
    clock_t end = clock();

    double time_taken = (double) (end - start) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Time taken: %.6f seconds\n", time_taken);

    return 0;
}