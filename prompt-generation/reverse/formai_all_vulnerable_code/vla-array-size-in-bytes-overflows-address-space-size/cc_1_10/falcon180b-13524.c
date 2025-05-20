//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000

// Function to find the maximum element in an array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to sort an array using bucket sort
void bucketSort(int arr[], int n) {
    int max = findMax(arr, n);
    int range = max / n;
    int *bucket[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        int index = arr[i] / range;
        if (bucket[index] == NULL) {
            bucket[index] = (int *)malloc(sizeof(int) * (n / MAX_SIZE));
        }
        int *temp = realloc(bucket[index], sizeof(int) * (n / MAX_SIZE + 1));
        if (temp!= NULL) {
            bucket[index] = temp;
        }
        bucket[index][n / MAX_SIZE] = arr[i];
    }
    int j = 0;
    for (int i = 0; i < n; i++) {
        arr[i] = bucket[arr[i] / range][j++];
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bucketSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}