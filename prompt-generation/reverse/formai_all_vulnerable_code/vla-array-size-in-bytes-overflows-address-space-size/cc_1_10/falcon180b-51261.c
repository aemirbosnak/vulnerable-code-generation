//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define BUCKET_SIZE 10

void generate_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_SIZE;
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int arr[], int size) {
    int *buckets[BUCKET_SIZE];
    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = malloc(MAX_SIZE * sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / BUCKET_SIZE;
        int *bucket = buckets[bucket_index];
        int *ptr = bucket;
        while ((*ptr)!= -1) {
            ptr++;
        }
        *ptr = arr[i];
    }

    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        int *bucket = buckets[i];
        while (*bucket!= -1) {
            arr[index++] = *bucket++;
        }
    }

    for (int i = 0; i < BUCKET_SIZE; i++) {
        free(buckets[i]);
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    generate_array(arr, size);
    printf("Before sorting:\n");
    print_array(arr, size);

    clock_t start_time = clock();
    bucket_sort(arr, size);
    clock_t end_time = clock();

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("After sorting:\n");
    print_array(arr, size);
    printf("Elapsed time: %lf seconds\n", elapsed_time);

    return 0;
}