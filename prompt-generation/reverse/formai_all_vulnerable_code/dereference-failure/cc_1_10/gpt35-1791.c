//FormAI DATASET v1.0 Category: Matrix operations ; Style: relaxed
#include <stdio.h>

/* Function to add two matrices element-wise */
void add_matrices(int n, int m, int matrix1[n][m], int matrix2[n][m], int result[n][m])
{
    for(int i=0; i < n; i++)
    {
        for(int j=0; j < m; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j]; // add corresponding elements
        }
    }
}

/* Function to multiply two matrices */
void multiply_matrices(int m, int n, int p, int matrix1[m][n], int matrix2[n][p], int result[m][p])
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<p; j++)
        {
            int sum = 0;
            for(int k=0; k<n; k++)
            {
                sum += matrix1[i][k] * matrix2[k][j]; // dot product of row of matrix1 and column of matrix2
            }
            result[i][j] = sum; // assign sum to result matrix
        }
    }
}

int main()
{
    int matrix1[2][3] = {{1, 2, 3},
                         {4, 5, 6}};

    int matrix2[2][3] = {{7, 8, 9},
                         {10, 11, 12}};

    int result[2][3];

    // add the two matrices
    add_matrices(2, 3, matrix1, matrix2, result);

    // display the resulting matrix
    printf("Addition of two matrices:\n");
    for(int i=0; i < 2; i++)
    {
        for(int j=0; j < 3; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    int matrix3[3][2] = {{1, 2},
                         {3, 4},
                         {5, 6}};

    int matrix4[2][4] = {{1, 2, 3, 4},
                         {5, 6, 7, 8}};

    int result2[3][4];

    // multiply the two matrices
    multiply_matrices(3, 2, 4, matrix3, matrix4, result2);

    // display the resulting matrix
    printf("\nMultiplication of two matrices:\n");
    for(int i=0; i < 3; i++)
    {
        for(int j=0; j < 4; j++)
        {
            printf("%d ", result2[i][j]);
        }
        printf("\n");
    }

    return 0;
}