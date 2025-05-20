//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define BLACK 0
#define WHITE 1

void init_matrix(int **matrix, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        matrix[i] = (int *) malloc(size * sizeof(int));
        for (j = 0; j < size; j++) {
            matrix[i][j] = WHITE;
        }
    }
}

void free_matrix(int **matrix, int size) {
    int i;
    for (i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void print_matrix(int **matrix, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
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
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (matrix[i][j] == BLACK) {
                count++;
            }
        }
    }
    return count;
}

void add_border(int **matrix, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        matrix[i][0] = BLACK;
        matrix[i][size - 1] = BLACK;
    }
    for (j = 0; j < size; j++) {
        matrix[0][j] = BLACK;
        matrix[size - 1][j] = BLACK;
    }
}

void generate_qr_code(int **matrix, int size, char *data) {
    int i, j, k, mask = 1;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            matrix[i][j] = WHITE;
        }
    }
    for (i = 0; i < strlen(data); i++) {
        for (j = 0; j < 8; j++) {
            k = 7 - j;
            if ((data[i] >> j) & 1) {
                matrix[i * 8 + k][j * 8 + k] = BLACK;
            }
        }
    }
    add_border(matrix, size);
}

int main(int argc, char **argv) {
    srand(time(NULL));
    int size = rand() % (MAX_SIZE - 10) + 10;
    int **matrix = (int **) malloc(size * sizeof(int *));
    init_matrix(matrix, size);
    char *data = "https://example.com";
    generate_qr_code(matrix, size, data);
    print_matrix(matrix, size);
    free_matrix(matrix, size);
    return 0;
}