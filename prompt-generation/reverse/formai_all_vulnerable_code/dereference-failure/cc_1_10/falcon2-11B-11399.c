//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} Element;

int main() {
    // Create an array of elements
    Element arr[] = {
        {1, 10},
        {2, 20},
        {3, 30},
        {4, 40},
        {5, 50},
        {6, 60},
        {7, 70},
        {8, 80},
        {9, 90},
        {10, 100}
    };

    // Sort the elements
    int n = sizeof(arr) / sizeof(arr[0]);
    int *buckets = malloc(n * sizeof(int));
    Element *sorted_arr = malloc(n * sizeof(Element));
    int *bucket_indices = malloc(n * sizeof(int));

    // Initialize bucket indices
    for (int i = 0; i < n; i++) {
        bucket_indices[i] = 0;
    }

    // Calculate the number of buckets
    int num_buckets = (n + 1) / 10;

    // Divide the elements into buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = bucket_indices[arr[i].key / 10];
        bucket_indices[arr[i].key / 10]++;
        buckets[bucket_index] = buckets[bucket_index] + 1;
    }

    // Merge the sorted elements into the final array
    int j = 0;
    for (int i = 0; i < num_buckets; i++) {
        while (buckets[i] > 0) {
            sorted_arr[j].key = arr[j + i * 10].key;
            sorted_arr[j].value = arr[j + i * 10].value;
            j++;
            buckets[i]--;
        }
    }

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("Element %d: Key = %d, Value = %d\n", i, sorted_arr[i].key, sorted_arr[i].value);
    }

    free(sorted_arr);
    free(bucket_indices);
    free(buckets);

    return 0;
}