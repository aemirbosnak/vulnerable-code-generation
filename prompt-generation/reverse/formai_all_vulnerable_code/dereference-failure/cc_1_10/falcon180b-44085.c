//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000
#define MAX_VALUE 1000

int main() {
    int n;
    int *arr;
    int *buckets;
    int bucket_size;
    int max_value;
    int min_value;
    int i, j, k;

    // Get the number of elements to sort
    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);

    // Allocate memory for the array and the buckets
    arr = (int *)malloc(n * sizeof(int));
    buckets = (int *)malloc(MAX_SIZE * sizeof(int));

    // Get the range of the values to sort
    printf("Enter the minimum value: ");
    scanf("%d", &min_value);
    printf("Enter the maximum value: ");
    scanf("%d", &max_value);

    // Calculate the bucket size
    bucket_size = (max_value - min_value) / MAX_SIZE;

    // Initialize the array with random values
    for (i = 0; i < n; i++) {
        arr[i] = rand() % (max_value - min_value + 1) + min_value;
    }

    // Perform the bucket sort
    for (i = 0; i < n; i++) {
        j = (arr[i] - min_value) / bucket_size;
        buckets[j]++;
    }

    for (i = 0, k = 0; i < MAX_SIZE; i++) {
        if (buckets[i] > 0) {
            for (j = 0; j < buckets[i]; j++) {
                arr[k++] = i * bucket_size + min_value;
            }
        }
    }

    // Print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free memory
    free(arr);
    free(buckets);

    return 0;
}