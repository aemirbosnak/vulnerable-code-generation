//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    int **data;
    int rows;
    int cols;
} Matrix;

Matrix *create_matrix(int rows, int cols) {
    Matrix *matrix = malloc(sizeof(Matrix));
    matrix->data = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = malloc(cols * sizeof(int));
    }
    matrix->rows = rows;
    matrix->cols = cols;
    return matrix;
}

void destroy_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

void print_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

int **create_random_matrix(int rows, int cols) {
    srand(time(NULL));
    int **matrix = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
    return matrix;
}

void mine_data(Matrix *data) {
    int max_value = data->data[0][0];
    int min_value = data->data[0][0];
    for (int i = 0; i < data->rows; i++) {
        for (int j = 0; j < data->cols; j++) {
            if (data->data[i][j] > max_value) {
                max_value = data->data[i][j];
            }
            if (data->data[i][j] < min_value) {
                min_value = data->data[i][j];
            }
        }
    }
    printf("Max value: %d\n", max_value);
    printf("Min value: %d\n", min_value);
}

int main() {
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    if (rows > MAX_ROWS || cols > MAX_COLS) {
        printf("Error: Matrix too large.\n");
        return 1;
    }

    Matrix *data = create_matrix(rows, cols);
    int **random_data = create_random_matrix(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data->data[i][j] = random_data[i][j];
        }
    }

    printf("Random matrix:\n");
    print_matrix(data);

    mine_data(data);

    destroy_matrix(data);
    for (int i = 0; i < rows; i++) {
        free(random_data[i]);
    }
    free(random_data);

    return 0;
}