//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_range(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

// Function to print a 2D array
void print_array(int **array, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main()
{
    // Initialize the random number generator
    srand(time(NULL));

    // Create a 2D array of size 10x10
    int **array = (int **)malloc(10 * sizeof(int *));
    for (int i = 0; i < 10; i++)
    {
        array[i] = (int *)malloc(10 * sizeof(int));
    }

    // Fill the array with random numbers between 0 and 9
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            array[i][j] = rand_range(0, 9);
        }
    }

    // Print the array
    printf("Original array:\n");
    print_array(array, 10, 10);

    // Find the sum of each row and column
    int row_sums[10];
    int col_sums[10];
    for (int i = 0; i < 10; i++)
    {
        row_sums[i] = 0;
        col_sums[i] = 0;
        for (int j = 0; j < 10; j++)
        {
            row_sums[i] += array[i][j];
            col_sums[i] += array[j][i];
        }
    }

    // Print the row and column sums
    printf("\nRow sums:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", row_sums[i]);
    }
    printf("\n\nColumn sums:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", col_sums[i]);
    }

    // Free the memory allocated for the array
    for (int i = 0; i < 10; i++)
    {
        free(array[i]);
    }
    free(array);

    return 0;
}