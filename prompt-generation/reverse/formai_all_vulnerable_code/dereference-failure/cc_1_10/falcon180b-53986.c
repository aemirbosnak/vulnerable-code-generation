//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the maximum sum of contiguous subarray in an array
int maxSubarraySum(int arr[], int n) {
    int max_sum = arr[0];
    int curr_sum = arr[0];

    // Traverse through the array
    for (int i = 1; i < n; i++) {
        // Check if adding the current element to the current sum will result in a negative sum
        if (curr_sum < 0) {
            curr_sum = arr[i];
        }
        // Update the maximum sum if the current sum is greater than the maximum sum
        else if (curr_sum > max_sum) {
            max_sum = curr_sum;
        }
        // Update the current sum by adding the current element to it
        curr_sum += arr[i];
    }

    // Return the maximum sum
    return max_sum;
}

// Main function
int main() {
    int n;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int* arr = (int*)malloc(n * sizeof(int));

    // Get the elements of the array from the user
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate the maximum sum of contiguous subarray in the array
    int max_sum = maxSubarraySum(arr, n);

    // Print the maximum sum
    printf("The maximum sum of contiguous subarray is: %d\n", max_sum);

    // Free the memory allocated for the array
    free(arr);

    return 0;
}