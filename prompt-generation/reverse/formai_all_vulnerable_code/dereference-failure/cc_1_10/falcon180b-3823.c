//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

typedef struct {
    int *array;
    int size;
} Bucket;

void create_buckets(Bucket *buckets, int num_buckets, int max_value) {
    for (int i = 0; i < num_buckets; i++) {
        buckets[i].array = malloc(sizeof(int) * max_value);
        buckets[i].size = 0;
    }
}

void destroy_buckets(Bucket *buckets, int num_buckets) {
    for (int i = 0; i < num_buckets; i++) {
        free(buckets[i].array);
    }
}

void bucket_sort(int *array, int size, Bucket *buckets, int num_buckets, int max_value) {
    for (int i = 0; i < size; i++) {
        int bucket_index = array[i] * num_buckets / max_value;
        buckets[bucket_index].array[buckets[bucket_index].size++] = array[i];
    }

    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < buckets[i].size; j++) {
            array[index++] = buckets[i].array[j];
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *array = malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }

    Bucket buckets[10];
    create_buckets(buckets, 10, 100);

    clock_t start, end;
    start = clock();
    bucket_sort(array, size, buckets, 10, 100);
    end = clock();

    double time_taken = (double) (end - start) / CLOCKS_PER_SEC;

    printf("Array before sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    printf("\nArray after sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    printf("\nTime taken: %.2f seconds\n", time_taken);

    destroy_buckets(buckets, 10);
    free(array);

    return 0;
}