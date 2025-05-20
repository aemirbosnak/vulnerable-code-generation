//FormAI DATASET v1.0 Category: Benchmarking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 500000
#define LOOP_SIZE 1000000

int main() {
    // Allocate memory for array
    int* arr = (int*)malloc(sizeof(int) * ARRAY_SIZE);
    
    // Fill array with random values
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;
    }
    
    // Perform Benchmarking
    double start, end;
    int sum = 0;
    
    // Measure time taken for a for loop
    start = clock();
    for (int i = 0; i < LOOP_SIZE; i++) {
        for (int j = 0; j < ARRAY_SIZE; j++) {
            sum += arr[j];
        }
    }
    end = clock();
    printf("For loop time: %f seconds\n", (end - start) / CLOCKS_PER_SEC);
    
    // Measure time taken for a while loop with pointers
    start = clock();
    int* ptr = arr;
    int counter = ARRAY_SIZE;
    while (counter--) {
        sum += (*ptr++);
    }
    for (int i = 0; i < LOOP_SIZE - 1; i++) {
        ptr = arr;
        counter = ARRAY_SIZE;
        while (counter--) {
            sum += (*ptr++);
        }
    }
    end = clock();
    printf("While loop with pointers time: %f seconds\n", (end - start) / CLOCKS_PER_SEC);
    
    // Measure time taken for a while loop with indexes
    start = clock();
    int index = 0;
    counter = ARRAY_SIZE;
    while (counter--) {
        sum += arr[index++];
    }
    for (int i = 0; i < LOOP_SIZE - 1; i++) {
        index = 0;
        counter = ARRAY_SIZE;
        while (counter--) {
            sum += arr[index++];
        }
    }
    end = clock();
    printf("While loop with indexes time: %f seconds\n", (end - start) / CLOCKS_PER_SEC);
    
    printf("Sum: %d", sum);
    
    // Free memory
    free(arr);
    return 0;
}