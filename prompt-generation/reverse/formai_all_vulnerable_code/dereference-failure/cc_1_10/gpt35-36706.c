//FormAI DATASET v1.0 Category: Benchmarking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of elements in the array
#define SIZE 1000000

// Define the number of times to run the benchmark
#define RUNS 5

// Define a custom data type for the array
typedef struct {
    int value;
    long long int timestamp;
} Data;

// Comparison function for sorting Data elements by value
int compare(const void *a, const void *b) {
    return ((Data*)a)->value - ((Data*)b)->value;
}

// Comparison function for searching Data elements by value
int search_compare(const void *a, const void *b) {
    return *(int*)a - ((Data*)b)->value;
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Allocate memory for the array
    Data *data = malloc(SIZE * sizeof(Data));

    // Fill the array with random data
    for (int i = 0; i < SIZE; i++) {
        data[i].value = rand();
        data[i].timestamp = 0;
    }

    // Sort the array using the qsort function
    clock_t sort_start = clock();
    qsort(data, SIZE, sizeof(Data), compare);
    clock_t sort_end = clock();

    // Search for a random value in the array using the bsearch function
    int search_value = rand();
    clock_t search_start = clock();
    Data *search_result = bsearch(&search_value, data, SIZE, sizeof(Data), search_compare);
    clock_t search_end = clock();

    // Print the benchmark results
    printf("Sorting time: %f seconds\n", (double)(sort_end - sort_start) / CLOCKS_PER_SEC);
    printf("Search time: %f seconds\n", (double)(search_end - search_start) / CLOCKS_PER_SEC);
    
    // Free the memory allocated for the data array
    free(data);

    return 0;
}