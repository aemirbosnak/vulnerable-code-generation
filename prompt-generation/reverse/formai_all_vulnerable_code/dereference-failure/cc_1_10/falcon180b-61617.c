//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_RANGE 1000000

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to get the index of the bucket for a given element
int get_bucket_index(int element, int range) {
    return element * range / MAX_RANGE;
}

// Function to sort an array using bucket sort
void bucket_sort(int *array, int size) {
    int i, j;
    int *bucket[MAX_SIZE];
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = malloc(sizeof(int) * size);
    }

    // Put elements in the buckets
    for (i = 0; i < size; i++) {
        int index = get_bucket_index(array[i], MAX_RANGE);
        bucket[index][i % MAX_SIZE] = array[i];
    }

    // Sort the buckets
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < size - 1; j++) {
            if (bucket[i][j] > bucket[i][j + 1]) {
                swap(&bucket[i][j], &bucket[i][j + 1]);
            }
        }
    }

    // Merge the sorted buckets
    int k = 0;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < size - 1; j++) {
            array[k++] = bucket[i][j];
        }
    }

    // Free the memory allocated for the buckets
    for (i = 0; i < MAX_SIZE; i++) {
        free(bucket[i]);
    }
}

// Function to generate a random array of integers
void generate_array(int *array, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % MAX_RANGE;
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *array = malloc(sizeof(int) * size);

    generate_array(array, size);

    printf("Before sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    bucket_sort(array, size);

    printf("\nAfter sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    free(array);

    return 0;
}