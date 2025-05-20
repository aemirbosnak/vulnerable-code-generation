//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000
#define MAX_VALUE 1000

int main() {
    int size;
    int *arr;
    int sum = 0;
    double avg;
    int i;

    // Prompt user for array size
    printf("Enter array size (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Validate array size
    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid array size.\n");
        return 1;
    }

    // Allocate memory for array
    arr = (int *)malloc(size * sizeof(int));

    // Prompt user for array elements
    printf("Enter array elements:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    // Calculate average
    avg = (double)sum / size;

    // Print array and average
    printf("\nArray: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nAverage: %.2f\n", avg);

    // Free memory
    free(arr);

    return 0;
}