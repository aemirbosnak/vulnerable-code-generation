//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows, cols;
    int** elements;
} Matrix;

void read_matrix(Matrix* mat) {
    printf("Enter the number of rows and columns for your noble matrix, ser:\n");
    scanf("%d %d", &mat->rows, &mat->cols);

    printf("Enter the noble elements of your matrix, ser:\n");

    mat->elements = malloc(mat->rows * sizeof(int*));
    for (int i = 0; i < mat->rows; i++) {
        mat->elements[i] = calloc(mat->cols, sizeof(int));
        for (int j = 0; j < mat->cols; j++) {
            scanf("%d", &mat->elements[i][j]);
        }
    }
}

void print_matrix(const Matrix* mat) {
    printf("The noble matrix you hath brought before me:\n");

    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->elements[i][j]);
        }
        printf("\n");
    }
}

Matrix add_matrices(const Matrix* mat1, const Matrix* mat2) {
    Matrix result;

    result.rows = mat1->rows;
    result.cols = mat1->cols;

    result.elements = malloc(result.rows * sizeof(int*));
    for (int i = 0; i < result.rows; i++) {
        result.elements[i] = calloc(result.cols, sizeof(int));
        for (int j = 0; j < result.cols; j++) {
            result.elements[i][j] = mat1->elements[i][j] + mat2->elements[i][j];
        }
    }

    return result;
}

int main() {
    Matrix mat1, mat2, sum;

    read_matrix(&mat1);
    read_matrix(&mat2);

    printf("The first matrix:\n");
    print_matrix(&mat1);

    printf("The second matrix:\n");
    print_matrix(&mat2);

    sum = add_matrices(&mat1, &mat2);

    printf("The sum of the two noble matrices:\n");
    print_matrix(&sum);

    for (int i = 0; i < sum.rows; i++) {
        free(sum.elements[i]);
    }
    free(sum.elements);

    for (int i = 0; i < mat1.rows; i++) {
        free(mat1.elements[i]);
    }
    free(mat1.elements);

    for (int i = 0; i < mat2.rows; i++) {
        free(mat2.elements[i]);
    }
    free(mat2.elements);

    return 0;
}