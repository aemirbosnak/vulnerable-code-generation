//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

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

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int bucketSize = findMax(arr, n) / n;
    int *buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = malloc(bucketSize * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (arr[i] / bucketSize == j) {
            buckets[j][i] = arr[i];
            j++;
        }
    }
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (j < bucketSize) {
            if (buckets[i][j] == 0) {
                j++;
            } else {
                arr[j] = buckets[i][j];
                j++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        free(buckets[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    srand(time(0));
    for (int i = 0; i < n; i++) {
        swap(&arr[i], &arr[rand() % n]);
    }
    bucketSort(arr, n);
    printf("Sorted elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}