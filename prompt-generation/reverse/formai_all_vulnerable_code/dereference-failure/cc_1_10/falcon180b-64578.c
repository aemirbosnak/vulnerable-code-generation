//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 1000000
#define MAX_NUM 1000000

int *arr;
int size;

void init(int _size) {
    size = _size;
    arr = (int *) malloc(size * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_NUM;
    }
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bucket_sort(int *arr, int size) {
    int *bucket = (int *) malloc(MAX_NUM * sizeof(int));
    memset(bucket, 0, MAX_NUM * sizeof(int));

    for (int i = 0; i < size; i++) {
        int num = arr[i];
        int index = num / (MAX_NUM / size);
        bucket[index]++;
    }

    int index = 0;
    for (int i = 0; i < size; i++) {
        int num = arr[i];
        int bucket_index = num / (MAX_NUM / size);
        while (bucket[bucket_index] > 0) {
            arr[index++] = num;
            bucket[bucket_index]--;
        }
    }
}

int main() {
    init(MAX_SIZE);

    printf("Before Sorting:\n");
    print_array(arr, size);

    bucket_sort(arr, size);

    printf("After Sorting:\n");
    print_array(arr, size);

    return 0;
}