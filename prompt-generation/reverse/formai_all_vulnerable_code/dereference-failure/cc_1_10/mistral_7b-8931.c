//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

#define BUCKET_SIZE 10

typedef struct {
    int count;
    int *data;
} Bucket;

void print_array(const char *title, int *arr, size_t size) {
    printf("%s: ", title);
    for (size_t i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int hash_func(int key, int table_size) {
    return (key % table_size + table_size) % table_size;
}

void bucket_sort(int *arr, size_t size) {
    Bucket *table = malloc(sizeof(Bucket) * BUCKET_SIZE);

    for (int i = 0; i < BUCKET_SIZE; ++i) {
        table[i].count = 0;
        table[i].data = malloc(sizeof(int) * BUCKET_SIZE);
    }

    srand(time(NULL));

    for (size_t i = 0; i < size; ++i) {
        int index = hash_func(arr[i], BUCKET_SIZE);
        table[index].data[table[index].count++] = arr[i];
    }

    size_t counter = 0;
    for (int i = 0; i < BUCKET_SIZE; ++i) {
        for (int j = 0; j < table[i].count; ++j) {
            arr[counter++] = table[i].data[j];
        }
    }

    for (int i = 0; i < BUCKET_SIZE; ++i) {
        free(table[i].data);
    }
    free(table);
}

int main(int argc, char **argv) {
    int arr[] = { 4, 1, 5, 2, 3, 1, 6, 8, 7, 9 };
    size_t size = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array:\n");
    print_array("Unsorted array", arr, size);

    bucket_sort(arr, size);

    printf("Sorted array:\n");
    print_array("Sorted array", arr, size);

    return 0;
}