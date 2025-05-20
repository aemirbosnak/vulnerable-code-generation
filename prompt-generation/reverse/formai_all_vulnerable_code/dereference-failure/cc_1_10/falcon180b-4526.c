//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000

int main() {
    int i, n, max, min, range;
    int *array;

    // Generate a random array of integers
    srand(time(NULL));
    n = rand() % MAX_SIZE + 1;
    array = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        array[i] = rand() % MAX_SIZE;
    }

    // Find the maximum and minimum values in the array
    max = array[0];
    min = array[0];
    for (i = 1; i < n; i++) {
        if (array[i] > max) {
            max = array[i];
        }
        if (array[i] < min) {
            min = array[i];
        }
    }

    range = max - min + 1;

    // Create the buckets
    int *buckets = (int *)malloc(range * sizeof(int));
    for (i = 0; i < range; i++) {
        buckets[i] = 0;
    }

    // Place the array elements in the appropriate buckets
    for (i = 0; i < n; i++) {
        int bucket = (array[i] - min) / range;
        buckets[bucket]++;
    }

    // Calculate the position of each element in the sorted array
    int pos = 0;
    for (i = 0; i < range; i++) {
        pos += buckets[i];
        buckets[i] = pos;
    }

    // Place the array elements in the sorted array
    for (i = n - 1; i >= 0; i--) {
        int bucket = (array[i] - min) / range;
        array[--buckets[bucket]] = array[i];
    }

    // Print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free the memory
    free(array);
    free(buckets);

    return 0;
}