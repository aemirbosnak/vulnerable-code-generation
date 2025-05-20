//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1024

typedef struct {
    char *data;
    int size;
} QRCode;

QRCode *generateQRCode(char *input) {
    int len = strlen(input);
    int version = 1;
    int mask = 0;
    QRCode *qrcode = malloc(sizeof(QRCode));
    qrcode->size = 1;
    qrcode->data = malloc(MAX_SIZE);

    int i, j;
    for (i = 0; i < len; i++) {
        char c = toupper(input[i]);

        if (c >= '0' && c <= '9') {
            mask |= 1;
        } else if (c >= 'A' && c <= 'Z') {
            mask |= 2;
        } else if (c >= 'a' && c <= 'z') {
            mask |= 4;
        } else {
            mask |= 8;
        }

        if ((i + 1) % 3 == 0) {
            int bit = 0;
            for (j = i - 2; j >= i - 3; j--) {
                if (mask & 1) {
                    bit |= 1 << (5 - (j + 1) % 3);
                }
                mask >>= 1;
            }
            qrcode->data[qrcode->size++] = bit;
        }
    }

    while ((qrcode->size % 4)!= 0) {
        qrcode->data[qrcode->size++] = 0;
    }

    return qrcode;
}

void printQRCode(QRCode *qrcode) {
    int i, j;
    for (i = 0; i < qrcode->size; i++) {
        for (j = 0; j < 8; j++) {
            if (qrcode->data[i] & (1 << j)) {
                printf("█");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    char input[MAX_SIZE];
    printf("Enter input string: ");
    scanf("%s", input);

    QRCode *qrcode = generateQRCode(input);
    printQRCode(qrcode);

    free(qrcode->data);
    free(qrcode);
    return 0;
}