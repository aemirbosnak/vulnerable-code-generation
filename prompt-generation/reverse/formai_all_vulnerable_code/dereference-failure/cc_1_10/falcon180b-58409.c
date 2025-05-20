//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SIZE 1000
#define PI 3.14159265358979323846

int **create_matrix(int size) {
    int **matrix = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

void set_matrix_value(int **matrix, int x, int y, int value) {
    if (x >= 0 && x < MAX_SIZE && y >= 0 && y < MAX_SIZE) {
        matrix[x][y] = value;
    }
}

int get_matrix_value(int **matrix, int x, int y) {
    if (x >= 0 && x < MAX_SIZE && y >= 0 && y < MAX_SIZE) {
        return matrix[x][y];
    }
    return 0;
}

void print_matrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", get_matrix_value(matrix, i, j));
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int size = rand() % MAX_SIZE + 10;
    int **matrix = create_matrix(size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            set_matrix_value(matrix, i, j, rand() % 2);
        }
    }

    print_matrix(matrix, size);

    return 0;
}