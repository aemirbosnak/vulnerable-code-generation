//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random coin value
int getRandomCoinValue(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print the given array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to find the maximum value in the given array
int findMaxValue(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform the greedy algorithm
int performGreedyAlgorithm(int arr[], int size) {
    int max = findMaxValue(arr, size);
    int sum = 0;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == max) {
            sum += arr[i];
            count++;
        }
    }
    return sum;
}

// Main function
int main() {
    srand(time(NULL));
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        arr[i] = getRandomCoinValue(1, 100);
    }
    printf("The original array is:\n");
    printArray(arr, size);
    int sum = performGreedyAlgorithm(arr, size);
    printf("The sum of the elements in the array is: %d\n", sum);
    return 0;
}