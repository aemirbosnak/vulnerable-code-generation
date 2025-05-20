//FormAI DATASET v1.0 Category: Matrix operations ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

int** createMatrix(int rows, int cols) {
    int** mat = (int**) malloc(sizeof(int*) * rows);

    for(int i = 0; i < rows; i++) {
        mat[i] = (int*) malloc(sizeof(int) * cols);
    }

    return mat;
}

void destroyMatrix(int** mat, int rows) {
    for(int i = 0; i < rows; i++) {
        free(mat[i]);
    }

    free(mat);
}

void printMatrix(int** mat, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }

        printf("\n");
    }
}

int** transpose(int** mat, int rows, int cols) {
    int** transposedMat = createMatrix(cols, rows);

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            transposedMat[j][i] = mat[i][j];
        }
    }

    return transposedMat;
}

int** multiply(int** mat1, int rows1, int cols1, int** mat2, int rows2, int cols2) {
    if(cols1 != rows2) {
        printf("Cannot multiply matrices with these dimensions.\n");
        return NULL;
    }

    int** productMat = createMatrix(rows1, cols2);

    for(int i = 0; i < rows1; i++) {
        for(int j = 0; j < cols2; j++) {
            productMat[i][j] = 0;
            for(int k = 0; k < cols1; k++) {
                productMat[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return productMat;
}

int main() {
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int** mat = createMatrix(rows, cols);

    printf("Enter matrix elements:\n");

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    printf("\nOriginal matrix:\n");
    printMatrix(mat, rows, cols);

    int choice;
    do {
        printf("\nChoose an operation:\n");
        printf("1. Transpose matrix\n");
        printf("2. Multiply matrix\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                int** transposedMat = transpose(mat, rows, cols);
                printf("\nTransposed matrix:\n");
                printMatrix(transposedMat, cols, rows);
                destroyMatrix(transposedMat, cols);
                break;
            }
            case 2: {
                int rows2, cols2;
                printf("\nEnter dimensions of second matrix (rows x cols): ");
                scanf("%d %d", &rows2, &cols2);

                int** mat2 = createMatrix(rows2, cols2);

                printf("Enter matrix elements:\n");

                for(int i = 0; i < rows2; i++) {
                    for(int j = 0; j < cols2; j++) {
                        scanf("%d", &mat2[i][j]);
                    }
                }

                int** productMat = multiply(mat, rows, cols, mat2, rows2, cols2);
                printf("\nProduct matrix:\n");
                printMatrix(productMat, rows, cols2);

                destroyMatrix(mat2, rows2);
                destroyMatrix(productMat, rows);
                break;
            }
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }

    } while(choice != 3);

    destroyMatrix(mat, rows);

    return 0;
}