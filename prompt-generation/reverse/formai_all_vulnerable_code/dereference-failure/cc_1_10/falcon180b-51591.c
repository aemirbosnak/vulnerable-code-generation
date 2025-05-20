//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers
int compare(const void *a, const void *b) {
    int x = *((int *) a);
    int y = *((int *) b);

    if (x < y)
        return -1;
    else if (x > y)
        return 1;
    else
        return 0;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        else if (arr[i] < min)
            min = arr[i];
    }

    int range = max - min + 1;
    int *bucket = (int *) malloc(range * sizeof(int));

    for (int i = 0; i < range; i++)
        bucket[i] = 0;

    for (int i = 0; i < n; i++) {
        bucket[arr[i] - min]++;
    }

    int index = 0;

    for (int i = 0; i < range; i++) {
        for (int j = 0; j < bucket[i]; j++) {
            arr[index++] = i + min;
        }
    }

    free(bucket);
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
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
    printArray(arr, n);

    return 0;
}