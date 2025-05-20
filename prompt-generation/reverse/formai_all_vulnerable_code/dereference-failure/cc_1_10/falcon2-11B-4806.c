//Falcon2-11B DATASET v1.0 Category: QR code generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MATRIX_SIZE 5
#define STRING_LENGTH 4

void generateRandomString(char* str, int length) {
    for (int i = 0; i < length; i++) {
        str[i] = (char) ('a' + rand() % 26);
    }
}

void generateBinary(char* str, int length) {
    for (int i = 0; i < length; i++) {
        str[i] = (char) ('0' + rand() % 2);
    }
}

void printMatrix(char** matrix) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

void writeToFile(char** matrix) {
    FILE* file = fopen("qr.png", "wb");
    if (file!= NULL) {
        for (int i = 0; i < MATRIX_SIZE; i++) {
            for (int j = 0; j < MATRIX_SIZE; j++) {
                if (matrix[i][j] == '1') {
                    fputc('X', file);
                } else {
                    fputc(' ', file);
                }
            }
            fputc('\n', file);
        }
        fclose(file);
    }
}

int main() {
    srand(time(NULL));

    char** matrix = malloc(MATRIX_SIZE * sizeof(char*));
    for (int i = 0; i < MATRIX_SIZE; i++) {
        matrix[i] = malloc(MATRIX_SIZE * sizeof(char));
    }

    generateRandomString(matrix[0], STRING_LENGTH);
    generateRandomString(matrix[1], STRING_LENGTH);
    generateRandomString(matrix[2], STRING_LENGTH);
    generateRandomString(matrix[3], STRING_LENGTH);
    generateRandomString(matrix[4], STRING_LENGTH);
    generateRandomString(matrix[5], STRING_LENGTH);

    generateBinary(matrix[0], STRING_LENGTH);
    generateBinary(matrix[1], STRING_LENGTH);
    generateBinary(matrix[2], STRING_LENGTH);
    generateBinary(matrix[3], STRING_LENGTH);
    generateBinary(matrix[4], STRING_LENGTH);
    generateBinary(matrix[5], STRING_LENGTH);

    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            if (matrix[i][j] == '0') {
                matrix[i][j] = '1';
            } else if (matrix[i][j] == '1') {
                matrix[i][j] = '0';
            }
        }
    }

    printMatrix(matrix);
    writeToFile(matrix);
    free(matrix);

    return 0;
}