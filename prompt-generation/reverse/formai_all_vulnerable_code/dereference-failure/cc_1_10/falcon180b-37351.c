//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_QR_SIZE 100
#define MAX_QR_CODE_WORDS 1000

struct QRCode {
    int size;
    int numDataCodewords;
    int numErrorCorrectionCodewords;
    int errorCorrectionLevel;
    int data[MAX_QR_CODE_WORDS];
};

void initQRCode(struct QRCode *qrcode) {
    qrcode->size = 0;
    qrcode->numDataCodewords = 0;
    qrcode->numErrorCorrectionCodewords = 0;
    qrcode->errorCorrectionLevel = 0;
}

int getQRCodeSize(int numDataCodewords) {
    int size = 1;
    while (size < numDataCodewords) {
        size *= 4;
    }
    return size;
}

void generateQRCode(struct QRCode *qrcode, char *data, int length) {
    initQRCode(qrcode);
    int numDataCodewords = length * 8 + 12;
    int numErrorCorrectionCodewords = numDataCodewords + (numDataCodewords / 3);
    int size = getQRCodeSize(numDataCodewords);
    qrcode->size = size;
    qrcode->numDataCodewords = numDataCodewords;
    qrcode->numErrorCorrectionCodewords = numErrorCorrectionCodewords;
    qrcode->errorCorrectionLevel = 0;
    int i, j;
    for (i = 0; i < numDataCodewords; i++) {
        int value = 0;
        for (j = 0; j < 8; j++) {
            value = (value << 1) | (data[i * 8 + j] - '0');
        }
        qrcode->data[i] = value;
    }
}

void printQRCode(struct QRCode *qrcode) {
    int size = qrcode->size;
    int numDataCodewords = qrcode->numDataCodewords;
    int numErrorCorrectionCodewords = qrcode->numErrorCorrectionCodewords;
    int errorCorrectionLevel = qrcode->errorCorrectionLevel;
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            int x = i - size / 2;
            int y = j - size / 2;
            if (x >= 0 && x < size && y >= 0 && y < size && ((qrcode->data[numDataCodewords - 1] >> (size - 1 - j)) & 1) == 1) {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("\n");
    }
}

int main() {
    struct QRCode qrcode;
    char data[] = "https://github.com/";
    generateQRCode(&qrcode, data, strlen(data));
    printQRCode(&qrcode);
    return 0;
}