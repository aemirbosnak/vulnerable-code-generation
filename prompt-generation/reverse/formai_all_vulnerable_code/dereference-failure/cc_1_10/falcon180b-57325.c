//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1000
#define BLACK 0
#define WHITE 1

int **create_matrix(int size) {
    int **matrix = (int **)malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * size);
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
                printf("X");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

void add_border(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        matrix[i][0] = BLACK;
        matrix[i][size - 1] = BLACK;
    }
    for (int j = 0; j < size; j++) {
        matrix[0][j] = BLACK;
        matrix[size - 1][j] = BLACK;
    }
}

void generate_qr_code(char *data, int **matrix, int size) {
    int data_length = strlen(data);
    int num_modules = (size - 2) * (size - 2);
    int num_data_modules = num_modules - 3 * (size - 2);
    int num_data_bytes = num_data_modules / 8;
    int num_error_correction_bytes = num_data_bytes + (num_data_bytes >> 2);
    int num_total_bytes = num_data_bytes + num_error_correction_bytes;
    int data_index = 0;
    int mask = 0;
    for (int i = 0; i < size - 2; i++) {
        for (int j = 0; j < size - 2; j++) {
            if ((i + j) % 2 == 0) {
                mask = 0x80;
            } else {
                mask = 0x01;
            }
            for (int k = 0; k < 8; k++) {
                if (data[data_index] & mask) {
                    matrix[i][j] = BLACK;
                } else {
                    matrix[i][j] = WHITE;
                }
                mask >>= 1;
                data_index++;
                if (data_index >= num_data_bytes) {
                    break;
                }
            }
        }
    }
    add_border(matrix, size);
}

int main() {
    srand(time(NULL));
    int size = rand() % MAX_SIZE + 1;
    char *data = (char *)malloc(sizeof(char) * (size * size - 2));
    for (int i = 0; i < size * size - 2; i++) {
        data[i] = rand() % 2 + '0';
    }
    int **matrix = create_matrix(size);
    generate_qr_code(data, matrix, size);
    print_matrix(matrix, size);
    free(data);
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}