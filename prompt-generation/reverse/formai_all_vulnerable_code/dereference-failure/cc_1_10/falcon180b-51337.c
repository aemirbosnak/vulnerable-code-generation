//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 21
#define HEIGHT 21
#define BLACK 0
#define WHITE 1

int **createMatrix(int width, int height) {
    int **matrix = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        matrix[i] = (int *)malloc(width * sizeof(int));
        for (int j = 0; j < width; j++) {
            matrix[i][j] = BLACK;
        }
    }
    return matrix;
}

void drawMatrix(int **matrix, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (matrix[i][j] == BLACK) {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("\n");
    }
}

int **generateQRCode(char *data, int width, int height) {
    int **matrix = createMatrix(width, height);
    int dataCount = strlen(data);
    int dataIndex = 0;
    int moduleCount = width * height;
    int moduleIndex = moduleCount - 1;

    while (dataCount > 0 && moduleIndex >= 0) {
        if (data[dataIndex] == '1') {
            matrix[moduleIndex / height][moduleIndex % height] = WHITE;
        }
        dataIndex++;
        moduleIndex--;
    }

    return matrix;
}

int main() {
    srand(time(NULL));

    int width = WIDTH;
    int height = HEIGHT;

    char *data = "Hello, World!";
    int **qrCode = generateQRCode(data, width, height);

    printf("QR Code:\n");
    drawMatrix(qrCode, width, height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (qrCode[i][j] == WHITE) {
                printf("\033[0;31m██\033[0m");
            } else {
                printf("\033[0;30m  \033[0m");
            }
        }
        printf("\n");
    }

    for (int i = 0; i < height; i++) {
        free(qrCode[i]);
    }
    free(qrCode);

    return 0;
}