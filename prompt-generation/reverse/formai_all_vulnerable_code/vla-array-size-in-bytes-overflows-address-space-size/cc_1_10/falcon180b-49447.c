//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum sum subarray in a given array
int maxSubArray(int arr[], int n) {
    int max_so_far = arr[0], max_ending_here = arr[0];

    // Iterate through the array
    for (int i = 1; i < n; i++) {
        // Update max_ending_here
        max_ending_here += arr[i];

        // If max_ending_here becomes negative, reset it to 0
        if (max_ending_here < 0) {
            max_ending_here = 0;
        }

        // Update max_so_far if max_ending_here is greater
        if (max_ending_here > max_so_far) {
            max_so_far = max_ending_here;
        }
    }

    // Return the maximum sum
    return max_so_far;
}

int main() {
    int n;

    // Get the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Create an array of n elements
    int arr[n];

    // Get the elements of the array from the user
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find the maximum sum subarray in the given array
    int max_sum = maxSubArray(arr, n);

    // Print the maximum sum
    printf("The maximum sum subarray is: %d\n", max_sum);

    return 0;
}