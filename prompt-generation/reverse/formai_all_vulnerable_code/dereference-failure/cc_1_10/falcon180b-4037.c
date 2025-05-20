//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 25
#define BLACK 0
#define WHITE 1

int **create_matrix(int size) {
    int **matrix = malloc(size * sizeof(int *));
    for(int i=0; i<size; i++) {
        matrix[i] = malloc(size * sizeof(int));
        for(int j=0; j<size; j++) {
            matrix[i][j] = WHITE;
        }
    }
    return matrix;
}

void print_matrix(int **matrix, int size) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            if(matrix[i][j] == BLACK) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void generate_qr_code(char *data, int **matrix, int size) {
    int data_bits = strlen(data) * 8;
    int num_data_modules = (data_bits + 7) / 8;
    int num_total_modules = size * size;
    int num_remaining_modules = num_total_modules - num_data_modules;

    int current_pos = 0;
    int current_row = 0;
    int current_col = 0;

    for(int i=0; i<num_data_modules; i++) {
        int bit = data[i / 8] & (1 << (7 - (i % 8)));
        if(bit == 0) {
            current_row++;
        } else {
            current_col++;
        }
        matrix[current_row][current_col] = BLACK;
    }

    current_row = 0;
    current_col = num_data_modules;

    while(current_pos < num_total_modules) {
        if(current_row == current_col) {
            current_col++;
        } else if(current_row + current_col == num_total_modules - 1) {
            current_row++;
        } else if(current_row == 0 && current_col == num_data_modules - 1) {
            current_col--;
        } else {
            current_row++;
        }
        matrix[current_row][current_col] = BLACK;
        current_pos++;
    }
}

void main() {
    srand(time(NULL));

    char *data = "Hello, World!";
    int size = MAX_SIZE;

    int **matrix = create_matrix(size);
    generate_qr_code(data, matrix, size);

    print_matrix(matrix, size);

    for(int i=0; i<size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}