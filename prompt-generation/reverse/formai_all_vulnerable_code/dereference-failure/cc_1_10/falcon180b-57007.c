//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to print the given array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to find the maximum value in the given array
int findMax(int arr[], int size) {
    int max = arr[0];
    int i;
    for (i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to apply the greedy algorithm for the given array and size
int greedyAlgorithm(int arr[], int size) {
    int i;
    int max = findMax(arr, size);
    int result = 0;
    for (i = 0; i < size; i++) {
        if (arr[i] == max) {
            result += arr[i];
        }
    }
    return result;
}

// Function to generate a random array of integers
void generateArray(int arr[], int size) {
    int i;
    srand(time(NULL));
    for (i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

// Main function
int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    generateArray(arr, size);
    int result = greedyAlgorithm(arr, size);
    printf("The maximum sum using the greedy algorithm is: %d\n", result);
    printArray(arr, size);
    return 0;
}