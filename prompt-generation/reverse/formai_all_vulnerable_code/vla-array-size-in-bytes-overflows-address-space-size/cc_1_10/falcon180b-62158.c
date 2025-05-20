//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum sum of a subarray with given constraints
int maxSubarraySum(int arr[], int n, int k) {
    // Initialize variables
    int max_sum = 0, curr_sum = 0;

    // Loop through the array and calculate the maximum sum
    for (int i = 0; i < n; i++) {
        // Update the current sum
        curr_sum += arr[i];

        // If the current sum exceeds the maximum sum, update the maximum sum
        if (curr_sum > max_sum) {
            max_sum = curr_sum;
        }

        // If the current sum exceeds k, reset it to 0
        if (curr_sum > k) {
            curr_sum = 0;
        }
    }

    // Return the maximum sum
    return max_sum;
}

int main() {
    // Initialize variables
    int n, k;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the maximum sum constraint: ");
    scanf("%d", &k);

    // Declare the array and initialize it with random values
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    // Find the maximum sum of a subarray with given constraints
    int max_sum = maxSubarraySum(arr, n, k);

    // Print the maximum sum
    printf("The maximum sum of a subarray with given constraints is %d\n", max_sum);

    return 0;
}