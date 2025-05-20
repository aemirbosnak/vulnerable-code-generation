//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
    int capacity;
    int count;
    int *bucket;
} Bucket;

void bucket_sort(int *arr, int size, int (*comparator)(int, int)) {
    Bucket *buckets = malloc(sizeof(Bucket) * 10);

    for (int i = 0; i < 10; i++) {
        buckets[i].capacity = 10;
        buckets[i].count = 0;
        buckets[i].bucket = malloc(sizeof(int) * buckets[i].capacity);
    }

    for (int i = 0; i < size; i++) {
        int index = (arr[i] % 10);
        if (buckets[index].count >= buckets[index].capacity) {
            buckets[index].capacity *= 2;
            buckets[index].bucket = realloc(buckets[index].bucket, sizeof(int) * buckets[index].capacity);
        }
        buckets[index].bucket[buckets[index].count++] = arr[i];
    }

    int sorted_index = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < buckets[i].count; j++) {
            int index = i;
            int element = buckets[i].bucket[j];
            for (int k = 0; k < sorted_index; k++) {
                if ((*comparator)(element, arr[sorted_index])) {
                    index = sorted_index;
                    break;
                }
                sorted_index++;
            }
            arr[sorted_index] = element;
        }
    }

    for (int i = 0; i < 10; i++) {
        free(buckets[i].bucket);
    }
    free(buckets);
}

int compare_numbers(int a, int b) {
    return a < b ? -1 : (a > b ? 1 : 0);
}

int main() {
    int arr[] = {3, 5, 2, 7, 1, 8, 4, 6};
    int size = ARRAY_SIZE(arr);

    printf("Unsorted array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    bucket_sort(arr, size, compare_numbers);

    printf("\nSorted array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}