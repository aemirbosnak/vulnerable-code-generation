//FormAI DATASET v1.0 Category: Matrix operations ; Style: scientific
//EXAMPLE PROGRAM: Scientific Matrix Operations in C

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//function to read in elements of a matrix
void read_matrix(double **matrix, int rows, int cols, char* label) {
    int i,j;
    printf("Enter %s matrix elements:\n",label);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%s[%d][%d] = ",label,i,j);
            scanf("%lf",&matrix[i][j]);
        }
    }
    printf("\n");
}

//function to print out a matrix
void print_matrix(double **matrix, int rows, int cols) {
    int i,j;
    printf("Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%f ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//function to multiply two matrices A and B, resulting in C
double **matrix_multiply(double **A, int Arows, int Acols, double **B, int Brows, int Bcols)
{
    int i,j,k;
    double **C;
    C = (double **) malloc(Arows * sizeof(double *));
    for (i = 0; i < Arows; i++) {
        C[i] = (double*) malloc(Bcols * sizeof(double));
    }
    for (i = 0; i < Arows; i++) {
        for (j = 0; j < Bcols; j++) {
            C[i][j] = 0;
            for (k = 0; k < Acols; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

//function to perform a scalar operation on a matrix
double **scalar_operation(double **A, int rows, int cols, double scalar, char operation)
{
    int i,j;
    double **C;
    C = (double **) malloc(rows * sizeof(double *));
    for (i = 0; i < rows; i++) {
        C[i] = (double*) malloc(cols * sizeof(double));
    }
    if (operation == '+') {
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                C[i][j] = A[i][j] + scalar;
            }
        }
    }
    else if (operation == '-') {
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                C[i][j] = A[i][j] - scalar;
            }
        }
    }
    else if (operation == '*') {
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                C[i][j] = A[i][j] * scalar;
            }
        }
    }
    else if (operation == '/') {
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                C[i][j] = A[i][j] / scalar;
            }
        }
    }
    return C;
}

//function to perform the transpose of a matrix
double **matrix_transpose(double **A, int rows, int cols)
{
    int i,j;
    double **C;
    C = (double **) malloc(cols * sizeof(double *));
    for (i = 0; i < cols; i++) {
        C[i] = (double*) malloc(rows * sizeof(double));
    }
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            C[j][i] = A[i][j];
        }
    }
    return C;
}

int main() {
    int rowsA, colsA, rowsB, colsB;
    double **A, **B, **C, **D;
    printf("Enter number of rows for matrix A: ");
    scanf("%d",&rowsA);
    printf("Enter number of columns for matrix A: ");
    scanf("%d",&colsA);
    A = (double **) malloc(rowsA * sizeof(double *));
    int i;
    for (i = 0; i < rowsA; i++) {
        A[i] = (double*) malloc(colsA * sizeof(double));
    }
    read_matrix(A,rowsA,colsA,"A");

    printf("Enter number of rows for matrix B: ");
    scanf("%d",&rowsB);
    printf("Enter number of columns for matrix B: ");
    scanf("%d",&colsB);
    B = (double **) malloc(rowsB * sizeof(double *));
    for (i = 0; i < rowsB; i++) {
        B[i] = (double*) malloc(colsB * sizeof(double));
    }
    read_matrix(B,rowsB,colsB,"B");

    if (colsA == rowsB) {
        C = matrix_multiply(A,rowsA,colsA,B,rowsB,colsB);
        printf("Matrix A multiplied by Matrix B:\n");
        print_matrix(C,rowsA,colsB);
    }
    else {
        printf("Cannot multiply matrices A and B - column count of A does not match row count of B.\n");
    }

    double scalar;
    char operation;
    printf("Enter scalar: ");
    scanf("%lf",&scalar);
    printf("Enter operation (+, -, *, /): ");
    scanf(" %c",&operation);
    D = scalar_operation(A,rowsA,colsA,scalar,operation);
    printf("Matrix A after scalar operation %c %f:\n",operation,scalar);
    print_matrix(D,rowsA,colsA);

    double **At = matrix_transpose(A,rowsA,colsA);
    printf("Transpose of Matrix A:\n");
    print_matrix(At,colsA,rowsA);

    free(A);
    free(B);
    free(C);
    free(D);
    free(At);

    return 0;
}