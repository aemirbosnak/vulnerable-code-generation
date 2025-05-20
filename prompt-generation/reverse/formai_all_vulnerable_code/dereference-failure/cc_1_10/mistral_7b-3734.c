//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 100000

void fill_array(int *arr) {
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i;
    }
}

void print_array(int *arr) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int *arr;
    clock_t start, end;

    arr = (int *)malloc(SIZE * sizeof(int));

    start = clock();
    fill_array(arr);
    end = clock();

    printf("Filling the array took %.10fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    for (int i = 0; i < SIZE; i++) {
        // Perform a meaningless calculation to make it look like work is being done
        int sum = 0;
        for (int j = 0; j < 100; j++) {
            sum += arr[i] * j;
        }
    }
    end = clock();

    printf("Processing the array took %.10fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(arr);

    char *str = "A beautiful sunset over a tranquil lake.";
    start = clock();
    for (int i = 0; i < SIZE; i++) {
        strcat(str, str);
    }
    end = clock();

    printf("Concatenating strings %d times took %.10fs\n", SIZE, (double)(end - start) / CLOCKS_PER_SEC);

    printf("Array contents before freeing: ");
    print_array(arr);

    arr = NULL;

    start = clock();
    for (int i = 0; i < 1000; i++) {
        // Simulate garbage collection
        for (int j = 0; j < 100; j++) {
            // Do some random operations to make it look like work is being done
            int a = rand() % SIZE;
            int b = rand() % SIZE;
            arr[a] += arr[b];
        }
    }
    end = clock();

    printf("Garbage collection took %.10fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}