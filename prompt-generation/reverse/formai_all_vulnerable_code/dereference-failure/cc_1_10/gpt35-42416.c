//FormAI DATASET v1.0 Category: Matrix operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void printMatrix(int **matrix, int rows, int cols);
void transpose(int **matrix, int rows, int cols);
void multiply(int **matrix1, int rows1, int cols1, int **matrix2, int rows2, int cols2);

int main()
{
    // create matrix A
    int rows1 = 3, cols1 = 2;
    int **matrix1 = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++)
    {
        matrix1[i] = (int *)malloc(cols1 * sizeof(int));
    }

    // initialize matrix A
    matrix1[0][0] = 1;
    matrix1[0][1] = 2;
    matrix1[1][0] = 3;
    matrix1[1][1] = 4;
    matrix1[2][0] = 5;
    matrix1[2][1] = 6;

    // create matrix B
    int rows2 = 2, cols2 = 3;
    int **matrix2 = (int **)malloc(rows2 * sizeof(int *));
    for (int i = 0; i < rows2; i++)
    {
        matrix2[i] = (int *)malloc(cols2 * sizeof(int));
    }

    // initialize matrix B
    matrix2[0][0] = 7;
    matrix2[0][1] = 8;
    matrix2[0][2] = 9;
    matrix2[1][0] = 10;
    matrix2[1][1] = 11;
    matrix2[1][2] = 12;

    // print matrix A
    printf("Matrix A:\n");
    printMatrix(matrix1, rows1, cols1);

    // transpose matrix A
    transpose(matrix1, rows1, cols1);

    // print transpose of matrix A
    printf("Transpose of matrix A:\n");
    printMatrix(matrix1, cols1, rows1);

    // print matrix B
    printf("Matrix B:\n");
    printMatrix(matrix2, rows2, cols2);

    // multiply matrix A and matrix B
    printf("Multiplication of matrix A and matrix B:\n");
    multiply(matrix1, cols1, rows1, matrix2, rows2, cols2);

    // free memory
    for (int i = 0; i < rows1; i++)
    {
        free(matrix1[i]);
    }
    free(matrix1);

    for (int i = 0; i < rows2; i++)
    {
        free(matrix2[i]);
    }
    free(matrix2);

    return 0;
}

/**
 * Function to print a matrix.
 * @param matrix: the matrix to print.
 * @param rows: the number of rows in the matrix.
 * @param cols: the number of columns in the matrix.
 */
void printMatrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/**
 * Function to transpose a matrix.
 * @param matrix: the matrix to transpose.
 * @param rows: the number of rows in the matrix.
 * @param cols: the number of columns in the matrix.
 */
void transpose(int **matrix, int rows, int cols)
{
    // create temporary matrix for transposed matrix
    int **temp = (int **)malloc(cols * sizeof(int *));
    for (int i = 0; i < cols; i++)
    {
        temp[i] = (int *)malloc(rows * sizeof(int));
    }

    // transpose matrix and store in temp
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            temp[j][i] = matrix[i][j];
        }
    }

    // copy temp to matrix
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            matrix[i][j] = temp[i][j];
        }
    }

    // free memory for temp
    for (int i = 0; i < cols; i++)
    {
        free(temp[i]);
    }
    free(temp);
}

/**
 * Function to multiply two matrices.
 * @param matrix1: the first matrix.
 * @param rows1: the number of rows in the first matrix.
 * @param cols1: the number of columns in the first matrix.
 * @param matrix2: the second matrix.
 * @param rows2: the number of rows in the second matrix.
 * @param cols2: the number of columns in the second matrix.
 */
void multiply(int **matrix1, int rows1, int cols1, int **matrix2, int rows2, int cols2)
{
    if (cols1 != rows2)
    {
        printf("Cannot multiply matrices.\n");
        return;
    }

    // create result matrix
    int **result = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++)
    {
        result[i] = (int *)malloc(cols2 * sizeof(int));
    }

    // multiply matrices and store in result
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            int sum = 0;
            for (int k = 0; k < cols1; k++)
            {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }

    // print result matrix
    printMatrix(result, rows1, cols2);

    // free memory for result
    for (int i = 0; i < rows1; i++)
    {
        free(result[i]);
    }
    free(result);
}