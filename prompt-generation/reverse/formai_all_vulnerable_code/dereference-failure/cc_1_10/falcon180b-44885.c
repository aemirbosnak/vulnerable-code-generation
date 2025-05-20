//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j, max = 0, min = 1000000;
    int *arr;
    clock_t start, end;
    double cpu_time_used;

    // Get size of array from user
    printf("Enter size of array: ");
    scanf("%d", &n);

    // Initialize array with random numbers
    arr = (int *) malloc(n * sizeof(int));
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 1000000;
    }

    // Find minimum and maximum values in array
    for (i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Print minimum and maximum values
    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);

    // Measure time taken to sort array
    start = clock();
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print time taken to sort array
    printf("Time taken to sort array: %lf seconds\n", cpu_time_used);

    return 0;
}