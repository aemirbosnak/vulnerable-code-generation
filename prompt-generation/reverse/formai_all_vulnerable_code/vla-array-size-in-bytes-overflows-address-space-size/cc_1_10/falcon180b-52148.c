//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

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

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = findMax(arr, n);
    int bucketSize = max / n;
    int* buckets[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / bucketSize;
        if (buckets[bucketIndex] == NULL) {
            buckets[bucketIndex] = malloc(sizeof(int));
            *buckets[bucketIndex] = arr[i];
        }
        else {
            int* temp = malloc(sizeof(int));
            *temp = arr[i];
            buckets[bucketIndex] = realloc(buckets[bucketIndex], sizeof(int) * 2);
            buckets[bucketIndex][0] = *temp;
            buckets[bucketIndex][1] = arr[i];
        }
    }
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (buckets[i]!= NULL) {
            for (int k = 0; k < 2; k++) {
                arr[j++] = buckets[i][k];
            }
            free(buckets[i]);
            buckets[i] = NULL;
        }
    }
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
    bucketSort(arr, n);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}