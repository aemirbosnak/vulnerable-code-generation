//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_VALUE 1000
#define MAX_BUCKETS 10

int *array;
int n;
int bucket_size;
int max_value;
int *buckets[MAX_BUCKETS];

void init_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_VALUE;
    }
}

void init_buckets(int *arr, int size) {
    for (int i = 0; i < MAX_BUCKETS; i++) {
        buckets[i] = malloc(size * sizeof(int));
    }
}

int get_bucket(int value) {
    return value / bucket_size;
}

void insert_bucket(int value, int index) {
    int bucket_index = get_bucket(value);
    int bucket_pos = 0;
    while (bucket_pos < index && buckets[bucket_index][bucket_pos] < value) {
        bucket_pos++;
    }
    for (int i = index; i > bucket_pos; i--) {
        buckets[bucket_index][i] = buckets[bucket_index][i-1];
    }
    buckets[bucket_index][bucket_pos] = value;
}

void bucket_sort() {
    for (int i = 0; i < n; i++) {
        int bucket_index = get_bucket(array[i]);
        insert_bucket(array[i], i);
    }
    int j = 0;
    for (int i = 0; i < MAX_BUCKETS; i++) {
        for (int k = 0; k < buckets[i][j]; k++) {
            array[k] = buckets[i][k];
            k++;
        }
        j++;
    }
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int size = MAX_SIZE;
    array = malloc(size * sizeof(int));
    n = size;
    bucket_size = MAX_VALUE / MAX_BUCKETS;
    max_value = MAX_VALUE;
    init_array(array, size);
    init_buckets(array, size);
    bucket_sort();
    print_array(array, size);
    return 0;
}