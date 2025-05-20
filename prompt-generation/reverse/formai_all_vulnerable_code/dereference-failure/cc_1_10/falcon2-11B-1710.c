//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a matrix
typedef struct matrix
{
    int rows;
    int cols;
    int* elements;
} matrix;

// Function to create a matrix of given size
matrix create_matrix(int rows, int cols)
{
    matrix matrix;

    matrix.rows = rows;
    matrix.cols = cols;

    matrix.elements = (int*)malloc(rows * cols * sizeof(int));

    return matrix;
}

// Function to print the matrix
void print_matrix(matrix matrix)
{
    int i, j;

    for (i = 0; i < matrix.rows; i++)
    {
        for (j = 0; j < matrix.cols; j++)
        {
            printf("%d ", matrix.elements[i * matrix.cols + j]);
        }
        printf("\n");
    }
}

// Function to calculate sum of all elements in the matrix
int calculate_sum(matrix matrix)
{
    int sum = 0;

    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.cols; j++)
        {
            sum += matrix.elements[i * matrix.cols + j];
        }
    }

    return sum;
}

int main()
{
    // Create a 3x3 matrix
    matrix matrix = create_matrix(3, 3);

    // Initialize matrix elements
    matrix.elements[0] = 1;
    matrix.elements[1] = 2;
    matrix.elements[2] = 3;
    matrix.elements[3] = 4;
    matrix.elements[4] = 5;
    matrix.elements[5] = 6;
    matrix.elements[6] = 7;
    matrix.elements[7] = 8;
    matrix.elements[8] = 9;

    // Print the matrix
    printf("Matrix:\n");
    print_matrix(matrix);

    // Calculate and print sum of all elements in the matrix
    int sum = calculate_sum(matrix);
    printf("Sum: %d\n", sum);

    return 0;
}