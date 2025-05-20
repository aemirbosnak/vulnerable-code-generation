//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LENGTH 1024
#define MIN_VALUE -1000000000
#define MAX_VALUE 1000000000

void print_matrix(int (*matrix)[MAX_LENGTH]);
void generate_random_matrix(int (*matrix)[MAX_LENGTH], int size);
void sum_matrix(int (*matrix)[MAX_LENGTH], int start_row, int start_col, int end_row, int end_col);
void multiply_matrix(int (*matrix)[MAX_LENGTH], int (*other_matrix)[MAX_LENGTH]);
void transpose_matrix(int (*matrix)[MAX_LENGTH]);

int main() {
    int (*matrix)[MAX_LENGTH] = calloc(MAX_LENGTH, sizeof(int));
    generate_random_matrix(matrix, 10);
    print_matrix(matrix);

    int start_row = 3;
    int start_col = 2;
    int end_row = 6;
    int end_col = 8;
    sum_matrix(matrix, start_row, start_col, end_row, end_col);

    multiply_matrix(matrix, matrix);
    transpose_matrix(matrix);

    return 0;
}

void print_matrix(int (*matrix)[MAX_LENGTH]) {
    for (int i = 0; i < MAX_LENGTH; i++) {
        for (int j = 0; j < MAX_LENGTH; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void generate_random_matrix(int (*matrix)[MAX_LENGTH], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = (int)(rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
        }
    }
}

void sum_matrix(int (*matrix)[MAX_LENGTH], int start_row, int start_col, int end_row, int end_col) {
    int sum = 0;
    for (int i = start_row; i <= end_row; i++) {
        for (int j = start_col; j <= end_col; j++) {
            sum += matrix[i][j];
        }
    }
    printf("Sum of matrix: %d\n", sum);
}

void multiply_matrix(int (*matrix)[MAX_LENGTH], int (*other_matrix)[MAX_LENGTH]) {
    int (*result_matrix)[MAX_LENGTH] = calloc(MAX_LENGTH, sizeof(int));
    for (int i = 0; i < MAX_LENGTH; i++) {
        for (int j = 0; j < MAX_LENGTH; j++) {
            int sum = 0;
            for (int k = 0; k < MAX_LENGTH; k++) {
                sum += matrix[i][k] * other_matrix[k][j];
            }
            result_matrix[i][j] = sum;
        }
    }
    free(matrix);
    matrix = result_matrix;
}

void transpose_matrix(int (*matrix)[MAX_LENGTH]) {
    int (*transposed_matrix)[MAX_LENGTH] = calloc(MAX_LENGTH, sizeof(int));
    for (int i = 0; i < MAX_LENGTH; i++) {
        for (int j = 0; j < MAX_LENGTH; j++) {
            transposed_matrix[j][i] = matrix[i][j];
        }
    }
    free(matrix);
    matrix = transposed_matrix;
}