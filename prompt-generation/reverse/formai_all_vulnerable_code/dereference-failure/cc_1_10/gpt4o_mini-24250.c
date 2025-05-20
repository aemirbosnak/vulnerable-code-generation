//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function prototypes
void investigate_benchmark(void (*func)(int), const char *func_name, int size);
void mystery_function(int size);
void another_mystery_function(int size);

int main() {
    int sizes[] = {1000, 10000, 100000};
    const char *function_names[] = {"mystery_function", "another_mystery_function"};
    
    for (int i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++) {
        printf("Investigating with array size: %d\n", sizes[i]);
        for (int j = 0; j < 2; j++) {
            investigate_benchmark((j == 0) ? mystery_function : another_mystery_function, function_names[j], sizes[i]);
        }
        printf("\n");
    }
    
    return 0;
}

// Function to benchmark another function
void investigate_benchmark(void (*func)(int), const char *func_name, int size) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    func(size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Function: %s for size: %d took %f seconds\n", func_name, size, cpu_time_used);
}

// A mysterious function that performs some calculation
void mystery_function(int size) {
    // Allocate a dynamic array to gather some data
    int *arr = (int*)malloc(size * sizeof(int));
    
    // Fill the array with values
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random values
    }
    
    // Sum the values of the array
    long long sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    
    // Introduce a slight delay to further add to the mystery
    for (volatile int i = 0; i < 100000; i++);
    
    free(arr); // Releasing the memory back to the system
}

// Another mysterious function that performs a different calculation
void another_mystery_function(int size) {
    // Allocate a dynamic array to gather some data
    int *arr = (int*)malloc(size * sizeof(int));
    
    // Fill the array with values
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random values
    }
    
    // Sort the array using bubble sort (a rather slow algorithm for mystery purposes)
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    free(arr); // Releasing the memory back to the system
}