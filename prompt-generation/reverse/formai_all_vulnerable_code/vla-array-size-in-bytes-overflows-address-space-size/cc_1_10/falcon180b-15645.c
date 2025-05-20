//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to find the maximum value of a given array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to find the minimum value of a given array
int findMin(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Function to find the maximum difference between two elements in an array
int maxDiff(int arr[], int n) {
    int max_diff = 0;
    int min_val = findMin(arr, n);
    for (int i = 0; i < n; i++) {
        int diff = arr[i] - min_val;
        if (diff > max_diff) {
            max_diff = diff;
        }
    }
    return max_diff;
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max_diff = maxDiff(arr, n);

    printf("The maximum difference between two elements in the array is %d\n", max_diff);

    return 0;
}