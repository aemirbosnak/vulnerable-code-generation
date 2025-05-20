//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000
#define RANGE 100

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bucketSort(int arr[], int n) {
    int i, j, bucket[MAX];
    for (i = 0; i < n; i++) {
        bucket[(arr[i] / RANGE) * RANGE]++;
    }
    for (i = 0; i < MAX; i++) {
        bucket[i] = 0;
    }
    for (i = 0; i < n; i++) {
        bucket[(arr[i] / RANGE) * RANGE]++;
    }
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < bucket[i]; j++) {
            arr[j * MAX + i] = i * RANGE;
        }
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int i, n, randNum;
    srand(time(NULL));
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        randNum = rand() % 1000;
        arr[i] = randNum;
        printf("%d ", randNum);
    }
    printf("\nBefore sorting:\n");
    printArray(arr, n);
    bucketSort(arr, n);
    printf("After sorting:\n");
    printArray(arr, n);
    return 0;
}