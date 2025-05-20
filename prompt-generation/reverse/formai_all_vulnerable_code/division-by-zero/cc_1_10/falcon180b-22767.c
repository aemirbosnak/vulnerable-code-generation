//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000
#define RANGE 100

int main() {
    int arr[MAX_SIZE];
    int size;
    int sum = 0;
    int avg;
    int max = 0;
    int min = RANGE;
    int count = 0;

    // Prompt user for array size
    printf("Enter array size (up to %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Generate random array
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % RANGE;
    }

    // Calculate sum, average, max, and min
    for (int i = 0; i < size; i++) {
        sum += arr[i];
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    avg = sum / size;

    // Print results
    printf("Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", avg);
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
    printf("Count: %d\n", count);

    return 0;
}