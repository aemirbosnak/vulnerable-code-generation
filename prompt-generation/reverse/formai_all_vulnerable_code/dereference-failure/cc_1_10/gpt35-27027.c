//FormAI DATASET v1.0 Category: Matrix operations ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMatrix(int** matrix, int row, int col);
void addMatrix(int** matrixA, int** matrixB, int** result, int row, int col);
void multiplyMatrix(int** matrixA, int** matrixB, int** result, int rowA, int colA, int rowB, int colB);

int main(){
    srand(time(NULL));
    int rowA = 3, colA = 3, rowB = 3, colB = 3;
    int** matrixA = (int**)malloc(rowA*sizeof(int*));
    int** matrixB = (int**)malloc(rowB*sizeof(int*));
    int** result = (int**)malloc(rowA*sizeof(int*));

    for(int i=0; i<rowA; i++){
        matrixA[i] = (int*)malloc(colA*sizeof(int));
        matrixB[i] = (int*)malloc(colB*sizeof(int));
        result[i] = (int*)malloc(colB*sizeof(int));
        for(int j=0; j<colA; j++){
            matrixA[i][j] = rand()%10;
            matrixB[i][j] = rand()%10;
        }
    }

    printf("Matrix A:\n");
    printMatrix(matrixA, rowA, colA);
    printf("\nMatrix B:\n");
    printMatrix(matrixB, rowB, colB);

    printf("\nAddition of Matrix A and B:\n");
    addMatrix(matrixA, matrixB, result, rowA, colA);
    printMatrix(result, rowA, colA);

    printf("\nMultiplication of Matrix A and B:\n");
    multiplyMatrix(matrixA, matrixB, result, rowA, colA, rowB, colB);
    printMatrix(result, rowA, colB);

    for(int i=0; i<rowA; i++){
        free(matrixA[i]);
        free(matrixB[i]);
        free(result[i]);
    }
    free(matrixA);
    free(matrixB);
    free(result);
    return 0;
}

void printMatrix(int** matrix, int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int** matrixA, int** matrixB, int** result, int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void multiplyMatrix(int** matrixA, int** matrixB, int** result, int rowA, int colA, int rowB, int colB){
    if(colA!=rowB){
        printf("Error: Cannot multiply these matrix!\n");
        return;
    }
    for(int i=0; i<rowA; i++){
        for(int j=0; j<colB; j++){
            int sum = 0;
            for(int k=0; k<colA; k++){
                sum += matrixA[i][k]*matrixB[k][j];
            }
            result[i][j] = sum;
        }
    }
}