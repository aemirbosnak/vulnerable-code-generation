//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

/* Define the maximum number of elements that can be sorted */
#define MAX_ELEMENTS 100

/* Define the maximum value of each element */
#define MAX_VALUE 100

/* Define a structure to represent a bucket */
typedef struct bucket {
    int count;
    int* values;
} Bucket;

/* Define the bucket sort function */
void bucket_sort(int array[], int n) {
    /* Create the buckets */
    Bucket* buckets = (Bucket*) malloc(MAX_VALUE * sizeof(Bucket));
    int i, j, k;

    /* Initialize the buckets */
    for (i = 0; i < MAX_VALUE; i++) {
        buckets[i].count = 0;
        buckets[i].values = (int*) malloc(MAX_ELEMENTS * sizeof(int));
    }

    /* Add elements to the buckets */
    for (i = 0; i < n; i++) {
        int value = array[i];
        int bucket_index = value / 10;
        buckets[bucket_index].values[buckets[bucket_index].count++] = value;
    }

    /* Sort the elements in each bucket */
    for (i = 0; i < MAX_VALUE; i++) {
        /* Check if the bucket is empty */
        if (buckets[i].count == 0) {
            continue;
        }

        /* Sort the elements in the bucket using insertion sort */
        for (j = 1; j < buckets[i].count; j++) {
            int key = buckets[i].values[j];
            for (k = j - 1; k >= 0 && buckets[i].values[k] > key; k--) {
                buckets[i].values[k + 1] = buckets[i].values[k];
            }
            buckets[i].values[k + 1] = key;
        }
    }

    /* Copy the elements back into the original array */
    int index = 0;
    for (i = 0; i < MAX_VALUE; i++) {
        for (j = 0; j < buckets[i].count; j++) {
            array[index++] = buckets[i].values[j];
        }
    }

    /* Free the memory used by the buckets */
    for (i = 0; i < MAX_VALUE; i++) {
        free(buckets[i].values);
    }
    free(buckets);
}

/* Define a helper function to print an array */
void print_array(int array[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", array[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

/* Define a main function to test the bucket sort algorithm */
int main() {
    int array[] = {39, 77, 25, 50, 13, 78, 91, 98, 28, 85};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Original array: ");
    print_array(array, n);

    bucket_sort(array, n);

    printf("Sorted array: ");
    print_array(array, n);

    return 0;
}