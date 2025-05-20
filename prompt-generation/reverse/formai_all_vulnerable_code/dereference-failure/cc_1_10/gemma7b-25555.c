//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QR_CODE_SIZE 256

typedef struct QRCode {
    int size;
    char **data;
} QRCode;

QRCode *qr_code_create(int size) {
    QRCode *qr_code = malloc(sizeof(QRCode));
    qr_code->size = size;
    qr_code->data = malloc(size * size * sizeof(char));
    return qr_code;
}

void qr_code_encode(QRCode *qr_code, char *data) {
    int i, j, k;
    for (i = 0; i < qr_code->size; i++) {
        for (j = 0; j < qr_code->size; j++) {
            qr_code->data[i][j] = 0;
        }
    }

    k = 0;
    for (i = 0; i < qr_code->size; i++) {
        for (j = 0; j < qr_code->size; j++) {
            if (k < strlen(data)) {
                qr_code->data[i][j] = data[k];
                k++;
            } else {
                qr_code->data[i][j] = 0;
            }
        }
    }
}

void qr_code_print(QRCode *qr_code) {
    int i, j;
    for (i = 0; i < qr_code->size; i++) {
        for (j = 0; j < qr_code->size; j++) {
            printf("%c ", qr_code->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    QRCode *qr_code = qr_code_create(20);
    qr_code_encode(qr_code, "Hello, world!");
    qr_code_print(qr_code);

    free(qr_code->data);
    free(qr_code);

    return 0;
}