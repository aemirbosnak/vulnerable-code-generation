//Gemma-7B DATASET v1.0 Category: Benchmarking ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE 1000

int main()
{
    int i, j, n, array_size, iterations;
    double start_time, end_time, total_time = 0.0;
    double *array;

    // Allocate memory for the array
    array = malloc(sizeof(double) * MAX_ARRAY_SIZE);

    // Get the number of iterations and array size from the user
    printf("Enter the number of iterations: ");
    scanf("%d", &iterations);

    printf("Enter the array size: ");
    scanf("%d", &array_size);

    // Fill the array with random numbers
    for (i = 0; i < array_size; i++)
    {
        array[i] = rand() % 1000;
    }

    // Start the timer
    start_time = clock() / CLOCKS_PER_SEC;

    // Perform the iterations
    for (j = 0; j < iterations; j++)
    {
        for (i = 0; i < array_size; i++)
        {
            array[i] = array[i] * 2;
        }
    }

    // Stop the timer
    end_time = clock() / CLOCKS_PER_SEC;

    // Calculate the total time
    total_time = end_time - start_time;

    // Print the total time
    printf("The total time taken is: %.2lf seconds\n", total_time);

    // Free the memory allocated for the array
    free(array);

    return 0;
}