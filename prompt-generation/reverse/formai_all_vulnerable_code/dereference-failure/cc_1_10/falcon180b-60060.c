//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_RANGE 1000

void generate_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_RANGE;
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int arr[], int size) {
    int *bucket = (int *)malloc(MAX_RANGE * sizeof(int));
    int max_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    int bucket_size = max_val / MAX_RANGE;
    for (int i = 0; i < size; i++) {
        int index = arr[i] / bucket_size;
        bucket[index]++;
    }
    int j = 0;
    for (int i = 0; i < MAX_RANGE; i++) {
        for (int k = 0; k < bucket[i]; k++) {
            arr[j++] = i * MAX_RANGE + k;
        }
    }
    free(bucket);
}

int main() {
    srand(time(NULL));
    int size = rand() % MAX_SIZE + 1;
    int arr[size];
    generate_array(arr, size);
    printf("Unsorted array:\n");
    print_array(arr, size);
    bucket_sort(arr, size);
    printf("Sorted array:\n");
    print_array(arr, size);
    return 0;
}