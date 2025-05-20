//FormAI DATASET v1.0 Category: Matrix operations ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>

//helper function to print matrix
void print_matrix(int rows, int cols, int matrix[rows][cols]){
    int i,j;
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int rows,cols;
    printf("Enter the number of rows for matrices: ");
    scanf("%d",&rows);
    printf("Enter the number of columns for matrices: ");
    scanf("%d",&cols);
    int a[rows][cols],b[rows][cols],c[rows][cols]; //declare matrices
    int i,j,k;

    printf("Enter the elements of 1st matrix: \n");
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the elements of 2nd matrix: \n");
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            scanf("%d",&b[i][j]);
        }
    }

    //Addition of Matrices
    printf("\nAddition of Matrices: \n");
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    print_matrix(rows,cols,c);

    //Subtraction of Matrices
    printf("\nSubtraction of Matrices: \n");
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            c[i][j] = a[i][j] - b[i][j];
        }
    }
    print_matrix(rows,cols,c);

    //Multiplication of Matrices
    printf("\nMultiplication of Matrices: \n");
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            c[i][j] = 0;
            for(k=0; k<cols; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    print_matrix(rows,cols,c);

    return 0;
}