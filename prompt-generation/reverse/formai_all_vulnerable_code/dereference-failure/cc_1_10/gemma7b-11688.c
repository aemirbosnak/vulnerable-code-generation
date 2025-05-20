//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void matrix_operations(int **a, int **b)
{
    int i, j, k;
    int m = *a, n = *b, o = 0;

    // Allocate memory for the product matrix
    int **c = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++)
    {
        c[i] = (int *)malloc(n * sizeof(int));
    }

    // Perform the matrix multiplication
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < o; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Print the product matrix
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < m; i++)
    {
        free(c[i]);
    }
    free(c);
}

int main()
{
    int a_rows, a_cols, b_rows, b_cols;
    int **a, **b, **c;

    printf("Enter the number of rows for matrix A: ");
    scanf("%d", &a_rows);

    printf("Enter the number of columns for matrix A: ");
    scanf("%d", &a_cols);

    printf("Enter the number of rows for matrix B: ");
    scanf("%d", &b_rows);

    printf("Enter the number of columns for matrix B: ");
    scanf("%d", &b_cols);

    // Allocate memory for the matrices
    a = (int **)malloc(a_rows * sizeof(int *));
    for (int i = 0; i < a_rows; i++)
    {
        a[i] = (int *)malloc(a_cols * sizeof(int));
    }

    b = (int **)malloc(b_rows * sizeof(int *));
    for (int i = 0; i < b_rows; i++)
    {
        b[i] = (int *)malloc(b_cols * sizeof(int));
    }

    // Get the input for the matrices
    printf("Enter the elements of matrix A: ");
    for (int i = 0; i < a_rows; i++)
    {
        for (int j = 0; j < a_cols; j++)
        {
            scanf("%d ", &a[i][j]);
        }
    }

    printf("Enter the elements of matrix B: ");
    for (int i = 0; i < b_rows; i++)
    {
        for (int j = 0; j < b_cols; j++)
        {
            scanf("%d ", &b[i][j]);
        }
    }

    // Perform the matrix operations
    matrix_operations(&a, &b);

    // Free the memory
    for (int i = 0; i < a_rows; i++)
    {
        free(a[i]);
    }
    free(a);

    for (int i = 0; i < b_rows; i++)
    {
        free(b[i]);
    }
    free(b);

    return 0;
}