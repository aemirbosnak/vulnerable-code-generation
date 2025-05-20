//FormAI DATASET v1.0 Category: Data structures visualization ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int height;
    int width;
    char** elements;
} Matrix;

Matrix* create_matrix(int height, int width) {
    Matrix* matrix = malloc(sizeof(Matrix));
    matrix->height = height;
    matrix->width = width;
    matrix->elements = malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++) {
        matrix->elements[i] = malloc(width * sizeof(char));
        for (int j = 0; j < width; j++) {
            matrix->elements[i][j] = '-';
        }
    }
    return matrix;
}

void print_matrix(Matrix* matrix) {
    printf("\n");
    for (int i = 0; i < matrix->height; i++) {
        for (int j = 0; j < matrix->width; j++) {
            printf("%c ", matrix->elements[i][j]);
        }
        printf("\n");
    }
}

void set_value(Matrix* matrix, int row, int col, char value) {
    matrix->elements[row][col] = value;
}

int main() {
    Matrix* matrix = create_matrix(MAX_SIZE, MAX_SIZE);

    set_value(matrix, 0, 0, 'A');
    set_value(matrix, 1, 1, 'B');
    set_value(matrix, 2, 2, 'C');
    set_value(matrix, 3, 3, 'D');
    set_value(matrix, 4, 4, 'E');
    set_value(matrix, 5, 5, 'F');
    set_value(matrix, 6, 6, 'G');
    set_value(matrix, 7, 7, 'H');
    set_value(matrix, 8, 8, 'I');
    set_value(matrix, 9, 9, 'J');

    printf("This is a visualization of a 10x10 Matrix:\n");
    print_matrix(matrix);

    return 0;
}