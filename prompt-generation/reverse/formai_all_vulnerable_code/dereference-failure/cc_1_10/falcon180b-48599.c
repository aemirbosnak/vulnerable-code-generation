//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

int **create_matrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

void destroy_matrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void print_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void flip_image(int **src, int **dest, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dest[i][j] = src[rows - i - 1][j];
        }
    }
}

void change_brightness(int **src, int **dest, int rows, int cols, int brightness) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dest[i][j] = src[i][j] + brightness;
        }
    }
}

void change_contrast(int **src, int **dest, int rows, int cols, int contrast) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dest[i][j] = (src[i][j] * contrast) / 255;
        }
    }
}

int main() {
    srand(time(NULL));
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    int **src = create_matrix(rows, cols);
    int **dest = create_matrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            src[i][j] = rand() % 256;
        }
    }
    flip_image(src, dest, rows, cols);
    change_brightness(dest, dest, rows, cols, 50);
    change_contrast(dest, dest, rows, cols, 150);
    printf("Original Image:\n");
    print_matrix(src, rows, cols);
    printf("Flipped Image with Increased Brightness and Contrast:\n");
    print_matrix(dest, rows, cols);
    destroy_matrix(src, rows);
    destroy_matrix(dest, rows);
    return 0;
}