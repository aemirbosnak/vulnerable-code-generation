//FormAI DATASET v1.0 Category: Matrix operations ; Style: high level of detail
#include <stdio.h>

// Function to print a matrix
void printMatrix(int n, int m, int matrix[n][m]) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrix(int n, int m, int mat1[n][m], int mat2[n][m], int sum[n][m]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            sum[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// Function to subtract two matrices
void subMatrix(int n, int m, int mat1[n][m], int mat2[n][m], int sub[n][m]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            sub[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

// Function to multiply two matrices
void mulMatrix(int n1, int m1, int n2, int m2, int mat1[n1][m1], int mat2[n2][m2], int mul[n1][m2]){
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < m2; j++){
            mul[i][j] = 0;
            for(int k = 0; k < n2; k++){
                mul[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// Function to transpose a matrix
void transMatrix(int n, int m, int mat[n][m], int tran[m][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            tran[j][i] = mat[i][j];
        }
    }
}

int main()
{
    int n, m;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &n, &m);

    int matrix1[n][m], matrix2[n][m], sum[n][m], sub[n][m], mul[n][m], tran[m][n];

    printf("Enter the elements of first matrix:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the elements of second matrix:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Addition of two matrices
    addMatrix(n, m, matrix1, matrix2, sum);

    printf("\nSum of two matrices:\n");
    printMatrix(n, m, sum);

    // Subtraction of two matrices
    subMatrix(n, m, matrix1, matrix2, sub);

    printf("\nDifference of two matrices:\n");
    printMatrix(n, m, sub);

    //Multiplication of two matrices
    mulMatrix(n, m, m, n, matrix1, matrix2, mul);

    printf("\nProduct of two matrices:\n");
    printMatrix(n, m, mul);

    //Transpose of a matrix
    transMatrix(n, m, matrix1, tran);

    printf("\nTranspose of the first matrix:\n");
    printMatrix(m, n, tran);

    return 0;
}