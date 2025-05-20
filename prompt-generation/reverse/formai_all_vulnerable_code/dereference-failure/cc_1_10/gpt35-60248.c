//FormAI DATASET v1.0 Category: Matrix operations ; Style: active
#include<stdio.h>

//Function to display the matrix
void displayMatrix(int rows, int cols, int matrix[rows][cols]){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

//Function to add two matrices
void addMatrix(int rows, int cols, int matrix1[rows][cols], int matrix2[rows][cols], int result[rows][cols]){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

//Function to subtract two matrices
void subMatrix(int rows, int cols, int matrix1[rows][cols], int matrix2[rows][cols], int result[rows][cols]){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

//Function to multiply two matrices
void mulMatrix(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2]){
    for(int i=0; i<rows1; i++){
        for(int j=0; j<cols2; j++){
            result[i][j] = 0;
            for(int k=0; k<cols1; k++){
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

//Main function
int main(){
    int a[3][3]={{1,2,3}, {4,5,6}, {7,8,9}};
    int b[3][3]={{2,3,4}, {5,6,7}, {8,9,10}};
    int c[3][3];
    
    printf("Matrix A:\n");
    displayMatrix(3, 3, a);
    
    printf("\nMatrix B:\n");
    displayMatrix(3, 3, b);
    
    addMatrix(3, 3, a, b, c);
    printf("\nSum of Matrix A and B:\n");
    displayMatrix(3, 3, c);
    
    subMatrix(3, 3, a, b, c);
    printf("\nDifference of Matrix A and B:\n");
    displayMatrix(3, 3, c);
    
    int d[3][2]={{1,2}, {3,4}, {5,6}};
    int e[2][3]={{1,2,3}, {4,5,6}};
    int f[3][3];
    
    printf("\nMatrix D:\n");
    displayMatrix(3, 2, d);
    
    printf("\nMatrix E:\n");
    displayMatrix(2, 3, e);
    
    mulMatrix(3, 2, d, 2, 3, e, f);
    printf("\nMultiplication of Matrix D and E:\n");
    displayMatrix(3, 3, f);
    
    return 0;
}