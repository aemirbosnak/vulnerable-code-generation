//FormAI DATASET v1.0 Category: Matrix operations ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>

void print_matrix(int **matrix, int rows, int cols){

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int **add_matrices(int **matrix1, int **matrix2, int rows, int cols){

    int **result = (int **)malloc(rows * sizeof(int *));
    for(int i=0; i<rows; i++){
        result[i] = (int *)malloc(cols * sizeof(int));
        for(int j=0; j<cols; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

int **transpose(int **matrix, int rows, int cols){

    int **result = (int **)malloc(cols * sizeof(int *));
    for(int i=0; i<cols; i++){
        result[i] = (int *)malloc(rows * sizeof(int));
        for(int j=0; j<rows; j++){
            result[i][j] = matrix[j][i];
        }
    }
    return result;
}

int main(){

    int rows, cols;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    int **matrix1 = (int **)malloc(rows * sizeof(int *));
    int **matrix2 = (int **)malloc(rows * sizeof(int *));
    for(int i=0; i<rows; i++){
        matrix1[i] = (int *)malloc(cols * sizeof(int));
        matrix2[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Enter the elements of the first matrix:\n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the elements of the second matrix:\n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("The first matrix is:\n");
    print_matrix(matrix1, rows, cols);

    printf("The second matrix is:\n");
    print_matrix(matrix2, rows, cols);

    int **sum_matrix = add_matrices(matrix1, matrix2, rows, cols);
    printf("The sum matrix is:\n");
    print_matrix(sum_matrix, rows, cols);

    int **transpose_matrix = transpose(matrix1, rows, cols);
    printf("The transpose of the first matrix is:\n");
    print_matrix(transpose_matrix, cols, rows);

    for(int i=0; i<rows; i++){
        free(matrix1[i]);
        free(matrix2[i]);
        free(sum_matrix[i]);
    }
    free(matrix1);
    free(matrix2);
    free(sum_matrix);
    for(int i=0; i<cols; i++){
        free(transpose_matrix[i]);
    }
    free(transpose_matrix);

    return 0;
}