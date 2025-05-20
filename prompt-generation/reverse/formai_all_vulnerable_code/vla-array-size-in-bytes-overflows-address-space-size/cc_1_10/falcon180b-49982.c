//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to insert an element into the correct bucket
void insert(int arr[], int n, int key) {
    int i = 0;
    while (i < n && arr[i] < key)
        i++;
    swap(&arr[i], &arr[n]);
    n++;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int i, j;
    int* bucket[MAX_SIZE];

    // Initialize all buckets to empty
    for (i = 0; i < MAX_SIZE; i++)
        bucket[i] = NULL;

    // Insert elements into the correct bucket
    for (i = 0; i < n; i++) {
        int key = arr[i];
        int index = key % MAX_SIZE;
        if (bucket[index] == NULL) {
            bucket[index] = (int*) malloc(sizeof(int));
            *bucket[index] = key;
        } else {
            insert(bucket[index], *bucket[index], key);
        }
    }

    // Concatenate all sorted buckets
    i = 0;
    for (j = 0; j < MAX_SIZE; j++) {
        if (bucket[j]!= NULL) {
            int* temp = bucket[j];
            arr[i++] = *temp;
            free(temp);
        }
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

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}