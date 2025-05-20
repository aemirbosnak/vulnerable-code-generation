//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int rand_bucket(int n) {
    return rand() % n;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bucket_sort(int arr[], int n) {
    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int range = max - min + 1;
    int bucket_size = range / n;
    int* buckets = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        buckets[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int bucket_index = rand_bucket(n);
        while (buckets[bucket_index] == 0) {
            bucket_index = rand_bucket(n);
        }
        buckets[bucket_index]++;
        arr[i] = rand_int(min, max);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            printf("%d ", arr[i]);
        }
    }
    free(buckets);
}

int main() {
    srand(time(NULL));
    int n = rand() % MAX_SIZE + 1;
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % MAX_SIZE;
    }
    printf("Before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucket_sort(arr, n);
    printf("After sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}