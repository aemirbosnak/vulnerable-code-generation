//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define QR_MAX_SIZE 4096

struct QRCode {
    int size;
    int **data;
};

void initQRCode(struct QRCode *qrcode, int size) {
    qrcode->size = size;
    qrcode->data = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        qrcode->data[i] = (int *)malloc(size * sizeof(int));
    }
}

void destroyQRCode(struct QRCode *qrcode) {
    for (int i = 0; i < qrcode->size; i++) {
        free(qrcode->data[i]);
    }
    free(qrcode->data);
}

void setQRCode(struct QRCode *qrcode, int x, int y, int color) {
    if (x >= 0 && y >= 0 && x < qrcode->size && y < qrcode->size) {
        qrcode->data[y][x] = color;
    }
}

void printQRCode(struct QRCode *qrcode) {
    for (int i = 0; i < qrcode->size; i++) {
        for (int j = 0; j < qrcode->size; j++) {
            printf("%d ", qrcode->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct QRCode qrcode;
    char input[100];
    int size = 0;

    printf("Enter text to generate QR code: ");
    scanf("%s", input);

    initQRCode(&qrcode, QR_MAX_SIZE);

    setQRCode(&qrcode, 0, 0, 0);
    setQRCode(&qrcode, 0, qrcode.size - 1, 0);
    setQRCode(&qrcode, qrcode.size - 1, 0, 0);
    setQRCode(&qrcode, qrcode.size - 1, qrcode.size - 1, 0);

    int posX = 0, posY = 0;
    for (int i = 0; i < strlen(input); i++) {
        int bit = input[i] - '0';
        for (int j = 0; j < 5; j++) {
            int color = (bit >> j) & 1;
            setQRCode(&qrcode, posX, posY, color);
            posX++;
        }
        posY++;
        if (posX >= qrcode.size) {
            posX = 0;
            posY++;
        }
    }

    printQRCode(&qrcode);

    destroyQRCode(&qrcode);

    return 0;
}