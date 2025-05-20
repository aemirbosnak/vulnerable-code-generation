//FormAI DATASET v1.0 Category: Matrix operations ; Style: ultraprecise
#include <stdio.h>

int main(){
    int rows, columns, i, j, num;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d%d", &rows, &columns);
    int A[rows][columns], B[rows][columns], C[rows][columns];

    printf("\nEnter the elements of matrix A:\n");

    //input matrix A
    for(i=0; i<rows; i++){
        for(j=0; j<columns; j++){
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nEnter the elements of matrix B:\n");

    //input matrix B
    for(i=0; i<rows; i++){
        for(j=0; j<columns; j++){
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    //display matrix A
    printf("\nMatrix A:\n");
    for(i=0; i<rows; i++){
        for(j=0; j<columns; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    //display matrix B
    printf("\nMatrix B:\n");
    for(i=0; i<rows; i++){
        for(j=0; j<columns; j++){
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    //Matrix Addition
    printf("\nMatrix A + B:\n");
    for(i=0; i<rows; i++){
        for(j=0; j<columns; j++){
            C[i][j] = A[i][j] + B[i][j];
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    //Matrix Subtraction
    printf("\nMatrix A - B:\n");
    for(i=0; i<rows; i++){
        for(j=0; j<columns; j++){
            C[i][j] = A[i][j] - B[i][j];
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    //Matrix Transpose
    printf("\nTranspose of matrix A:\n");
    for(i=0; i<rows; i++){
        for(j=0; j<columns; j++){
            printf("%d ", A[j][i]);
        }
        printf("\n");
    }

    return 0;
}