//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum value in an array
int max_value(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to find the minimum value in an array
int min_value(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Function to find the maximum difference between any two elements in an array
int max_diff(int arr[], int n) {
    int max_diff = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int diff = arr[j] - arr[i];
            if (diff > max_diff) {
                max_diff = diff;
            }
        }
    }
    return max_diff;
}

// Function to find the maximum sum of any two elements in an array
int max_sum(int arr[], int n) {
    int max_sum = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            if (sum > max_sum) {
                max_sum = sum;
            }
        }
    }
    return max_sum;
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("The maximum value in the array is %d\n", max_value(arr, n));
    printf("The minimum value in the array is %d\n", min_value(arr, n));
    printf("The maximum difference between any two elements in the array is %d\n", max_diff(arr, n));
    printf("The maximum sum of any two elements in the array is %d\n", max_sum(arr, n));
    return 0;
}