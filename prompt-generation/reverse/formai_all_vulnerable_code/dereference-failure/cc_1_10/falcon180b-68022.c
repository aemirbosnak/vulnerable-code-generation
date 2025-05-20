//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define INF 99999

// Function to find the minimum value in an array
int findMin(int arr[], int n) {
    int min = arr[0];
    for(int i=1; i<n; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Function to find the maximum value in an array
int findMax(int arr[], int n) {
    int max = arr[0];
    for(int i=1; i<n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int min = findMin(arr, n);
    int max = findMax(arr, n);
    int range = max - min + 1;
    int *bucket = (int *)malloc(range * sizeof(int));
    int *temp = (int *)malloc(n * sizeof(int));
    int i, j, k;

    // Initialize bucket
    for(i=0; i<range; i++) {
        bucket[i] = INF;
    }

    // Place elements in appropriate bucket
    for(i=0; i<n; i++) {
        j = arr[i] - min;
        bucket[j] = arr[i];
    }

    // Sort elements in each bucket
    for(i=0; i<range; i++) {
        if(bucket[i]!= INF) {
            arr[k] = bucket[i];
            k++;
        }
    }

    // Free memory
    free(bucket);
    free(temp);
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for(i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    bucketSort(arr, n);
    printf("Sorted array: ");
    for(i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}