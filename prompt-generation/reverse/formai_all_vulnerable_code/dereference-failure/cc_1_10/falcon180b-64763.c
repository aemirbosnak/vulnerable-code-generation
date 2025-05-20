//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000
#define BLACK 0
#define WHITE 1

typedef struct {
    int **matrix;
    int size;
} QRCode;

void createQRCode(QRCode *qrCode, int size) {
    qrCode->size = size;
    qrCode->matrix = (int **)malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        qrCode->matrix[i] = (int *)malloc(sizeof(int) * size);
        for (int j = 0; j < size; j++) {
            qrCode->matrix[i][j] = WHITE;
        }
    }
}

void destroyQRCode(QRCode *qrCode) {
    for (int i = 0; i < qrCode->size; i++) {
        free(qrCode->matrix[i]);
    }
    free(qrCode->matrix);
}

void printQRCode(QRCode *qrCode) {
    for (int i = 0; i < qrCode->size; i++) {
        for (int j = 0; j < qrCode->size; j++) {
            if (qrCode->matrix[i][j] == BLACK) {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("\n");
    }
}

void readQRCode(QRCode *qrCode, char *data) {
    int size = strlen(data);
    int i = 0, j = 0;
    while (i < size) {
        while (j < size && data[i]!= data[j]) {
            j++;
        }
        if (data[i] == data[j]) {
            if (qrCode->matrix[i / qrCode->size][j / qrCode->size] == WHITE) {
                qrCode->matrix[i / qrCode->size][j / qrCode->size] = BLACK;
            }
        }
        i++;
        j++;
    }
}

int main() {
    QRCode qrCode;
    createQRCode(&qrCode, MAX_SIZE);
    char *data = "I love you";
    readQRCode(&qrCode, data);
    printQRCode(&qrCode);
    destroyQRCode(&qrCode);
    return 0;
}