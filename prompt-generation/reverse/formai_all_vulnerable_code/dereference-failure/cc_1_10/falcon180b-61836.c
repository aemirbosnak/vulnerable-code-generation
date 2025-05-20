//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define BLACK 0
#define WHITE 1

int **createMatrix(int size) {
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

void printMatrix(int **matrix, int size) {
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

void generateQRCode(char *data, int size) {
    int **matrix = createMatrix(size);
    int dataLength = strlen(data);
    int numChunks = (dataLength + 7) / 8;
    int chunkSize = (size - 17) / numChunks;
    int remainder = (size - 17) % numChunks;
    int value = 0;
    int mask = 0x80;
    int bitIndex = 0;
    int x = 8;
    int y = 8;

    for (int i = 0; i < numChunks; i++) {
        if (i < remainder) {
            value = data[i * 8] - '0';
        } else {
            value = 0;
        }
        for (int j = 0; j < 8; j++) {
            if (value & mask) {
                matrix[i * chunkSize + j][y - 1 - i * chunkSize] = BLACK;
            }
            mask >>= 1;
        }
    }

    for (int i = 0; i < numChunks; i++) {
        for (int j = 0; j < 8; j++) {
            if (matrix[i * chunkSize + j][y - 1 - i * chunkSize] == BLACK) {
                matrix[i * chunkSize + j][y - 1 - i * chunkSize + 1] = BLACK;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] == BLACK) {
                matrix[i][j] = WHITE;
            } else {
                matrix[i][j] = BLACK;
            }
        }
    }

    printMatrix(matrix, size);

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

int main() {
    srand(time(NULL));
    int size = rand() % 11 + 10;
    char data[MAX_SIZE];
    sprintf(data, "https://github.com/username/repository");
    generateQRCode(data, size);
    return 0;
}