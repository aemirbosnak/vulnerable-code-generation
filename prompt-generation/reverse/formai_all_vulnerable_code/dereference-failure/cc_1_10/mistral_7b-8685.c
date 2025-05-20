//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUCKETS 256
#define BUCKET_SIZE 32

typedef struct {
    int bottom;
    int top;
    int count;
    int data[BUCKET_SIZE];
} Bucket;

void print_int_array(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int arr[], int size) {
    int i, index;
    Bucket buckets[MAX_BUCKETS] = {0};

    for (i = 0; i < size; i++) {
        index = arr[i] / (BUCKET_SIZE / 2);
        buckets[index].count++;
    }

    for (i = 0; i < MAX_BUCKETS; i++) {
        if (buckets[i].count == 0) {
            continue;
        }

        for (int j = 0; j < buckets[i].count; j++) {
            int element = arr[index];
            arr[index] = arr[--size];
            arr[size] = element;

            index = arr[size] / (BUCKET_SIZE / 2);
        }

        for (int j = 0; j < BUCKET_SIZE / 2; j++) {
            if (buckets[i].top >= BUCKET_SIZE) {
                break;
            }

            if (buckets[i].count == 0) {
                break;
            }

            int element = buckets[i].data[buckets[i].bottom++];
            arr[--size] = element;
        }

        buckets[i].count = 0;
    }
}

int main() {
    int arr[] = {17, 24, 12, 230, 2, 8, 22, 35, 11, 14};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: \n");
    print_int_array(arr, size);

    bucket_sort(arr, size);

    printf("Sorted array: \n");
    print_int_array(arr, size);

    return 0;
}