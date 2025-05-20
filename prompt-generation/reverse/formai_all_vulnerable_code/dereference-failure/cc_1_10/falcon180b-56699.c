//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_QR_SIZE 100000
#define BLACK 0
#define WHITE 1
#define BLACK_COLOR "\033[30m"
#define WHITE_COLOR "\033[37m"
#define RESET_COLOR "\033[0m"

typedef struct {
    int **matrix;
    int size;
} QRCode;

int isBlack(int x, int y) {
    if (x < 0 || y < 0 || x >= MAX_QR_SIZE || y >= MAX_QR_SIZE) {
        return WHITE;
    }
    return BLACK;
}

void initQRCode(QRCode *qrCode) {
    int i, j;
    qrCode->size = 0;
    qrCode->matrix = (int **)malloc(MAX_QR_SIZE * sizeof(int *));
    for (i = 0; i < MAX_QR_SIZE; i++) {
        qrCode->matrix[i] = (int *)malloc(MAX_QR_SIZE * sizeof(int));
        for (j = 0; j < MAX_QR_SIZE; j++) {
            qrCode->matrix[i][j] = BLACK;
        }
    }
}

void drawQRCode(QRCode *qrCode) {
    int i, j;
    for (i = 0; i < qrCode->size; i++) {
        for (j = 0; j < qrCode->size; j++) {
            if (qrCode->matrix[i][j] == BLACK) {
                printf(BLACK_COLOR);
            } else {
                printf(WHITE_COLOR);
            }
            printf("  ");
        }
        printf(RESET_COLOR);
        printf("\n");
    }
}

int getQRCodeSize(QRCode *qrCode) {
    return qrCode->size;
}

void destroyQRCode(QRCode *qrCode) {
    int i, j;
    for (i = 0; i < qrCode->size; i++) {
        for (j = 0; j < qrCode->size; j++) {
            free(qrCode->matrix[i][j]);
        }
        free(qrCode->matrix[i]);
    }
    free(qrCode->matrix);
}

int main() {
    char input[10000];
    int i, j, size, x, y;
    QRCode qrCode;
    initQRCode(&qrCode);
    printf("Enter QR code input: ");
    fgets(input, sizeof(input), stdin);
    size = strlen(input);
    for (i = 0; i < size; i++) {
        if (isalpha(input[i])) {
            x = i % qrCode.size;
            y = i / qrCode.size;
            if (isBlack(x, y)) {
                qrCode.matrix[y][x] = BLACK;
            }
        }
    }
    drawQRCode(&qrCode);
    getchar();
    destroyQRCode(&qrCode);
    return 0;
}