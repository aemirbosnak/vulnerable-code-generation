//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10
#define BUCKET_SIZE 2

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void bucket_sort(int array[], int n) {
    int i, j, k;
    int min_value = array[0];
    int max_value = array[0];
    for (i = 1; i < n; i++) {
        if (array[i] < min_value) {
            min_value = array[i];
        }
        else if (array[i] > max_value) {
            max_value = array[i];
        }
    }

    int bucket_count = (max_value - min_value) / BUCKET_SIZE + 1;
    int** buckets = (int**)malloc(bucket_count * sizeof(int*));
    for (i = 0; i < bucket_count; i++) {
        buckets[i] = (int*)malloc(BUCKET_SIZE * sizeof(int));
    }

    for (i = 0; i < bucket_count; i++) {
        for (j = 0; j < BUCKET_SIZE; j++) {
            buckets[i][j] = 0;
        }
    }

    for (i = 0; i < n; i++) {
        int bucket_index = (array[i] - min_value) / BUCKET_SIZE;
        for (j = 0; j < BUCKET_SIZE; j++) {
            if (buckets[bucket_index][j] == 0) {
                buckets[bucket_index][j] = array[i];
                break;
            }
        }
    }

    int index = 0;
    for (i = 0; i < bucket_count; i++) {
        qsort(buckets[i], BUCKET_SIZE, sizeof(int), compare);
        for (j = 0; j < BUCKET_SIZE; j++) {
            if (buckets[i][j] != 0) {
                array[index++] = buckets[i][j];
            }
        }
    }

    for (i = 0; i < bucket_count; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

int main() {
    int arr[ARRAY_SIZE] = { 5, 6, 2, 1, 3, 9, 5, 8, 7, 4 };
    int i;
    printf("Before sorting: ");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }

    bucket_sort(arr, ARRAY_SIZE);

    printf("\nAfter sorting: ");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}