//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ROWS 10
#define MAX_COLS 10

typedef struct {
    int **mat;
    int rows;
    int cols;
} Matrix;

void create_matrix(Matrix *mat, int rows, int cols) {
    mat->rows = rows;
    mat->cols = cols;
    mat->mat = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat->mat[i] = (int *)malloc(cols * sizeof(int));
    }
}

void destroy_matrix(Matrix *mat) {
    for (int i = 0; i < mat->rows; i++) {
        free(mat->mat[i]);
    }
    free(mat->mat);
}

void print_matrix(const Matrix *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    Matrix mat;
    create_matrix(&mat, rows, cols);

    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat.mat[i][j]);
        }
    }

    print_matrix(&mat);

    destroy_matrix(&mat);

    return 0;
}