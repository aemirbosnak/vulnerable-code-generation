//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int arr[MAX_SIZE];
int buckets[MAX_SIZE];

void initialize_array(int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void print_array(int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int bucket_size = max / size + 1;
    for (int i = 0; i < size; i++) {
        buckets[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / bucket_size;
        buckets[bucket_index]++;
    }

    int index = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            arr[index++] = i * bucket_size + j;
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    initialize_array(size);
    printf("Unsorted array:\n");
    print_array(size);

    bucket_sort(size);
    printf("Sorted array:\n");
    print_array(size);

    return 0;
}