//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000
#define BLACK 0x000000
#define WHITE 0xFFFFFF

int **create_matrix(int size) {
    int **matrix = (int **)malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * size);
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = WHITE;
        }
    }
    return matrix;
}

void add_pixel(int **matrix, int x, int y, int color) {
    if (x >= 0 && x < MAX_SIZE && y >= 0 && y < MAX_SIZE) {
        matrix[y][x] = color;
    }
}

int main() {
    char *input = "https://example.com";
    int size = strlen(input) * 8;
    int **matrix = create_matrix(size);

    // Add border
    for (int i = 0; i < size; i++) {
        add_pixel(matrix, i, 0, BLACK);
        add_pixel(matrix, i, size - 1, BLACK);
    }
    for (int i = 0; i < size; i++) {
        add_pixel(matrix, 0, i, BLACK);
        add_pixel(matrix, size - 1, i, BLACK);
    }

    // Add data
    int pos = 0;
    for (int i = 0; i < strlen(input); i++) {
        for (int j = 0; j < 8; j++) {
            int bit = input[i] >> j & 1;
            add_pixel(matrix, pos++, 0, bit? BLACK : WHITE);
        }
    }

    // Save image
    FILE *file = fopen("qrcode.png", "wb");
    if (file == NULL) {
        printf("Error: could not create file\n");
        exit(1);
    }
    fprintf(file, "P6\n%d %d\n%d\n", size, size, 255);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            fprintf(file, "%d ", matrix[i][j]);
        }
    }
    fclose(file);

    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}