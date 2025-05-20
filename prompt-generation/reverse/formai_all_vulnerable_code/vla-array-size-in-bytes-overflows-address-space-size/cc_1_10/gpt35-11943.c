//FormAI DATASET v1.0 Category: Matrix operations ; Style: energetic
#include<stdio.h>

//function to print matrix
void printMatrix(int rows, int cols, int matrix[rows][cols]){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

//function to add two matrices
void addMatrix(int rows, int cols, int matrix1[rows][cols], int matrix2[rows][cols]){
    //creating the empty matrix to store the result
    int result[rows][cols];

    //adding the corresponding elements of matrices and storing the result in the empty matrix
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    //printing the result
    printf("\nThe addition of the matrices is:\n");
    printMatrix(rows, cols, result);
}

//function to multiply two matrices
void multiplyMatrix(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2]){
    //creating the empty matrix to store the result
    int result[rows1][cols2];

    //initializing the empty matrix with 0s
    for(int i=0;i<rows1;i++){
        for(int j=0;j<cols2;j++){
            result[i][j] = 0;
        }
    }

    //multiplying the matrices
    for(int i=0;i<rows1;i++){
        for(int j=0;j<cols2;j++){
            for(int k=0;k<cols1;k++){
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    //printing the result
    printf("\nThe multiplication of the matrices is:\n");
    printMatrix(rows1, cols2, result);
}

int main(){
    int rows1, cols1;

    //getting the dimensions of matrix1 from the user
    printf("Enter the number of rows and columns of matrix1: ");
    scanf("%d %d", &rows1, &cols1);

    //creating matrix1 and getting its contents from the user
    int matrix1[rows1][cols1];
    printf("\nEnter the elements of matrix1:\n");
    for(int i=0;i<rows1;i++){
        for(int j=0;j<cols1;j++){
            scanf("%d", &matrix1[i][j]);
        }
    }

    int rows2, cols2;

    //getting the dimensions of matrix2 from the user
    printf("\nEnter the number of rows and columns of matrix2: ");
    scanf("%d %d", &rows2, &cols2);

    //creating matrix2 and getting its contents from the user
    int matrix2[rows2][cols2];
    printf("\nEnter the elements of matrix2:\n");
    for(int i=0;i<rows2;i++){
        for(int j=0;j<cols2;j++){
            scanf("%d", &matrix2[i][j]);
        }
    }

    //checking if the matrices can be added and adding them if they can be
    if(rows1==rows2 && cols1==cols2){
        addMatrix(rows1, cols1, matrix1, matrix2);
    }
    else{
        printf("\nThe matrices cannot be added as their dimensions are different.\n");
    }

    //checking if the matrices can be multiplied and multiplying them if they can be
    if(cols1==rows2){
        multiplyMatrix(rows1, cols1, matrix1, rows2, cols2, matrix2);
    }
    else{
        printf("\nThe matrices cannot be multiplied as the number of columns in matrix1 is not equal to the number of rows in matrix2.\n");
    }

    return 0;
}