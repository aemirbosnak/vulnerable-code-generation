//FormAI DATASET v1.0 Category: Matrix operations ; Style: creative
#include<stdio.h>

//Function to print the matrix
void printMatrix(int **matrix, int rows, int cols){
    printf("\nMatrix:\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

//Function to add two matrices
int **addMatrix(int **matrix1, int **matrix2, int rows, int cols){
    int **sum = (int**)malloc(rows*sizeof(int*));
    for(int i=0;i<rows;i++){
        sum[i] = (int*)malloc(cols*sizeof(int));
        for(int j=0;j<cols;j++){
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return sum;
}

//Function to subtract two matrices
int **subtractMatrix(int **matrix1, int **matrix2, int rows, int cols){
    int **difference = (int**)malloc(rows*sizeof(int*));
    for(int i=0;i<rows;i++){
        difference[i] = (int*)malloc(cols*sizeof(int));
        for(int j=0;j<cols;j++){
            difference[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return difference;
}

//Function to multiply two matrices
int **multiplyMatrix(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2){
    if(cols1 != rows2){
        printf("\nMatrices cannot be multiplied!\n");
        return NULL;
    }
    int **product = (int**)malloc(rows1*sizeof(int*));
    for(int i=0;i<rows1;i++){
        product[i] = (int*)malloc(cols2*sizeof(int));
        for(int j=0;j<cols2;j++){
            product[i][j] = 0;
            for(int k=0;k<cols1;k++){
                product[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return product;
}

int main(){
    int rows1, cols1, rows2, cols2, choice;
    printf("\nEnter rows and columns for matrix 1:\n");
    scanf("%d %d", &rows1, &cols1);
    int **matrix1 = (int**)malloc(rows1*sizeof(int*));
    for(int i=0;i<rows1;i++){
        matrix1[i] = (int*)malloc(cols1*sizeof(int));
        for(int j=0;j<cols1;j++){
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("\nEnter rows and columns for matrix 2:\n");
    scanf("%d %d", &rows2, &cols2);
    int **matrix2 = (int**)malloc(rows2*sizeof(int*));
    for(int i=0;i<rows2;i++){
        matrix2[i] = (int*)malloc(cols2*sizeof(int));
        for(int j=0;j<cols2;j++){
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }
    while(1){
        printf("\nOperations:\n1. Add matrices\n2. Subtract matrices\n3. Multiply matrices\n4. Print matrix 1\n5. Print matrix 2\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: {
                int **sum = addMatrix(matrix1, matrix2, rows1, cols1);
                printMatrix(sum, rows1, cols1);
                break;
            }
            case 2: {
                int **difference = subtractMatrix(matrix1, matrix2, rows1, cols1);
                printMatrix(difference, rows1, cols1);
                break;
            }
            case 3: {
                int **product = multiplyMatrix(matrix1, matrix2, rows1, cols1, rows2, cols2);
                if(product != NULL){
                    printMatrix(product, rows1, cols2);
                }
                break;
            }
            case 4: {
                printMatrix(matrix1, rows1, cols1);
                break;
            }
            case 5: {
                printMatrix(matrix2, rows2, cols2);
                break;
            }
            case 6: {
                printf("\nGoodbye!\n");
                return 0;
            }
            default: {
                printf("\nInvalid choice!\n");
                break;
            }
        }
    }
    return 0;
}