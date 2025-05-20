//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 100000

void fill_array(int *arr) {
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }
}

void print_array(int *arr) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int *arr;
    clock_t start, end;

    arr = (int *)calloc(SIZE, sizeof(int));

    // Set up the scene
    printf("\nWelcome to the immersive C benchmarking experience!\n");
    printf("You are about to witness the power of your computer as it processes a massive array of integers.\n");
    printf("The array contains %d integers, each one randomly filled with a value between 0 and 99.\n", SIZE);

    // Prepare the array
    fill_array(arr);

    // Begin the timer
    start = clock();

    // Perform the benchmarked operation
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += arr[i];
    }

    // Stop the timer
    end = clock();

    // Display the results
    printf("\nThe sum of all %d integers is: %d\n", SIZE, sum);
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("This calculation took %.2f seconds to complete.\n", duration);

    // Free the memory
    free(arr);

    return 0;
}