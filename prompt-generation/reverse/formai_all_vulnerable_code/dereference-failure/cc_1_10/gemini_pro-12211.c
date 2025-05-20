//GEMINI-pro DATASET v1.0 Category: QR code generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    int size;
    Point *points;
} QRCode;

QRCode *createQRCode(int size) {
    QRCode *qrCode = malloc(sizeof(QRCode));
    qrCode->size = size;
    qrCode->points = malloc(sizeof(Point) * size * size);
    return qrCode;
}

void freeQRCode(QRCode *qrCode) {
    free(qrCode->points);
    free(qrCode);
}

void setPoint(QRCode *qrCode, int x, int y, int value) {
    qrCode->points[y * qrCode->size + x].x = x;
    qrCode->points[y * qrCode->size + x].y = y;
}

void printQRCode(QRCode *qrCode) {
    for (int y = 0; y < qrCode->size; y++) {
        for (int x = 0; x < qrCode->size; x++) {
            printf("%d", qrCode->points[y * qrCode->size + x].x);
        }
        printf("\n");
    }
}

QRCode *generateQRCode(char *data, int size) {
    QRCode *qrCode = createQRCode(size);

    int x = 0, y = 0;
    int direction = 0; // 0: right, 1: down, 2: left, 3: up
    int count = 0;

    while (count < size * size) {
        setPoint(qrCode, x, y, data[count] == '1');
        count++;

        switch (direction) {
            case 0: // right
                if (x == size - 1 || qrCode->points[(y + 1) * size + x].x != -1) {
                    direction = 1;
                    y++;
                } else {
                    x++;
                }
                break;
            case 1: // down
                if (y == size - 1 || qrCode->points[(y + 1) * size + x].x != -1) {
                    direction = 2;
                    x--;
                } else {
                    y++;
                }
                break;
            case 2: // left
                if (x == 0 || qrCode->points[(y - 1) * size + x].x != -1) {
                    direction = 3;
                    y--;
                } else {
                    x--;
                }
                break;
            case 3: // up
                if (y == 0 || qrCode->points[(y - 1) * size + x].x != -1) {
                    direction = 0;
                    x++;
                } else {
                    y--;
                }
                break;
        }
    }

    return qrCode;
}

int main() {
    char *data = "Hello World!";
    int size = 21;

    QRCode *qrCode = generateQRCode(data, size);
    printQRCode(qrCode);
    freeQRCode(qrCode);

    return 0;
}