//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BLACK 0
#define WHITE 1

typedef struct {
    int **matrix;
    int width;
    int height;
} QRCode;

void generateQRCode(QRCode *qrcode, char *input) {
    int i, j, bit, mask = 0x80;
    int modules = (qrcode->width - 17) / 4;
    for (i = 0; i < strlen(input); i++) {
        bit = input[i] - '0';
        for (j = 0; j < 8; j++) {
            if (bit & mask) {
                qrcode->matrix[i / modules][j + (i % modules) * 8] = WHITE;
            } else {
                qrcode->matrix[i / modules][j + (i % modules) * 8] = BLACK;
            }
            mask >>= 1;
        }
    }
}

void printQRCode(QRCode *qrcode) {
    int i, j;
    for (i = 0; i < qrcode->height; i++) {
        for (j = 0; j < qrcode->width; j++) {
            if (qrcode->matrix[i][j] == WHITE) {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("\n");
    }
}

int main() {
    char input[100];
    QRCode qrcode;
    printf("Enter input: ");
    scanf("%s", input);
    qrcode.height = 29;
    qrcode.width = strlen(input) * 8 + 17;
    qrcode.matrix = (int **)malloc(qrcode.height * sizeof(int *));
    for (int i = 0; i < qrcode.height; i++) {
        qrcode.matrix[i] = (int *)malloc(qrcode.width * sizeof(int));
    }
    generateQRCode(&qrcode, input);
    printQRCode(&qrcode);
    free(qrcode.matrix);
    return 0;
}