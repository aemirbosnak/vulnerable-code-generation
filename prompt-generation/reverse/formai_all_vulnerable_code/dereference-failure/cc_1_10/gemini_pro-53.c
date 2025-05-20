//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int random_range(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to generate a random array of size n
int* generate_random_array(int n) {
    int* arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = random_range(0, 1000);
    }
    return arr;
}

// Function to sort an array of size n using bubble sort
void bubble_sort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to measure the time taken by bubble sort to sort an array of size n
double benchmark_bubble_sort(int n) {
    // Generate a random array of size n
    int* arr = generate_random_array(n);

    // Start the timer
    clock_t start = clock();

    // Sort the array using bubble sort
    bubble_sort(arr, n);

    // Stop the timer
    clock_t end = clock();

    // Calculate the time taken by bubble sort
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Free the memory allocated to the array
    free(arr);

    // Return the time taken by bubble sort
    return time_taken;
}

// Main function
int main() {
    // Array of sizes of arrays to be sorted
    int sizes[] = {10000, 20000, 30000, 40000, 50000};

    // Array to store the time taken by bubble sort for each size
    double times[5];

    // Measure the time taken by bubble sort for each size
    for (int i = 0; i < 5; i++) {
        times[i] = benchmark_bubble_sort(sizes[i]);
    }

    // Print the time taken by bubble sort for each size
    printf("Size\tTime (seconds)\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\t%f\n", sizes[i], times[i]);
    }

    return 0;
}