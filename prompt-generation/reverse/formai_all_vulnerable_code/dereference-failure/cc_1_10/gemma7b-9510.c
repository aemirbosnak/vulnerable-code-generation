//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QR_MAX_SIZE 256

typedef struct QRCode {
    int size;
    int **data;
} QRCode;

void qr_code_generate(QRCode *qrcode) {
    qrcode->size = QR_MAX_SIZE;
    qrcode->data = malloc(qrcode->size * sizeof(int *));
    for (int i = 0; i < qrcode->size; i++) {
        qrcode->data[i] = malloc(qrcode->size * sizeof(int));
    }

    qrcode->data[0][0] = 1;
    qrcode->data[0][1] = 1;
    qrcode->data[1][0] = 1;
    qrcode->data[1][1] = 1;

    time_t t = time(NULL);
    qrcode->data[t / 60][t % 60] = 1;
}

void qr_code_print(QRCode *qrcode) {
    for (int i = 0; i < qrcode->size; i++) {
        for (int j = 0; j < qrcode->size; j++) {
            if (qrcode->data[i][j] == 1) {
                printf("■ ");
            } else {
                printf("□ ");
            }
        }

        printf("\n");
    }
}

int main() {
    QRCode *qrcode = malloc(sizeof(QRCode));
    qr_code_generate(qrcode);
    qr_code_print(qrcode);

    free(qrcode);

    return 0;
}