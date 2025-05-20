//FormAI DATASET v1.0 Category: Matrix operations ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

void displayMatrix(int **matrix, int rows, int cols){
    printf("Matrix:\n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int **matrixA, int **matrixB, int **result, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void subtractMatrix(int **matrixA, int **matrixB, int **result, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

void multiplyMatrix(int **matrixA, int **matrixB, int **result, int rows1, int cols1, int cols2){
    for(int i=0; i<rows1; i++){
        for(int j=0; j<cols2; j++){
            result[i][j] = 0;
            for(int k=0; k<cols1; k++){
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int main(){
    int rows1, cols1, rows2, cols2;
    printf("Enter the dimensions of the first matrix:\n");
    scanf("%d%d", &rows1, &cols1);
    printf("Enter the dimensions of the second matrix:\n");
    scanf("%d%d", &rows2, &cols2);

    if(cols1 != rows2){
        printf("Cannot perform matrix multiplication.\n");
        return 0;
    }

    // Allocate memory for the matrices
    int **matrixA = (int **)malloc(rows1 * sizeof(int *));
    for(int i=0; i<rows1; i++){
        matrixA[i] = (int *)malloc(cols1 * sizeof(int));
    }

    int **matrixB = (int **)malloc(rows2 * sizeof(int *));
    for(int i=0; i<rows2; i++){
        matrixB[i] = (int *)malloc(cols2 * sizeof(int));
    }

    int **result = (int **)malloc(rows1 * sizeof(int *));
    for(int i=0; i<rows1; i++){
        result[i] = (int *)malloc(cols2 * sizeof(int));
    }

    // Read the input matrices
    printf("Enter the first matrix:\n");
    for(int i=0; i<rows1; i++){
        for(int j=0; j<cols1; j++){
            scanf("%d", &matrixA[i][j]);
        }
    }

    printf("Enter the second matrix:\n");
    for(int i=0; i<rows2; i++){
        for(int j=0; j<cols2; j++){
            scanf("%d", &matrixB[i][j]);
        }
    }

    // Display the input matrices
    displayMatrix(matrixA, rows1, cols1);
    displayMatrix(matrixB, rows2, cols2);

    // Add the matrices and display the result
    addMatrix(matrixA, matrixB, result, rows1, cols1);
    printf("After adding the matrices:\n");
    displayMatrix(result, rows1, cols1);

    // Subtract the matrices and display the result
    subtractMatrix(matrixA, matrixB, result, rows1, cols1);
    printf("After subtracting the matrices:\n");
    displayMatrix(result, rows1, cols1);

    // Multiply the matrices and display the result
    multiplyMatrix(matrixA, matrixB, result, rows1, cols1, cols2);
    printf("After multiplying the matrices:\n");
    displayMatrix(result, rows1, cols2);

    // Free the memory
    for(int i=0; i<rows1; i++){
        free(matrixA[i]);
    }
    free(matrixA);

    for(int i=0; i<rows2; i++){
        free(matrixB[i]);
    }
    free(matrixB);

    for(int i=0; i<rows1; i++){
        free(result[i]);
    }
    free(result);

    return 0;
}