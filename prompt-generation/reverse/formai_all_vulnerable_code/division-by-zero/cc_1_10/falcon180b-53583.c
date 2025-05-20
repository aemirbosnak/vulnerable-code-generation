//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_RANGE 10000

void generate_array(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_RANGE;
    }
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void bucket_sort(int arr[], int size) {
    int *bucket = (int *)malloc(MAX_SIZE * sizeof(int));
    int range = MAX_RANGE / size;
    for (int i = 0; i < size; i++) {
        bucket[arr[i] / range]++;
    }
    int index = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < bucket[i]; j++) {
            arr[index++] = i * range + range;
        }
    }
    free(bucket);
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    generate_array(arr, size);
    printf("Original array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucket_sort(arr, size);
    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}