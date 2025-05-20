//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum sum contiguous subarray
int maxSubArray(int arr[], int n) {
    int max_so_far = arr[0], max_ending_here = arr[0];

    for (int i = 1; i < n; i++) {
        max_ending_here += arr[i];

        if (max_ending_here > max_so_far) {
            max_so_far = max_ending_here;
        }

        if (max_ending_here < 0) {
            max_ending_here = 0;
        }
    }

    return max_so_far;
}

// Function to find the maximum sum contiguous subarray using greedy algorithm
int maxSubArrayGreedy(int arr[], int n) {
    int max_so_far = arr[0], max_ending_here = arr[0];

    for (int i = 1; i < n; i++) {
        max_ending_here += arr[i];

        if (max_ending_here > max_so_far) {
            max_so_far = max_ending_here;
        } else {
            max_ending_here = max_so_far;
        }
    }

    return max_so_far;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Using standard approach
    int max_sum = maxSubArray(arr, n);
    printf("Maximum sum contiguous subarray using standard approach is: %d\n", max_sum);

    // Using greedy approach
    int max_sum_greedy = maxSubArrayGreedy(arr, n);
    printf("Maximum sum contiguous subarray using greedy approach is: %d\n", max_sum_greedy);

    return 0;
}