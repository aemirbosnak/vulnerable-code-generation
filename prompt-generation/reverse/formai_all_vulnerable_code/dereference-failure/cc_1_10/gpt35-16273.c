//FormAI DATASET v1.0 Category: Matrix operations ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define constants */
#define ROWS 3
#define COLS 3

/* Define function prototypes */
int **allocateMatrix();
void fillMatrix(int **matrix);
void printMatrix(int **matrix);
int **addMatrix(int **matrix1, int **matrix2);
int **subtractMatrix(int **matrix1, int **matrix2);
int **multiplyMatrix(int **matrix1, int **matrix2);
void freeMatrix(int **matrix);

/* Main function */
int main()
{
    /* Seed random number generator */
    srand(time(0));

    /* Allocate and fill matrices */
    int **matrix1 = allocateMatrix();
    fillMatrix(matrix1);
    int **matrix2 = allocateMatrix();
    fillMatrix(matrix2);

    /* Print initial matrices */
    printf("Matrix 1:\n");
    printMatrix(matrix1);
    printf("\nMatrix 2:\n");
    printMatrix(matrix2);

    /* Add matrices */
    int **sum = addMatrix(matrix1, matrix2);
    printf("\nMatrix Sum:\n");
    printMatrix(sum);

    /* Subtract matrices */
    int **difference = subtractMatrix(matrix1, matrix2);
    printf("\nMatrix Difference:\n");
    printMatrix(difference);

    /* Multiply matrices */
    int **product = multiplyMatrix(matrix1, matrix2);
    printf("\nMatrix Product:\n");
    printMatrix(product);

    /* Free memory */
    freeMatrix(matrix1);
    freeMatrix(matrix2);
    freeMatrix(sum);
    freeMatrix(difference);
    freeMatrix(product);

    return 0;
}

/* Function to allocate memory for matrices */
int **allocateMatrix()
{
    /* Allocate memory for pointers to rows */
    int **matrix = (int **)malloc(ROWS * sizeof(int *));
    if (matrix == NULL)
    {
        printf("Error allocating memory!\n");
        exit(1);
    }

    /* Allocate memory for columns in each row */
    int i;
    for (i = 0; i < ROWS; i++)
    {
        matrix[i] = (int *)malloc(COLS * sizeof(int));
        if (matrix[i] == NULL)
        {
            printf("Error allocating memory!\n");
            exit(1);
        }
    }

    return matrix;
}

/* Function to fill matrices with random numbers */
void fillMatrix(int **matrix)
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            matrix[i][j] = rand() % 10;
        }
    }
}

/* Function to print matrices */
void printMatrix(int **matrix)
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/* Function to add matrices */
int **addMatrix(int **matrix1, int **matrix2)
{
    /* Allocate memory for sum matrix */
    int **sum = allocateMatrix();

    /* Add corresponding elements */
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return sum;
}

/* Function to subtract matrices */
int **subtractMatrix(int **matrix1, int **matrix2)
{
    /* Allocate memory for difference matrix */
    int **difference = allocateMatrix();

    /* Subtract corresponding elements */
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            difference[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    return difference;
}

/* Function to multiply matrices */
int **multiplyMatrix(int **matrix1, int **matrix2)
{
    /* Allocate memory for product matrix */
    int **product = allocateMatrix();

    /* Multiply matrices using nested loops */
    int i, j, k;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            product[i][j] = 0;
            for (k = 0; k < COLS; k++)
            {
                product[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return product;
}

/* Function to free memory allocated for matrices */
void freeMatrix(int **matrix)
{
    int i;
    for (i = 0; i < ROWS; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}