//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

void generate_random_array(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }
}

void bucket_sort(int arr[], int n) {
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    int bucket_size = max_val / n;
    int *buckets = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        buckets[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int bucket_index = arr[i] / bucket_size;
        buckets[bucket_index]++;
    }

    int *sorted_arr = malloc(n * sizeof(int));
    int sorted_index = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            sorted_arr[sorted_index++] = arr[i];
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i] = sorted_arr[i];
    }

    free(buckets);
    free(sorted_arr);
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    generate_random_array(arr, n);

    printf("Unsorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucket_sort(arr, n);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}