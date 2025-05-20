//FormAI DATASET v1.0 Category: Matrix operations ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

void print_matrix(int rows, int cols, int matrix[][cols]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrix(int rows, int cols, int matrix1[][cols], int matrix2[][cols], int result[][cols]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void multiply_matrix(int rows1, int cols1, int matrix1[][cols1], int rows2, int cols2, int matrix2[][cols2], int result[][cols2]) {
    if(cols1 != rows2) {
        printf("Cannot multiply matrices with these dimensions\n");
        exit(1);
    }

    for(int i = 0; i < rows1; i++) {
        for(int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for(int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int result[3][3];

    printf("Matrix 1:\n");
    print_matrix(3, 3, matrix1);

    printf("\nMatrix 2:\n");
    print_matrix(3, 3, matrix2);

    printf("\nAdding matrices...\n");
    add_matrix(3, 3, matrix1, matrix2, result);
    print_matrix(3, 3, result);

    int matrix3[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    int matrix4[2][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}};
    int result2[3][4];

    printf("\nMatrix 3:\n");
    print_matrix(3, 2, matrix3);

    printf("\nMatrix 4:\n");
    print_matrix(2, 4, matrix4);

    printf("\nMultiplying matrices...\n");
    multiply_matrix(3, 2, matrix3, 2, 4, matrix4, result2);
    print_matrix(3, 4, result2);
    
    return 0;
}