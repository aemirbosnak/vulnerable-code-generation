//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    // Define the Matrix structure
    typedef struct Matrix {
        int rows;
        int cols;
        double **data;
    } Matrix;

    // Create a Matrix
    Matrix *my_matrix = malloc(sizeof(Matrix));
    my_matrix->rows = 3;
    my_matrix->cols = 3;
    my_matrix->data = malloc(my_matrix->rows * my_matrix->cols * sizeof(double));

    // Populate the Matrix
    my_matrix->data[0][0] = 1.0;
    my_matrix->data[0][1] = 2.0;
    my_matrix->data[0][2] = 3.0;
    my_matrix->data[1][0] = 4.0;
    my_matrix->data[1][1] = 5.0;
    my_matrix->data[1][2] = 6.0;
    my_matrix->data[2][0] = 7.0;
    my_matrix->data[2][1] = 8.0;
    my_matrix->data[2][2] = 9.0;

    // Transpose the Matrix
    Matrix *transposed_matrix = malloc(sizeof(Matrix));
    transposed_matrix->rows = my_matrix->cols;
    transposed_matrix->cols = my_matrix->rows;
    transposed_matrix->data = malloc(transposed_matrix->rows * transposed_matrix->cols * sizeof(double));

    for (int i = 0; i < transposed_matrix->rows; i++) {
        for (int j = 0; j < transposed_matrix->cols; j++) {
            transposed_matrix->data[i][j] = my_matrix->data[j][i];
        }
    }

    // Print the Transposed Matrix
    for (int i = 0; i < transposed_matrix->rows; i++) {
        for (int j = 0; j < transposed_matrix->cols; j++) {
            printf("%f ", transposed_matrix->data[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    free(my_matrix->data);
    free(my_matrix);
    free(transposed_matrix->data);
    free(transposed_matrix);

    return 0;
}