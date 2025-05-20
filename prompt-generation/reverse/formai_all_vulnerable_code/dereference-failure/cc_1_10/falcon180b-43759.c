//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QR_CODE_SIZE 10000
#define MAX_QR_CODE_CHARS 8000

typedef struct {
    int size;
    char *data;
} QRCode;

QRCode *create_qrcode() {
    QRCode *qrcode = malloc(sizeof(QRCode));
    qrcode->size = 0;
    qrcode->data = malloc(MAX_QR_CODE_SIZE);
    return qrcode;
}

void destroy_qrcode(QRCode *qrcode) {
    free(qrcode->data);
    free(qrcode);
}

void append_qrcode(QRCode *qrcode, char c) {
    if (qrcode->size >= MAX_QR_CODE_SIZE) {
        printf("Error: QR code is too large.\n");
        exit(1);
    }
    qrcode->data[qrcode->size] = c;
    qrcode->size++;
}

int is_valid_qrcode(QRCode *qrcode) {
    int i, j;
    for (i = 0; i < qrcode->size; i++) {
        if (!isprint(qrcode->data[i])) {
            return 0;
        }
    }
    for (i = 0; i < qrcode->size - 1; i++) {
        for (j = i + 1; j < qrcode->size; j++) {
            if (qrcode->data[i] == qrcode->data[j]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    QRCode *qrcode = create_qrcode();
    char c;

    printf("Enter QR code:\n");
    while ((c = getchar())!= '\n') {
        append_qrcode(qrcode, toupper(c));
    }

    if (is_valid_qrcode(qrcode)) {
        printf("Valid QR code.\n");
    } else {
        printf("Invalid QR code.\n");
    }

    destroy_qrcode(qrcode);
    return 0;
}