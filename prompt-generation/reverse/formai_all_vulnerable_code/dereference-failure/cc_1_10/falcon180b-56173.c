//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define QR_MAX_SIZE 10000
#define QR_MAX_MODULES 10000
#define QR_MAX_BITS 10000
#define QR_MAX_DATA 10000

typedef struct {
    int size;
    int modules[QR_MAX_MODULES];
} QRCode;

typedef struct {
    int size;
    int *data;
} QRData;

QRCode *qrcode_create(int size) {
    QRCode *qrcode = malloc(sizeof(QRCode));
    qrcode->size = size;
    int i;
    for (i = 0; i < size; i++) {
        qrcode->modules[i] = 0;
    }
    return qrcode;
}

void qrcode_destroy(QRCode *qrcode) {
    free(qrcode);
}

void qrcode_get_modules(QRCode *qrcode, int **modules) {
    *modules = qrcode->modules;
}

QRData *qrcode_get_data(QRCode *qrcode) {
    QRData *data = malloc(sizeof(QRData));
    data->size = qrcode->size;
    data->data = malloc(qrcode->size * sizeof(int));
    int i;
    for (i = 0; i < qrcode->size; i++) {
        data->data[i] = qrcode->modules[i];
    }
    return data;
}

void qrcode_destroy_data(QRData *data) {
    free(data->data);
    free(data);
}

int qrcode_encode(QRCode *qrcode, char *input) {
    int input_len = strlen(input);
    int data_len = input_len * 8;
    int data_size = (data_len + 7) / 8;
    int i;
    for (i = 0; i < data_size; i++) {
        int bit = 0;
        int j;
        for (j = 0; j < 8; j++) {
            if (input[i * 8 + j] == '1') {
                bit |= 1 << (7 - j);
            }
        }
        qrcode->modules[i] = bit;
    }
    return data_size;
}

void qrcode_print(QRCode *qrcode) {
    int i;
    for (i = 0; i < qrcode->size; i++) {
        printf("%d ", qrcode->modules[i]);
    }
    printf("\n");
}

int main() {
    char input[QR_MAX_DATA];
    printf("Enter input: ");
    scanf("%s", input);
    QRCode *qrcode = qrcode_create(10);
    qrcode_encode(qrcode, input);
    qrcode_print(qrcode);
    QRData *data = qrcode_get_data(qrcode);
    int data_size = qrcode_get_data(qrcode)->size;
    printf("Data size: %d\n", data_size);
    int *data_modules = data->data;
    int i;
    for (i = 0; i < data_size; i++) {
        printf("%d ", data_modules[i]);
    }
    printf("\n");
    qrcode_destroy(qrcode);
    qrcode_destroy_data(data);
    return 0;
}