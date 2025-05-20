//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QR_CODE_SIZE 1000
#define MAX_QR_CODE_VALUE 4294967295

struct qr_code {
    int size;
    int value;
    char *data;
};

void generate_qr_code(struct qr_code *qrcode) {
    char *data = malloc(MAX_QR_CODE_SIZE * sizeof(char));
    int size = 0;

    for (int i = 0; i < MAX_QR_CODE_SIZE; i++) {
        data[i] = rand() % 10 + '0';
    }

    qrcode->size = size;
    qrcode->value = 0;
    qrcode->data = data;
}

int is_valid_qr_code(struct qr_code *qrcode) {
    int value = 0;
    int size = 0;

    for (int i = 0; i < strlen(qrcode->data); i++) {
        if (isdigit(qrcode->data[i])) {
            value = value * 10 + (qrcode->data[i] - '0');
        } else {
            return 0;
        }
    }

    size = value % MAX_QR_CODE_VALUE;

    if (size == qrcode->size) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    struct qr_code qrcode;
    generate_qr_code(&qrcode);

    if (is_valid_qr_code(&qrcode)) {
        printf("Valid QR code with size %d and value %d\n", qrcode.size, qrcode.value);
    } else {
        printf("Invalid QR code\n");
    }

    free(qrcode.data);
    return 0;
}