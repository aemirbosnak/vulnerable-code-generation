//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 256

typedef struct QRCode {
    int size;
    char **data;
} QRCode;

QRCode *qrcode_init(int size) {
    QRCode *qr = malloc(sizeof(QRCode));
    qr->size = size;
    qr->data = malloc(size * size * sizeof(char));
    return qr;
}

void qrcode_encode(QRCode *qr, char *data) {
    int i, j, k;
    for (i = 0; i < qr->size; i++) {
        for (j = 0; j < qr->size; j++) {
            qr->data[i][j] = 0;
        }
    }

    k = 0;
    for (i = 0; i < qr->size && k < strlen(data); i++) {
        for (j = 0; j < qr->size && k < strlen(data); j++) {
            if (data[k] == '1') {
                qr->data[i][j] = 1;
            }
            k++;
        }
    }
}

void qrcode_draw(QRCode *qr) {
    int i, j;
    for (i = 0; i < qr->size; i++) {
        for (j = 0; j < qr->size; j++) {
            if (qr->data[i][j] == 1) {
                printf("● ");
            } else {
                printf("◦ ");
            }
        }
        printf("\n");
    }
}

int main() {
    QRCode *qr = qrcode_init(10);
    qrcode_encode(qr, "Hello, world!");
    qrcode_draw(qr);

    free(qr->data);
    free(qr);

    return 0;
}