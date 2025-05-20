//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_VAL 1000000

int *create_array(int size) {
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_VAL;
    }
    return arr;
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int *arr, int size) {
    int *buckets = (int *)malloc(MAX_VAL * sizeof(int));
    for (int i = 0; i < MAX_VAL; i++) {
        buckets[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / (MAX_VAL / size);
        buckets[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i < MAX_VAL; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            arr[index++] = i * (MAX_VAL / size) + j;
        }
    }
}

int main() {
    srand(time(NULL));

    int size = MAX_SIZE;
    int *arr = create_array(size);

    printf("Before sorting:\n");
    print_array(arr, size);

    bucket_sort(arr, size);

    printf("After sorting:\n");
    print_array(arr, size);

    free(arr);
    return 0;
}