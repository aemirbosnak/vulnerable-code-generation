//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Function to create a bucket of a specified size
void create_bucket(int* array, int size, int bucket_size) {
    for (int i = 0; i < size; i++) {
        array[i] = -1;
    }
    int* buckets = (int*) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        buckets[i] = 0;
    }
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (array[i]!= -1) {
            while (j < bucket_size && array[i] > buckets[j]) {
                j++;
            }
            buckets[j] = array[i];
        }
    }
}

// Function to sort the elements using bucket sort
void bucket_sort(int* array, int size) {
    int* buckets = (int*) malloc(size * sizeof(int));
    create_bucket(array, size, size);
    for (int i = 0; i < size; i++) {
        if (array[i]!= -1) {
            array[i] = buckets[array[i]];
            buckets[array[i]] = -1;
        }
    }
    free(buckets);
}

// Function to print the sorted array
void print_array(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[] = {10, 5, 4, 6, 8, 3, 7, 1, 2, 9};
    int size = sizeof(array) / sizeof(array[0]);
    bucket_sort(array, size);
    print_array(array, size);
    return 0;
}