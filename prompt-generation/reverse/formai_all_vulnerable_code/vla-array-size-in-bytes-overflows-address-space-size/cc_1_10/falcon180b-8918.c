//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define QR_WIDTH 21
#define QR_HEIGHT 21

typedef struct {
    int x, y;
} Point;

typedef struct {
    int **data;
    int width, height;
} QRCode;

void generateQRCode(QRCode *qrCode) {
    int i, j;
    for (i = 0; i < qrCode->height; i++) {
        for (j = 0; j < qrCode->width; j++) {
            qrCode->data[i][j] = 0;
        }
    }
}

void setQRCodeData(QRCode *qrCode, int x, int y, int value) {
    int i, j;
    for (i = 0; i < QR_WIDTH; i++) {
        for (j = 0; j < QR_HEIGHT; j++) {
            if (qrCode->data[i][j] == 0 && (x + i - 8) >= 0 && (y + j - 8) >= 0 && (x + i - 8) < qrCode->width && (y + j - 8) < qrCode->height) {
                qrCode->data[i][j] = value;
            }
        }
    }
}

void drawQRCode(QRCode *qrCode) {
    int i, j;
    for (i = 0; i < qrCode->height; i++) {
        for (j = 0; j < qrCode->width; j++) {
            if (qrCode->data[i][j] == 0) {
                printf("  ");
            } else {
                printf("##");
            }
        }
        printf("\n");
    }
}

void *generateThread(void *arg) {
    QRCode *qrCode = (QRCode *) arg;
    int x, y;
    srand(time(NULL));
    for (y = 0; y < QR_HEIGHT; y++) {
        for (x = 0; x < QR_WIDTH; x++) {
            if (qrCode->data[y][x] == 0) {
                int value = rand() % 2;
                setQRCodeData(qrCode, x, y, value);
            }
        }
    }
    return NULL;
}

int main() {
    int width, height, threadCount;
    printf("Enter QR code width: ");
    scanf("%d", &width);
    printf("Enter QR code height: ");
    scanf("%d", &height);
    printf("Enter number of threads: ");
    scanf("%d", &threadCount);
    QRCode qrCode;
    generateQRCode(&qrCode);
    pthread_t threads[threadCount];
    int i;
    for (i = 0; i < threadCount; i++) {
        pthread_create(&threads[i], NULL, generateThread, &qrCode);
    }
    for (i = 0; i < threadCount; i++) {
        pthread_join(threads[i], NULL);
    }
    drawQRCode(&qrCode);
    return 0;
}