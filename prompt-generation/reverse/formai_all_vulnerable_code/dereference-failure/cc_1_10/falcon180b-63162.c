//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum sum subarray
int maxSubArray(int arr[], int n) {
    int max_so_far = arr[0];
    int max_ending_here = arr[0];

    // Iterate through the array
    for (int i = 1; i < n; i++) {
        // If the current element is greater than the sum of the previous elements
        if (arr[i] > max_ending_here + arr[i - 1]) {
            // Update the maximum sum subarray
            max_ending_here = arr[i];
        } else {
            // Update the maximum sum subarray ending at the previous element
            max_ending_here += arr[i];
        }

        // Update the maximum sum subarray so far
        if (max_ending_here > max_so_far) {
            max_so_far = max_ending_here;
        }
    }

    return max_so_far;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory for the array dynamically
    int *arr = (int *) malloc(n * sizeof(int));

    // Get the elements of the array from the user
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find the maximum sum subarray
    int max_sum = maxSubArray(arr, n);

    // Print the maximum sum subarray
    printf("The maximum sum subarray is: ");
    for (int i = 0; i < n; i++) {
        if (max_sum > 0) {
            printf("%d ", arr[i]);
            max_sum -= arr[i];
        }
    }

    free(arr);
    return 0;
}