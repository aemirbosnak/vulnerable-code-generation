//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j, max = 0;
    clock_t start, end;
    double cpu_time_used;

    // Get user input for array size
    printf("Enter array size: ");
    scanf("%d", &n);

    // Initialize array with random numbers
    int arr[n];
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    // Sort the array using bubble sort
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Measure the time taken to sort the array
    start = clock();
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print the sorted array and the time taken to sort it
    printf("\nSorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTime taken: %.2lf seconds\n", cpu_time_used);

    return 0;
}