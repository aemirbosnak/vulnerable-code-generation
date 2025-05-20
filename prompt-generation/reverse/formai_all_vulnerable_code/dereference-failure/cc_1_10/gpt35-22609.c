//FormAI DATASET v1.0 Category: Matrix operations ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

void Matrix_Addition(int rows, int cols, int Matrix1[rows][cols], int Matrix2[rows][cols]){
    int sum_Matrix[rows][cols];
    printf("The Sum of the Matrix is: \n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            sum_Matrix[i][j] = Matrix1[i][j] + Matrix2[i][j];
            printf("%d ",sum_Matrix[i][j]);
        }
        printf("\n");
    }
}

void Matrix_Subtraction(int rows, int cols, int Matrix1[rows][cols], int Matrix2[rows][cols]){
    int diff_Matrix[rows][cols];
    printf("The Difference of the Matrix is: \n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            diff_Matrix[i][j] = Matrix1[i][j] - Matrix2[i][j];
            printf("%d ",diff_Matrix[i][j]);
        }
        printf("\n");
    }
}

void Matrix_Multiplication(int rows, int cols, int Matrix1[rows][cols], int rows2, int cols2, int Matrix2[rows2][cols2]){
    int prod_Matrix[rows][cols2];
    printf("The Product of the Matrix is: \n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols2;j++){
            prod_Matrix[i][j] = 0;
            for(int k=0;k<cols;k++){
                prod_Matrix[i][j] += Matrix1[i][k] * Matrix2[k][j];
            }
            printf("%d ",prod_Matrix[i][j]);
        }
        printf("\n");
    }
}

void Matrix_Transpose(int rows, int cols, int Matrix1[rows][cols]){
    int trans_Matrix[cols][rows];
    printf("The Transpose of the Matrix is: \n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            trans_Matrix[j][i] = Matrix1[i][j];
        }
    }
    for(int i=0;i<cols;i++){
        for(int j=0;j<rows;j++){
            printf("%d ",trans_Matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int Matrix1[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int Matrix2[3][3] = {{9,8,7},{6,5,4},{3,2,1}};
    int rows = 3, cols = 3;
    Matrix_Addition(rows,cols,Matrix1,Matrix2);
    Matrix_Subtraction(rows,cols,Matrix1,Matrix2);
    Matrix_Multiplication(rows,cols,Matrix1,cols,rows,Matrix2);
    Matrix_Transpose(rows,cols,Matrix1);
    return 0;
}