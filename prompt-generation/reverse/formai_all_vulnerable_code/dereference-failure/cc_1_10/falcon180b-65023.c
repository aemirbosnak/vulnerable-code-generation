//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QR_MAX_SIZE 1024
#define QR_MAX_DATA_SIZE (QR_MAX_SIZE - 17)

typedef struct {
    int size;
    int margin;
    char *data;
} QRCode;

QRCode *qrcode_create(int size, int margin) {
    QRCode *qrcode = malloc(sizeof(QRCode));
    qrcode->size = size;
    qrcode->margin = margin;
    qrcode->data = malloc(QR_MAX_DATA_SIZE + 1);
    memset(qrcode->data, 0, QR_MAX_DATA_SIZE + 1);
    return qrcode;
}

void qrcode_destroy(QRCode *qrcode) {
    free(qrcode->data);
    free(qrcode);
}

int qrcode_encode(QRCode *qrcode, char *data) {
    int len = strlen(data);
    if (len > QR_MAX_DATA_SIZE) {
        return -1;
    }
    memcpy(qrcode->data, data, len);
    return 0;
}

void qrcode_print(QRCode *qrcode) {
    int size = qrcode->size;
    int margin = qrcode->margin;
    int data_size = strlen(qrcode->data);
    int i, j, x, y;
    char *data = qrcode->data;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if ((i >= margin && i < size - margin) && (j >= margin && j < size - margin)) {
                if (*data == '1') {
                    printf("  ");
                } else {
                    printf("██");
                }
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    QRCode *qrcode = qrcode_create(10, 2);
    qrcode_encode(qrcode, "Hello, World!");
    qrcode_print(qrcode);
    qrcode_destroy(qrcode);
    return 0;
}