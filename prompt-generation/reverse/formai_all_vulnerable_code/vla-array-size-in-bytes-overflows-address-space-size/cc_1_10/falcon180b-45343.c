//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucketSort(int arr[], int n) {
    int i, j;
    int bucket[MAX_SIZE] = {0};

    // Counting the number of elements in each bucket
    for (i = 0; i < n; i++) {
        int index = arr[i] * MAX_SIZE / (n - 1);
        bucket[index]++;
    }

    // Modify the counts to get the position of each element in the sorted array
    for (i = 1; i < MAX_SIZE; i++) {
        bucket[i] += bucket[i - 1];
    }

    // Place the elements in the correct bucket
    for (i = n - 1; i >= 0; i--) {
        int index = arr[i] * MAX_SIZE / (n - 1);
        bucket[index]--;
        arr[bucket[index]] = arr[i];
    }
}

int main() {
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}