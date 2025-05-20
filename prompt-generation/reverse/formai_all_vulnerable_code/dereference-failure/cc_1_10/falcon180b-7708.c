//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUCKETS 100

typedef struct {
    int data;
    int index;
} Element;

void bucket_sort(Element* array, int count) {
    Element* buckets[MAX_BUCKETS] = {0};
    int bucket_counts[MAX_BUCKETS] = {0};
    int max_value = array[0].data;
    int min_value = array[0].data;

    // Find the maximum and minimum values in the array
    for (int i = 0; i < count; i++) {
        if (array[i].data > max_value) {
            max_value = array[i].data;
        }
        if (array[i].data < min_value) {
            min_value = array[i].data;
        }
    }

    // Calculate the range and bucket size
    int range = max_value - min_value;
    int bucket_size = range / MAX_BUCKETS;

    // Add each element to the appropriate bucket
    for (int i = 0; i < count; i++) {
        int bucket_index = (array[i].data - min_value) / bucket_size;
        buckets[bucket_index] = (void*)malloc(sizeof(Element));
        buckets[bucket_index]->data = array[i].data;
        buckets[bucket_index]->index = i;
        bucket_counts[bucket_index]++;
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < MAX_BUCKETS; i++) {
        if (buckets[i]!= NULL) {
            Element* temp = buckets[i];
            buckets[i] = NULL;
            int j;
            for (j = i - 1; j >= 0 && temp->data < buckets[j]->data; j--) {
                buckets[j + 1] = buckets[j];
            }
            buckets[j + 1] = temp;
        }
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < count; i++) {
        array[i].data = buckets[array[i].index]->data;
    }
}

int main() {
    Element array[10] = {{5}, {3}, {8}, {2}, {1}, {7}, {4}, {6}, {9}, {0}};
    int count = sizeof(array) / sizeof(array[0]);

    printf("Before sorting:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", array[i].data);
    }
    printf("\n");

    bucket_sort(array, count);

    printf("After sorting:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", array[i].data);
    }
    printf("\n");

    return 0;
}