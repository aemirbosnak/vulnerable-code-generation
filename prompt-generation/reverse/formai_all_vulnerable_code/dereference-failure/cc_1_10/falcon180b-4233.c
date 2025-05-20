//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

void bucket_sort(int *arr, int size) {
    int *bucket = malloc(MAX_SIZE * sizeof(int));
    int bucket_size = MAX_SIZE;
    int i, j, k = 0;
    int min = arr[0];
    int max = arr[0];

    for (i = 0; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    for (i = 0; i < size; i++) {
        arr[i] = (arr[i] - min) * (MAX_SIZE / (max - min));
        k = arr[i];
        while (bucket[k]!= 0) {
            k = (k + 1) % MAX_SIZE;
        }
        bucket[k] = arr[i];
    }

    for (i = 0; i < size; i++) {
        arr[i] = 0;
    }

    for (i = 0; i < MAX_SIZE; i++) {
        if (bucket[i]!= 0) {
            arr[k++] = bucket[i];
        }
    }

    free(bucket);
}

void generate_array(int *arr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = malloc(size * sizeof(int));

    generate_array(arr, size);

    printf("Before sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    bucket_sort(arr, size);

    printf("\nAfter sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}