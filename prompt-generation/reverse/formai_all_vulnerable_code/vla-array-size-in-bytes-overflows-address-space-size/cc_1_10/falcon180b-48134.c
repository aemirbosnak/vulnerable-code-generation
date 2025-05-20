//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

void generateArray(int arr[], int size) {
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_SIZE;
    }
}

int compare(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

void bucketSort(int arr[], int size) {
    int *bucket[MAX_SIZE];

    for (int i = 0; i < MAX_SIZE; i++) {
        bucket[i] = malloc(sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        int index = arr[i] / 10;
        int value = arr[i] % 10;

        if (bucket[index] == NULL) {
            bucket[index] = malloc(sizeof(int));
        }

        int *ptr = bucket[index];
        while (*ptr!= -1) {
            ptr++;
        }

        *ptr = value;
    }

    int count = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        int *ptr = bucket[i];

        while (*ptr!= -1) {
            arr[count++] = *ptr;
            ptr++;
        }
    }
}

int main() {
    int size;

    printf("Enter the size of the array (maximum %d): ", MAX_SIZE);
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    generateArray(arr, size);

    printf("Before sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    qsort(arr, size, sizeof(int), compare);

    printf("\nAfter sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\n");

    bucketSort(arr, size);

    printf("After bucket sort:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}