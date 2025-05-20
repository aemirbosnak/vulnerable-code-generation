//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of iterations for each experiment
#define NUM_ITERATIONS 1000

// Define the number of experiments to run
#define NUM_EXPERIMENTS 10

// Define the maximum size of the array to be sorted
#define MAX_ARRAY_SIZE 10000

// Define the function to be optimized
int sum_of_squares(int *array, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i] * array[i];
    }
    return sum;
}

// Define the function to generate a random array
int *generate_random_array(int size) {
    int *array = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
    return array;
}

// Define the function to run the experiment
void run_experiment(int size) {
    // Create an array of random numbers
    int *array = generate_random_array(size);

    // Calculate the sum of squares of the array
    int sum = sum_of_squares(array, size);

    // Print the results
    printf("Size: %d, Sum of squares: %d\n", size, sum);

    // Free the memory allocated for the array
    free(array);
}

// Define the main function
int main() {
    // Set the random seed
    srand(time(NULL));

    // Run the experiment for each size
    for (int i = 0; i < NUM_EXPERIMENTS; i++) {
        for (int size = 100; size <= MAX_ARRAY_SIZE; size *= 2) {
            run_experiment(size);
        }
    }

    return 0;
}