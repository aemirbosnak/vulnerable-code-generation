//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void fill_matrix(int **matrix, int size) {
    srand(time(NULL));
    int count = 0;
    while (count < size * size / 2) {
        int x = rand() % size;
        int y = rand() % size;
        if (matrix[x][y] == WHITE) {
            matrix[x][y] = BLACK;
            count++;
        }
    }
}

int main() {
    int size = MAX_SIZE;
    int **matrix = create_matrix(size);
    fill_matrix(matrix, size);
    print_matrix(matrix, size);
    return 0;
}