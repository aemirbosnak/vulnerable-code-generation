//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Define the shape-shifter function that will be applied 
// to each element of the input array before they are sorted
int shape_shift(int num) {
    int new_num = 0;
    while (num > 0) {
        int digit = num % 10;
        new_num = (new_num * 10) + digit;
        num /= 10;
    }
    return new_num;
}

// Define the bucket sort function
void bucket_sort(int *arr, int n) {
    int i, j;

    // Find the maximum element in the array
    int max = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Create buckets for each digit place value
    int **buckets = (int **) malloc(sizeof(int *) * 10);
    for (i = 0; i < 10; i++) {
        buckets[i] = (int *) malloc(sizeof(int) * n);
        for (j = 0; j < n; j++) {
            buckets[i][j] = 0;
        }
    }

    // Distribute the elements of the array among the buckets
    int divisor = 1;
    while (max / divisor > 0) {
        for (i = 0; i < n; i++) {
            int shapeshifted = shape_shift(arr[i]);
            int digit = (shapeshifted / divisor) % 10;
            buckets[digit][i] = arr[i];
        }

        // Reorder the elements in the array based on the contents of the buckets
        int k = 0;
        for (i = 0; i < 10; i++) {
            for (j = 0; j < n; j++) {
                if (buckets[i][j] != 0) {
                    arr[k++] = buckets[i][j];
                }
            }
        }

        // Clear the contents of the buckets for the next pass
        for (i = 0; i < 10; i++) {
            for (j = 0; j < n; j++) {
                buckets[i][j] = 0;
            }
        }

        // Increase the divisor to sort by the next digit place value
        divisor *= 10;
    }

    // Free the allocated space for the buckets
    for (i = 0; i < 10; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

// Test the bucket sort function
int main() {
    int arr[] = {101, 231, 302, 421, 574, 678, 712, 839, 989};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    printf("Original array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Apply the shape-shifting transformation to the input array
    for (i = 0; i < n; i++) {
        arr[i] = shape_shift(arr[i]);
    }

    bucket_sort(arr, n);

    // Apply the shape-shifting transformation again to restore the original order of the sorted elements
    for (i = 0; i < n; i++) {
        arr[i] = shape_shift(arr[i]);
    }

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}