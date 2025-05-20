//FormAI DATASET v1.0 Category: Matrix operations ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>

int checkSymmetric(int **matrix, int rows, int cols) {
    int i,j;
    for(i=0;i<rows;i++) {
        for(j=0;j<cols;j++) {
            if(matrix[i][j]!=matrix[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

int checkSkewSymmetric(int **matrix, int rows, int cols) {
    int i,j;
    for(i=0;i<rows;i++) {
        for(j=0;j<cols;j++) {
            if(matrix[i][j]!=-matrix[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

int **transpose(int **matrix, int rows, int cols) {
    int **transposedMatrix = (int **)malloc(cols * sizeof(int *));
    int i,j;
    for(i=0;i<cols;i++) {
        transposedMatrix[i] = (int *)malloc(rows * sizeof(int));
        for(j=0;j<rows;j++) {
            transposedMatrix[i][j] = matrix[j][i];
        }
    }
    return transposedMatrix;
}

int main() {
    int rows, cols, i, j;
    printf("Enter number of rows: ");
    scanf("%d",&rows);
    printf("Enter number of columns: ");
    scanf("%d",&cols);
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for(i=0;i<rows;i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        printf("Enter elements for row %d: ",i+1);
        for(j=0;j<cols;j++) {
            scanf("%d",&matrix[i][j]);
        }
    }
    printf("The matrix you entered is:\n");
    for(i=0;i<rows;i++) {
        for(j=0;j<cols;j++) {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    int symmetric = checkSymmetric(matrix, rows, cols);
    int skewSymmetric = checkSkewSymmetric(matrix, rows, cols);
    if(symmetric==1 && skewSymmetric==0) {
        printf("The matrix is symmetric.\n");
    }
    else if(symmetric==0 && skewSymmetric==1) {
        printf("The matrix is skew-symmetric.\n");
    }
    else {
        printf("The matrix is neither symmetric nor skew-symmetric.\n");
    }
    int **transposedMatrix = transpose(matrix, rows, cols);
    printf("The transpose of the matrix is:\n");
    for(i=0;i<cols;i++) {
        for(j=0;j<rows;j++) {
            printf("%d ",transposedMatrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}