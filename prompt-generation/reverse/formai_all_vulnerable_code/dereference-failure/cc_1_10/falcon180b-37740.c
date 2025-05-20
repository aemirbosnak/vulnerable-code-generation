//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum value in an array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to find the minimum value in an array
int findMin(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Function to implement the greedy algorithm
int greedyAlgorithm(int arr[], int n) {
    int max = findMax(arr, n);
    int min = findMin(arr, n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == max) {
            sum += max;
        } else if (arr[i] == min) {
            sum += min;
        }
    }
    return sum;
}

// Main function
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int result = greedyAlgorithm(arr, n);
    printf("The sum of the maximum and minimum elements is: %d", result);
    return 0;
}