//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000

int *generate_array(int size) {
    int *arr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_SIZE;
    }
    return arr;
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int *arr, int size, int max_val) {
    int *buckets = malloc(max_val * sizeof(int*));
    for (int i = 0; i < max_val; i++) {
        buckets[i] = NULL;
    }

    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / 10;
        int *bucket = buckets[bucket_index];
        if (bucket == NULL) {
            bucket = malloc(10 * sizeof(int));
            for (int j = 0; j < 10; j++) {
                bucket[j] = -1;
            }
            buckets[bucket_index] = bucket;
        }
        int *elem = malloc(sizeof(int));
        *elem = arr[i];
        int pos = 0;
        while (pos < 10 && bucket[pos]!= -1) {
            pos++;
        }
        bucket[pos] = elem;
    }

    int index = 0;
    for (int i = 0; i < max_val; i++) {
        int *bucket = buckets[i];
        if (bucket!= NULL) {
            for (int j = 0; j < 10; j++) {
                if (bucket[j]!= -1) {
                    arr[index++] = *(int*)bucket[j];
                }
            }
        }
    }

    for (int i = 0; i < max_val; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

int main() {
    srand(time(NULL));
    int size = rand() % MAX_SIZE + 1;
    int *arr = generate_array(size);
    print_array(arr, size);
    bucket_sort(arr, size, MAX_SIZE);
    print_array(arr, size);
    free(arr);
    return 0;
}