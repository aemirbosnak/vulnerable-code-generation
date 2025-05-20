//FormAI DATASET v1.0 Category: Matrix operations ; Style: minimalist
#include <stdio.h>

/* Function declaration */
void printMatrix(int (*matrix)[3], int rows, int cols);
void multiplyMatrix(int (*matrix1)[2], int (*matrix2)[3], int rows, int cols);

int main()
{
    int row1 = 2, col1 = 2;
    int row2 = 2, col2 = 3;

    /* Matrix1 and Matrix2 Declaration */
    int matrix1[row1][col1], matrix2[row2][col2];

    /* Matrix1 values initialization*/
    matrix1[0][0] = 1;
    matrix1[0][1] = 2;
    matrix1[1][0] = 3;
    matrix1[1][1] = 4;

    /* Matrix2 values initialization*/
    matrix2[0][0] = 5;
    matrix2[0][1] = 6;
    matrix2[0][2] = 7;
    matrix2[1][0] = 8;
    matrix2[1][1] = 9;
    matrix2[1][2] = 10;

    printf("\nMatrix 1\n");
    printMatrix(matrix1, row1, col1);

    printf("\nMatrix 2\n");
    printMatrix(matrix2, row2, col2);

    printf("\nMatrix Multiplication\n");
    multiplyMatrix(matrix1, matrix2, row1, col2);

    return 0;
}

/* Function definition to print a matrix */
void printMatrix(int (*matrix)[3], int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

/* Function definition to multiply two matrices */
void multiplyMatrix(int (*matrix1)[2], int (*matrix2)[3], int rows, int cols)
{
    int i, j, k;
    int result[rows][cols];

    /* Initialize result matrix to 0 */
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            result[i][j] = 0;
        }
    }

    /* Multiply the matrices */
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            for (k = 0; k < 2; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    /* Print the result matrix */
    printMatrix(result, rows, cols);
}