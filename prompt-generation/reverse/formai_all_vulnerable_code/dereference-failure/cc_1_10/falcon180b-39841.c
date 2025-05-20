//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define NUM_ITERATIONS 10

void generate_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void bubble_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int *arr = malloc(MAX_SIZE * sizeof(int));

    generate_array(arr, MAX_SIZE);

    double start_time = clock();
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        bubble_sort(arr, MAX_SIZE);
    }
    double end_time = clock();

    printf("Time taken: %lf seconds\n", (end_time - start_time) / CLOCKS_PER_SEC);

    print_array(arr, MAX_SIZE);

    free(arr);

    return 0;
}