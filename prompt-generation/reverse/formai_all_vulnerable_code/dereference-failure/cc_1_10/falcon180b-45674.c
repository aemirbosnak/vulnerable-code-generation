//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int *generate_random_array(int size) {
    int *arr = (int*) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
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
    int *buckets = (int*) malloc(MAX_SIZE * sizeof(int));
    int max_value = arr[0];
    int min_value = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
        if (arr[i] < min_value) {
            min_value = arr[i];
        }
    }

    int bucket_size = (max_value - min_value) / size;
    int num_buckets = MAX_SIZE / bucket_size;

    for (int i = 0; i < size; i++) {
        int bucket_index = (arr[i] - min_value) / bucket_size;
        if (bucket_index >= num_buckets) {
            bucket_index = num_buckets - 1;
        }
        buckets[bucket_index]++;
    }

    int current_index = 0;
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            arr[current_index++] = min_value + i * bucket_size;
        }
    }

    free(buckets);
}

int main() {
    srand(time(0));
    int size = rand() % MAX_SIZE + 1;
    int *arr = generate_random_array(size);

    printf("Random array:\n");
    print_array(arr, size);

    bucket_sort(arr, size);

    printf("Sorted array:\n");
    print_array(arr, size);

    free(arr);
    return 0;
}