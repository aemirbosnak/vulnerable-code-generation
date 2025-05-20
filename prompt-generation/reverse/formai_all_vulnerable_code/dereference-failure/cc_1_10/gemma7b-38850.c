//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

typedef struct QRCode {
    int **data;
    int rows;
    int cols;
} QRCode;

QRCode *generateQRCode(char *str) {
    QRCode *qrcode = malloc(sizeof(QRCode));

    qrcode->rows = MAX_SIZE;
    qrcode->cols = MAX_SIZE;
    qrcode->data = (int **)malloc(qrcode->rows * sizeof(int *));
    for (int i = 0; i < qrcode->rows; i++) {
        qrcode->data[i] = (int *)malloc(qrcode->cols * sizeof(int));
    }

    int len = strlen(str);
    qrcode->rows = len + 1;
    qrcode->cols = len + 1;
    qrcode->data = (int **)realloc(qrcode->data, qrcode->rows * sizeof(int *));
    for (int i = 0; i < qrcode->rows; i++) {
        qrcode->data[i] = (int *)realloc(qrcode->data[i], qrcode->cols * sizeof(int));
    }

    qrcode->data[0][0] = 0;
    qrcode->data[0][qrcode->cols - 1] = 0;
    qrcode->data[qrcode->rows - 1][0] = 0;
    qrcode->data[qrcode->rows - 1][qrcode->cols - 1] = 0;

    int i = 0;
    for (char *p = str; *p != '\0'; p++) {
        qrcode->data[i + 1][i + 1] = (int) *p;
        i++;
    }

    return qrcode;
}

int main() {
    char str[] = "Hello, World!";
    QRCode *qrcode = generateQRCode(str);

    for (int r = 0; r < qrcode->rows; r++) {
        for (int c = 0; c < qrcode->cols; c++) {
            printf("%d ", qrcode->data[r][c]);
        }
        printf("\n");
    }

    free(qrcode);

    return 0;
}