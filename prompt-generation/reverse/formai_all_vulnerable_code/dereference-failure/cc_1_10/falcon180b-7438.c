//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum value of a given array
int max(int arr[], int n) {
    int max = arr[0];
    for(int i=1; i<n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to implement the greedy algorithm
void greedy(int arr[], int n) {
    int max_sum = 0;
    int sum = 0;

    // Initialize the first element as the maximum sum
    max_sum = max(arr, n);
    sum = max_sum;

    // Iterate through the array and add elements to the sum
    for(int i=1; i<n; i++) {
        if(arr[i] > 0) {
            sum += arr[i];
        } else {
            sum = 0;
        }
        max_sum = max(max_sum, sum);
    }

    printf("The maximum sum is %d\n", max_sum);
}

int main() {
    int arr[] = {2, 1, -3, 4, -5, 6, -7, 8, -9};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("The given array is: ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    greedy(arr, n);

    return 0;
}