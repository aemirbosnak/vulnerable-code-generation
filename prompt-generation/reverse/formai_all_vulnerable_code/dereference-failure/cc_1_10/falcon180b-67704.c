//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 1000
#define BLACK 0
#define WHITE 1

int **create_matrix(int size) {
    int **matrix = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            matrix[i][j] = WHITE;
        }
    }
    return matrix;
}

void free_matrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void print_matrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] == BLACK) {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("\n");
    }
}

int count_black(int **matrix, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] == BLACK) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    srand(time(NULL));
    int size = rand() % MAX_SIZE + 10;
    int **matrix = create_matrix(size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (rand() % 2 == 0) {
                matrix[i][j] = BLACK;
            }
        }
    }

    int black_count = count_black(matrix, size);

    printf("QR Code with %d black squares:\n", black_count);
    print_matrix(matrix, size);

    free_matrix(matrix, size);

    return 0;
}