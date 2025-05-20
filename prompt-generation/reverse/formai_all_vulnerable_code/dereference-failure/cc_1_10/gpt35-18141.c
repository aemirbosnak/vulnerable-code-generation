//FormAI DATASET v1.0 Category: Matrix operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Function to print the matrix
void print_matrix(int **matrix, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//Function to find transpose of a matrix
int** transpose(int **matrix, int rows, int cols){
    int **result = (int **)malloc(cols * sizeof(int *));
    for(int i=0; i<cols; i++){
        result[i] = (int *)malloc(rows * sizeof(int));
    }

    for(int i=0; i<cols; i++){
        for(int j=0; j<rows; j++){
            result[i][j] = matrix[j][i];
        }
    }

    return result;
}

//Function to find inverse of a matrix
int** inverse(int **matrix, int n){
    int **result = (int **)malloc(n * sizeof(int *));
    for(int i=0; i<n; i++){
        result[i] = (int *)malloc(n * sizeof(int));
    }

    //Find the determinant of the matrix
    int det = 0;
    for(int i=0; i<n; i++){
        det += (matrix[0][i] * (matrix[1][(i+1)%n] * matrix[2][(i+2)%n] - matrix[1][(i+2)%n] * matrix[2][(i+1)%n]));
    }

    //Find the adjoint of the matrix
    int **adjoint = (int **)malloc(n * sizeof(int *));
    for(int i=0; i<n; i++){
        adjoint[i] = (int *)malloc(n * sizeof(int));
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            adjoint[i][j] = ((i+j)%2==0 ? 1 : -1) * (matrix[(j+1)%n][(i+1)%n] * matrix[(j+2)%n][(i+2)%n] - matrix[(j+2)%n][(i+1)%n] * matrix[(j+1)%n][(i+2)%n]);
        }
    }

    //Find the inverse of the matrix
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            result[i][j] = adjoint[i][j]*1.0/det;
        }
    }

    return result;
}

int main(){
    int rows = 3;
    int cols = 3;
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for(int i=0; i<rows; i++){
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    //Initialize the matrix with random values
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            matrix[i][j] = rand()%10;
        }
    }

    //Print the original matrix
    printf("Original matrix:\n");
    print_matrix(matrix, rows, cols);

    //Find the transpose of the matrix
    int **transposed = transpose(matrix, rows, cols);
    printf("Transposed matrix:\n");
    print_matrix(transposed, cols, rows);

    //Find the inverse of the matrix
    int **inverse_matrix = inverse(matrix, rows);
    printf("Inverse matrix:\n");
    print_matrix(inverse_matrix, rows, cols);

    return 0;
}