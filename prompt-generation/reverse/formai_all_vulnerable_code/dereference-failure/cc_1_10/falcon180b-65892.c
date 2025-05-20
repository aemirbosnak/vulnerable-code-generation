//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define BLACK 0
#define WHITE 1

typedef struct {
    int **data;
    int size;
} QrCode;

QrCode *createQrCode(int size) {
    QrCode *qrCode = (QrCode *)malloc(sizeof(QrCode));
    qrCode->data = (int **)malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        qrCode->data[i] = (int *)malloc(sizeof(int) * size);
        for (int j = 0; j < size; j++) {
            qrCode->data[i][j] = WHITE;
        }
    }
    qrCode->size = size;
    return qrCode;
}

void destroyQrCode(QrCode *qrCode) {
    for (int i = 0; i < qrCode->size; i++) {
        free(qrCode->data[i]);
    }
    free(qrCode->data);
    free(qrCode);
}

void setQrCode(QrCode *qrCode, int x, int y, int color) {
    if (x >= 0 && x < qrCode->size && y >= 0 && y < qrCode->size) {
        qrCode->data[y][x] = color;
    }
}

void printQrCode(QrCode *qrCode) {
    for (int i = 0; i < qrCode->size; i++) {
        for (int j = 0; j < qrCode->size; j++) {
            if (qrCode->data[i][j] == BLACK) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    QrCode *qrCode = createQrCode(MAX_SIZE);
    setQrCode(qrCode, 0, 0, BLACK);
    setQrCode(qrCode, 0, MAX_SIZE - 1, BLACK);
    setQrCode(qrCode, MAX_SIZE - 1, 0, BLACK);
    setQrCode(qrCode, MAX_SIZE - 1, MAX_SIZE - 1, BLACK);
    int size = 0;
    while (size < MAX_SIZE) {
        int x = rand() % MAX_SIZE;
        int y = rand() % MAX_SIZE;
        if (qrCode->data[y][x] == WHITE) {
            setQrCode(qrCode, x, y, BLACK);
            size++;
        }
    }
    printQrCode(qrCode);
    destroyQrCode(qrCode);
    return 0;
}