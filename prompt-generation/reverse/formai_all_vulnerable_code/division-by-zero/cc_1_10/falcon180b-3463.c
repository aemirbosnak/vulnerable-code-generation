//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MIN_VALUE 0
#define MAX_VALUE 1000

void generate_random_array(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int arr[], int size) {
    int bucket_size = (MAX_VALUE - MIN_VALUE) / size + 1;
    int *buckets[size];

    for (int i = 0; i < size; i++) {
        buckets[i] = (int *) malloc(sizeof(int) * bucket_size);
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < bucket_size; j++) {
            buckets[i][j] = -1;
        }
    }

    for (int i = 0; i < size; i++) {
        int bucket_index = (arr[i] - MIN_VALUE) / bucket_size;
        buckets[bucket_index][arr[i] - MIN_VALUE - bucket_size * bucket_index] = i;
    }

    int index = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < bucket_size; j++) {
            if (buckets[i][j]!= -1) {
                arr[index++] = buckets[i][j];
            }
        }
    }

    for (int i = 0; i < size; i++) {
        free(buckets[i]);
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    generate_random_array(arr, size);
    print_array(arr, size);

    bucket_sort(arr, size);
    printf("Sorted array: ");
    print_array(arr, size);

    return 0;
}