//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

void generate_random_array(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_SIZE;
    }
}

void bucket_sort(int arr[], int size) {
    int num_buckets = size / 10;
    int bucket_size = size / num_buckets;
    int *buckets[num_buckets];

    for (int i = 0; i < num_buckets; i++) {
        buckets[i] = (int *) malloc(bucket_size * sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / bucket_size;
        int bucket_offset = arr[i] % bucket_size;
        buckets[bucket_index][bucket_offset] = arr[i];
    }

    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < bucket_size; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    for (int i = 0; i < num_buckets; i++) {
        free(buckets[i]);
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    generate_random_array(arr, size);

    printf("Original array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, size);

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}