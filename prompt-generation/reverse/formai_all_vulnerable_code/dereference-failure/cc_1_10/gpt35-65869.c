//FormAI DATASET v1.0 Category: Matrix operations ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

void printMatrix(int *matrix, int rows, int cols) {
    printf("Printing Matrix...\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", *(matrix + i*cols + j));
        }
        printf("\n");
    }
}

void transpose(int *matrix, int rows, int cols) {
    printf("Transposing Matrix...\n");
    int *tempMatrix = malloc(rows*cols*sizeof(int));

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            *(tempMatrix + j*rows + i) = *(matrix + i*cols + j);
        }
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            *(matrix + i*cols + j) = *(tempMatrix + i*cols + j);
        }
    }

    free(tempMatrix);
}

void multiply(int *matrix1, int rows1, int cols1, int *matrix2, int rows2, int cols2) {
    if(cols1 != rows2) {
        printf("Error: Cannot multiply matrices with incompatible dimensions.\n");
        return;
    }

    printf("Multiplying Matrices...\n");
    int *resultMatrix = malloc(rows1*cols2*sizeof(int));

    for(int i = 0; i < rows1; i++) {
        for(int j = 0; j < cols2; j++) {
            *(resultMatrix + i*cols2 + j) = 0;
            for(int k = 0; k < cols1; k++) {
                *(resultMatrix + i*cols2 + j) += *(matrix1 + i*cols1 + k) * *(matrix2 + k*cols2 + j);
            }
        }
    }

    printMatrix(resultMatrix, rows1, cols2);
    free(resultMatrix);
}

int main() {
    int matrix1[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int matrix2[3][2] = {{1,2}, {3,4}, {5,6}};

    int rows1 = sizeof(matrix1)/sizeof(matrix1[0]);
    int cols1 = sizeof(matrix1[0])/sizeof(matrix1[0][0]);

    int rows2 = sizeof(matrix2)/sizeof(matrix2[0]);
    int cols2 = sizeof(matrix2[0])/sizeof(matrix2[0][0]);

    printMatrix(&matrix1[0][0], rows1, cols1);
    transpose(&matrix1[0][0], rows1, cols1);
    printMatrix(&matrix1[0][0], cols1, rows1);
    multiply(&matrix1[0][0], cols1, rows1, &matrix2[0][0], rows2, cols2);

    return 0;
}