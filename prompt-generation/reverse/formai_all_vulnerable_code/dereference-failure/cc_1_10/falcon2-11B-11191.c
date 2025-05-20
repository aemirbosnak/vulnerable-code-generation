//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int size = 10;
    int *arr;
    int i;
    int j;

    arr = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    printf("Memory game: match the pairs.\n");
    printf("Size of array: %d\n", size);
    printf("Array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (i = 0; i < size; i++) {
        j = rand() % size;
        while (arr[i] == arr[j]) {
            j = rand() % size;
        }
        arr[i] = arr[j];
        arr[j] = arr[i];
    }

    printf("Array after shuffling: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Memory game: match the pairs.\n");
    printf("Size of array: %d\n", size);
    printf("Array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (i = 0; i < size; i++) {
        j = rand() % size;
        while (arr[i] == arr[j]) {
            j = rand() % size;
        }
        arr[i] = arr[j];
        arr[j] = arr[i];
    }

    printf("Array after shuffling: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}