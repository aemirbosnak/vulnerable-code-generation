//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum value in an integer array
int max_value(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to find the minimum value in an integer array
int min_value(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Function to find the maximum difference between two values in an integer array
int max_diff(int arr[], int n) {
    int max_diff = 0;
    for (int i = 0; i < n - 1; i++) {
        int min_val = min_value(arr, n);
        int max_val = max_value(arr, n);
        if (max_val - min_val > max_diff) {
            max_diff = max_val - min_val;
        }
    }
    return max_diff;
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max_difference = max_diff(arr, n);

    printf("The maximum difference between any two values is: %d\n", max_difference);

    return 0;
}