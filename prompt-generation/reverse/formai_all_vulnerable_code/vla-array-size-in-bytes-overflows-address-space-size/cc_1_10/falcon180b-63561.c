//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum value in an array
int max(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to find the minimum value in an array
int min(int arr[], int n) {
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
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return max - min;
}

int main() {
    int n, m;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int max1 = max(arr, n);
    int min1 = min(arr, n);
    int maxDiff1 = maxDiff(arr, n);
    printf("The maximum value in the array is %d\n", max1);
    printf("The minimum value in the array is %d\n", min1);
    printf("The maximum difference between two elements in the array is %d\n", maxDiff1);
    return 0;
}