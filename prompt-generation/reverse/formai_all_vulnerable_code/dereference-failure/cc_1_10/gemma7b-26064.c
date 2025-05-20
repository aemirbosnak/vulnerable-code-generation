//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

typedef struct QRCode {
    int **data;
    int width;
    int height;
} QRCode;

QRCode *qrcode_create(int w, int h) {
    QRCode *qr = malloc(sizeof(QRCode));
    qr->data = malloc(w * h * sizeof(int));
    qr->width = w;
    qr->height = h;
    return qr;
}

void qrcode_encode(QRCode *qr, char *str) {
    int i, j, k = 0;
    for (i = 0; i < qr->height; i++) {
        for (j = 0; j < qr->width; j++) {
            qr->data[i][j] = 0;
            for (k = 0; str[k] && k < MAX_SIZE; k++) {
                if (str[k] == '1' && i == k) {
                    qr->data[i][j] = 1;
                }
            }
        }
    }
}

void qrcode_print(QRCode *qr) {
    int i, j;
    for (i = 0; i < qr->height; i++) {
        for (j = 0; j < qr->width; j++) {
            printf("%d ", qr->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char str[] = "Hello, world!";
    QRCode *qr = qrcode_create(10, 10);
    qrcode_encode(qr, str);
    qrcode_print(qr);
    free(qr);
    return 0;
}