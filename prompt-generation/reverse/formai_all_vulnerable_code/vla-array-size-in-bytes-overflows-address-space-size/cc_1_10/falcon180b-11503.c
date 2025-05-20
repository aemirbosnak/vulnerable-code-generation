//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE 100
#define MAX_SIZE 1000

void generate_array(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % RANGE;
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int arr[], int size) {
    int bucket[MAX_SIZE] = {0};
    int max_val = arr[0];
    int min_val = arr[0];

    for (int i = 0; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    int range = max_val - min_val + 1;
    int bucket_size = range / size;

    for (int i = 0; i < size; i++) {
        bucket[(arr[i] - min_val) / bucket_size]++;
    }

    int index = 0;
    for (int i = 0; i < size; i++) {
        while (bucket[(arr[i] - min_val) / bucket_size] > 0) {
            arr[index++] = arr[i];
            bucket[(arr[i] - min_val) / bucket_size]--;
        }
    }
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    if (size > MAX_SIZE) {
        printf("Array size is too large.\n");
        return 0;
    }

    generate_array(arr, size);
    printf("Unsorted array:\n");
    print_array(arr, size);

    bucket_sort(arr, size);
    printf("Sorted array:\n");
    print_array(arr, size);

    return 0;
}