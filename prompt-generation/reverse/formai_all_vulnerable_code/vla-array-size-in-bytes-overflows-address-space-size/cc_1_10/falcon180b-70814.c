//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BUCKETS 10
#define MAX_VALUE 1000
#define MIN_VALUE 1

void generate_array(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_VALUE + MIN_VALUE;
    }
}

void bucket_sort(int arr[], int size) {
    int *buckets[NUM_BUCKETS];
    for (int i = 0; i < NUM_BUCKETS; i++) {
        buckets[i] = (int *) malloc(size * sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / (MAX_VALUE / NUM_BUCKETS);
        int *bucket = buckets[bucket_index];
        int j = 0;
        while (bucket[j]!= 0 && arr[i] > bucket[j]) {
            j++;
        }
        for (int k = size - 1; k > j; k--) {
            buckets[bucket_index][k] = buckets[bucket_index][k - 1];
        }
        buckets[bucket_index][j] = arr[i];
    }

    int index = 0;
    for (int i = 0; i < NUM_BUCKETS; i++) {
        for (int j = 0; j < size; j++) {
            if (buckets[i][j]!= 0) {
                arr[index++] = buckets[i][j];
            }
        }
    }

    for (int i = 0; i < NUM_BUCKETS; i++) {
        free(buckets[i]);
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    generate_array(arr, size);

    printf("Original array:\n");
    print_array(arr, size);

    bucket_sort(arr, size);

    printf("Sorted array:\n");
    print_array(arr, size);

    return 0;
}