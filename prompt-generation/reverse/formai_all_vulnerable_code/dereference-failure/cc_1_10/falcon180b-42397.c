//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int arr[], int size) {
    int max_val = arr[0];
    int min_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }
    int range = max_val - min_val + 1;
    int* buckets = (int*) malloc(range * sizeof(int));
    memset(buckets, 0, range * sizeof(int));
    for (int i = 0; i < size; i++) {
        int bucket_idx = (arr[i] - min_val) / (max_val - min_val + 1) * range;
        buckets[bucket_idx]++;
    }
    int j = 0;
    for (int i = 0; i < range; i++) {
        while (buckets[i] > 0) {
            arr[j++] = i * (max_val - min_val + 1) + min_val;
            buckets[i]--;
        }
    }
    free(buckets);
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[MAX_SIZE];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;
    }
    printf("Original array:\n");
    print_array(arr, size);
    bucket_sort(arr, size);
    printf("Sorted array:\n");
    print_array(arr, size);
    return 0;
}