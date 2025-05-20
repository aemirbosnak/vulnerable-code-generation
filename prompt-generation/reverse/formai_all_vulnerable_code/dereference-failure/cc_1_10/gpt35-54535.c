//FormAI DATASET v1.0 Category: Matrix operations ; Style: visionary
#include <stdio.h>

/* A visionary program for performing matrix operations in C */

/* Defining the struct for matrix */
typedef struct {
    int rows;
    int cols;
    int **vals;  // 2D array to store matrix values
} Matrix;

/* Function to create a new matrix */
Matrix* create_matrix(int rows, int cols) {
    Matrix *m = (Matrix*) malloc(sizeof(Matrix));
    m->rows = rows;
    m->cols = cols;
    m->vals = (int**) malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        m->vals[i] = (int*) malloc(cols * sizeof(int));
    }
    return m;
}

/* Function to fill matrix with values */
void fill_matrix(Matrix *m) {
    printf("Enter the values for the matrix: \n");
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            scanf("%d", &m->vals[i][j]);
        }
    }
}

/* Function to print the matrix */
void print_matrix(Matrix *m) {
    printf("Matrix:\n");
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->vals[i][j]);
        }
        printf("\n");
    }
}

/* Function to add two matrices */
Matrix* add_matrix(Matrix *m1, Matrix *m2) {
    if (m1->rows != m2->rows || m1->cols != m2->cols) {
        printf("Error: matrices must have same dimensions.\n");
        return NULL;
    }
    Matrix *result = create_matrix(m1->rows, m1->cols);
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->cols; j++) {
            result->vals[i][j] = m1->vals[i][j] + m2->vals[i][j];
        }
    }
    return result;
}

/* Function to multiply two matrices */
Matrix* multiply_matrix(Matrix *m1, Matrix *m2) {
    if (m1->cols != m2->rows) {
        printf("Error: number of columns in first matrix must be equal to number of rows in second matrix.\n");
        return NULL;
    }
    Matrix *result = create_matrix(m1->rows, m2->cols);
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->cols; j++) {
            result->vals[i][j] = 0;
            for (int k = 0; k < m1->cols; k++) {
                result->vals[i][j] += m1->vals[i][k] * m2->vals[k][j];
            }
        }
    }
    return result;
}

/* Main function */
int main(void) {
    int rows1, cols1, rows2, cols2;
    printf("Enter the dimensions of first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    Matrix *m1 = create_matrix(rows1, cols1);
    fill_matrix(m1);
    print_matrix(m1);

    printf("Enter the dimensions of second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    Matrix *m2 = create_matrix(rows2, cols2);
    fill_matrix(m2);
    print_matrix(m2);

    Matrix *m3 = add_matrix(m1, m2);
    if (m3) {
        printf("Addition result:\n");
        print_matrix(m3);
    }

    Matrix *m4 = multiply_matrix(m1, m2);
    if (m4) {
        printf("Multiplication result:\n");
        print_matrix(m4);
    }

    /* Freeing up memory */
    for (int i = 0; i < rows1; i++) {
        free(m1->vals[i]);
    }
    free(m1->vals);
    free(m1);
    for (int i = 0; i < rows2; i++) {
        free(m2->vals[i]);
    }
    free(m2->vals);
    free(m2);
    if (m3) {
        for (int i = 0; i < m3->rows; i++) {
            free(m3->vals[i]);
        }
        free(m3->vals);
        free(m3);
    }
    if (m4) {
        for (int i = 0; i < m4->rows; i++) {
            free(m4->vals[i]);
        }
        free(m4->vals);
        free(m4);
    }

    return 0;
}