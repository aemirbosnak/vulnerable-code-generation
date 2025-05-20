//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define BUCKET_SIZE 10

typedef struct {
    int data;
    int index;
} bucket_t;

void create_buckets(bucket_t *buckets, int num_buckets) {
    for (int i = 0; i < num_buckets; i++) {
        buckets[i].data = -1;
        buckets[i].index = -1;
    }
}

void insert_into_bucket(bucket_t *buckets, int num_buckets, int data) {
    int index = data / BUCKET_SIZE;
    if (buckets[index].data == -1) {
        buckets[index].data = data;
        buckets[index].index = 0;
    } else {
        int j = 0;
        while (j < buckets[index].index && buckets[index].data < data) {
            j++;
        }
        buckets[index].index++;
        buckets[index].data = data;
    }
}

void sort_array(int *arr, int num_elements) {
    bucket_t *buckets = malloc(num_elements * sizeof(bucket_t));
    create_buckets(buckets, num_elements);

    for (int i = 0; i < num_elements; i++) {
        insert_into_bucket(buckets, num_elements, arr[i]);
    }

    int *sorted_arr = malloc(num_elements * sizeof(int));
    int j = 0;

    for (int i = 0; i < num_elements; i++) {
        if (buckets[i].data!= -1) {
            sorted_arr[j] = buckets[i].data;
            j++;
        }
    }

    free(buckets);
    memcpy(arr, sorted_arr, num_elements * sizeof(int));
    free(sorted_arr);
}

int main(int argc, char *argv[]) {
    int num_elements = 10;
    int *arr = malloc(num_elements * sizeof(int));

    for (int i = 0; i < num_elements; i++) {
        arr[i] = rand() % 100;
    }

    printf("Before sorting:\n");
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", arr[i]);
    }

    sort_array(arr, num_elements);

    printf("\nAfter sorting:\n");
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}