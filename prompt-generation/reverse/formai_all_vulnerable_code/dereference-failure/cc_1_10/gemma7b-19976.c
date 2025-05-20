//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QR_CODE_SIZE 255

typedef struct QRCodeData {
    int width;
    int height;
    int **data;
} QRCodeData;

QRCodeData* qrCodeDataCreate(int width, int height) {
    QRCodeData* qrCodeData = malloc(sizeof(QRCodeData));
    qrCodeData->width = width;
    qrCodeData->height = height;
    qrCodeData->data = malloc(sizeof(int*) * height);
    for (int i = 0; i < height; i++) {
        qrCodeData->data[i] = malloc(sizeof(int) * width);
    }
    return qrCodeData;
}

void qrCodeDataDestroy(QRCodeData* qrCodeData) {
    for (int i = 0; i < qrCodeData->height; i++) {
        free(qrCodeData->data[i]);
    }
    free(qrCodeData->data);
    free(qrCodeData);
}

void qrCodeDataGenerate(QRCodeData* qrCodeData, char* data) {
    int dataLen = strlen(data);
    int minSize = qrCodeData->width * qrCodeData->height;
    if (dataLen < minSize) {
        return;
    }

    for (int i = 0; i < qrCodeData->height; i++) {
        for (int j = 0; j < qrCodeData->width; j++) {
            int pos = i * qrCodeData->width + j;
            if (pos < dataLen) {
                qrCodeData->data[i][j] = data[pos] & 0x01;
            } else {
                qrCodeData->data[i][j] = 0;
            }
        }
    }
}

int main() {
    QRCodeData* qrCodeData = qrCodeDataCreate(25, 25);
    qrCodeDataGenerate(qrCodeData, "Hello, world!");
    qrCodeDataDestroy(qrCodeData);

    return 0;
}