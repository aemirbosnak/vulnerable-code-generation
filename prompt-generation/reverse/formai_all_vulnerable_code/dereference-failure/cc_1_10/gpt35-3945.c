//FormAI DATASET v1.0 Category: Matrix operations ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>

void read_matrix(int**, int, int);
void display_matrix(int**, int, int);
void add_matrices(int**, int**, int, int);
void multiply_matrices(int**, int**, int**, int, int, int);
void transpose_matrix(int**, int**, int, int);

int main()
{
    int rows, cols;
    int **matrix1, **matrix2, **sum, **product, **transpose; 

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    matrix1 = (int**)malloc(rows*sizeof(int*));
    matrix2 = (int**)malloc(rows*sizeof(int*));
    sum = (int**)malloc(rows*sizeof(int*));
    product = (int**)malloc(rows*sizeof(int*));
    transpose = (int**)malloc(cols*sizeof(int*));

    for(int i=0; i<rows; i++)
    {
        matrix1[i] = (int*)malloc(cols*sizeof(int));
        matrix2[i] = (int*)malloc(cols*sizeof(int));
        sum[i] = (int*)malloc(cols*sizeof(int));
        product[i] = (int*)malloc(cols*sizeof(int));
    }

    for(int j=0; j<cols; j++)
    {
        transpose[j] = (int*)malloc(rows*sizeof(int));
    }

    printf("\nEnter elements of matrix1:\n");
    read_matrix(matrix1, rows, cols);

    printf("\nEnter elements of matrix2:\n");
    read_matrix(matrix2, rows, cols);

    printf("\nMatrix1:\n");
    display_matrix(matrix1, rows, cols);

    printf("\nMatrix2:\n");
    display_matrix(matrix2, rows, cols);

    add_matrices(matrix1, matrix2, rows, cols);
    multiply_matrices(matrix1, matrix2, product, rows, cols, cols);
    transpose_matrix(matrix1, transpose, rows, cols);

    printf("\nSum of Matrix1 and Matrix2:\n");
    display_matrix(sum, rows, cols);

    printf("\nProduct of Matrix1 and Matrix2:\n");
    display_matrix(product, rows, cols);

    printf("\nTranspose of Matrix1:\n");
    display_matrix(transpose, cols, rows);

    for(int i=0; i<rows; i++)
    {
        free(matrix1[i]);
        free(matrix2[i]);
        free(sum[i]);
        free(product[i]);
    }

    for(int j=0; j<cols; j++)
    {
        free(transpose[j]);
    }

    free(matrix1);
    free(matrix2);
    free(sum);
    free(product);
    free(transpose);

    return 0;
}

void read_matrix(int** matrix, int rows, int cols)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            scanf("%d", (*(matrix+i)+j));
        }
    }
}

void display_matrix(int** matrix, int rows, int cols)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            printf("%d\t", *(*(matrix+i)+j));
        }
        printf("\n");
    }
}

void add_matrices(int** matrix1, int** matrix2, int rows, int cols)
{
    int **sum;
    sum = (int**)malloc(rows*sizeof(int*));

    for(int i=0; i<rows; i++)
    {
        *(sum+i) = (int*)malloc(cols*sizeof(int));
    }

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            *(*(sum+i)+j) = *(*(matrix1+i)+j) + *(*(matrix2+i)+j);
        }
    }

    printf("\n");
    display_matrix(sum, rows, cols);
}

void multiply_matrices(int** matrix1, int** matrix2, int** product, int rows1, int cols1, int cols2)
{
    for(int i=0; i<rows1; i++)
    {
        for(int j=0; j<cols2; j++)
        {
            *(*(product+i)+j) = 0;
            for(int k=0; k<cols1; k++)
            {
                *(*(product+i)+j) += (*(*(matrix1+i)+k) * *(*(matrix2+k)+j));
            }
        }
    }
}

void transpose_matrix(int** matrix, int** transpose, int rows, int cols)
{
    for(int i=0; i<cols; i++)
    {
        for(int j=0; j<rows; j++)
        {
            *(*(transpose+i)+j) = *(*(matrix+j)+i);
        }
    }
}