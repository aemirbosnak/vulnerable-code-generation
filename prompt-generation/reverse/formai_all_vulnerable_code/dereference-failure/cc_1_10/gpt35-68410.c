//FormAI DATASET v1.0 Category: Matrix operations ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Function to print a matrix
void printMatrix(int **matrix, int rows, int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
int** addMatrix(int **matrixA, int **matrixB, int rows, int cols){
    int **resultMatrix = (int **)malloc(rows*sizeof(int *));
    for(int i=0;i<rows;i++){
        resultMatrix[i] = (int *)malloc(cols*sizeof(int));
        for(int j=0;j<cols;j++){
            resultMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    return resultMatrix;
}

// Function to subtract two matrices
int** subtractMatrix(int **matrixA, int **matrixB, int rows, int cols){
    int **resultMatrix = (int **)malloc(rows*sizeof(int *));
    for(int i=0;i<rows;i++){
        resultMatrix[i] = (int *)malloc(cols*sizeof(int));
        for(int j=0;j<cols;j++){
            resultMatrix[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    return resultMatrix;
}

// Function to multiply two matrices
int** multiplyMatrix(int **matrixA, int **matrixB, int rowsA, int colsA, int colsB){
    int **resultMatrix = (int **)malloc(rowsA*sizeof(int *));
    for(int i=0;i<rowsA;i++){
        resultMatrix[i] = (int *)malloc(colsB*sizeof(int));
        for(int j=0;j<colsB;j++){
            int sum = 0;
            for(int k=0;k<colsA;k++){
                sum += matrixA[i][k]*matrixB[k][j];
            }
            resultMatrix[i][j] = sum;
        }
    }
    return resultMatrix;
}

int main(){
    int rowsA,colsA,rowsB,colsB;
    printf("Enter the number of rows and columns of first matrix: ");
    scanf("%d %d",&rowsA,&colsA);
    printf("Enter the number of rows and columns of second matrix: ");
    scanf("%d %d",&rowsB,&colsB);

    // Input the first matrix
    int **matrixA = (int **)malloc(rowsA*sizeof(int *));
    printf("Enter the elements of first matrix:\n");
    for(int i=0;i<rowsA;i++){
        matrixA[i] = (int *)malloc(colsA*sizeof(int));
        for(int j=0;j<colsA;j++){
            scanf("%d",&matrixA[i][j]);
        }
    }

    // Input the second matrix
    int **matrixB = (int **)malloc(rowsB*sizeof(int *));
    printf("Enter the elements of second matrix:\n");
    for(int i=0;i<rowsB;i++){
        matrixB[i] = (int *)malloc(colsB*sizeof(int));
        for(int j=0;j<colsB;j++){
            scanf("%d",&matrixB[i][j]);
        }
    }

    // Add the two matrices
    if(rowsA!=rowsB || colsA!=colsB){
        printf("Addition is not possible!\n");
    } else {
        printf("The sum of the two matrices is:\n");
        int **addition = addMatrix(matrixA,matrixB,rowsA,colsA);
        printMatrix(addition,rowsA,colsA);
    }

    // Subtract the two matrices
    if(rowsA!=rowsB || colsA!=colsB){
        printf("Subtraction is not possible!\n");
    } else {
        printf("The difference of the two matrices is:\n");
        int **subtraction = subtractMatrix(matrixA,matrixB,rowsA,colsA);
        printMatrix(subtraction,rowsA,colsA);
    }

    // Multiply the two matrices
    if(colsA!=rowsB){
        printf("Multiplication is not possible!\n");
    } else {
        printf("The product of the two matrices is:\n");
        int **multiplication = multiplyMatrix(matrixA,matrixB,rowsA,colsA,colsB);
        printMatrix(multiplication,rowsA,colsB);
    }

    return 0;
}