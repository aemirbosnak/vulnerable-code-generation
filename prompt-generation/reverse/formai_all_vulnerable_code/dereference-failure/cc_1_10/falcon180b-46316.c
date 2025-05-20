//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BUCKETS 10
#define MAX_ELEMENTS 1000

int *arr;
int n;
int buckets[MAX_BUCKETS];

void initialize_arr(int n) {
    arr = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
}

void initialize_buckets(int n) {
    for (int i = 0; i < MAX_BUCKETS; i++) {
        buckets[i] = 0;
    }
}

int get_bucket_index(int key) {
    return key % MAX_BUCKETS;
}

void insert_into_bucket(int key) {
    int index = get_bucket_index(key);
    buckets[index]++;
}

void count_sort(int n) {
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    for (int i = 0; i < MAX_BUCKETS; i++) {
        buckets[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int key = arr[i];
        int index = get_bucket_index(key);
        buckets[index]++;
    }

    for (int i = 1; i < MAX_BUCKETS; i++) {
        buckets[i] += buckets[i - 1];
    }

    int *sorted_arr = (int *) malloc(sizeof(int) * n);
    for (int i = n - 1; i >= 0; i--) {
        int key = arr[i];
        int index = get_bucket_index(key);
        sorted_arr[--buckets[index]] = key;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = sorted_arr[i];
    }

    free(sorted_arr);
}

void print_arr(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int n = MAX_ELEMENTS;
    initialize_arr(n);
    initialize_buckets(n);

    for (int i = 0; i < n; i++) {
        insert_into_bucket(arr[i]);
    }

    count_sort(n);
    print_arr(n);

    return 0;
}