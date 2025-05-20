//GEMINI-pro DATASET v1.0 Category: QR code generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    int w, h;
    int *data;
} QRCode;

QRCode *qrcode_new(int w, int h) {
    QRCode *qr = malloc(sizeof(QRCode));
    qr->w = w;
    qr->h = h;
    qr->data = malloc(w * h * sizeof(int));
    return qr;
}

void qrcode_free(QRCode *qr) {
    free(qr->data);
    free(qr);
}

void qrcode_set(QRCode *qr, int x, int y, int v) {
    if (x >= 0 && x < qr->w && y >= 0 && y < qr->h) {
        qr->data[y * qr->w + x] = v;
    }
}

int qrcode_get(QRCode *qr, int x, int y) {
    if (x >= 0 && x < qr->w && y >= 0 && y < qr->h) {
        return qr->data[y * qr->w + x];
    }
    return 0;
}

void qrcode_print(QRCode *qr) {
    for (int y = 0; y < qr->h; y++) {
        for (int x = 0; x < qr->w; x++) {
            printf("%d ", qr->data[y * qr->w + x]);
        }
        printf("\n");
    }
}

int main() {
    int w = 21;
    int h = 21;
    QRCode *qr = qrcode_new(w, h);

    // Draw a QR code pattern
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (x == 0 || y == 0 || x == w - 1 || y == h - 1) {
                qrcode_set(qr, x, y, 1);
            } else if (x == 6 && y == 6) {
                qrcode_set(qr, x, y, 1);
            } else if (x == 14 && y == 6) {
                qrcode_set(qr, x, y, 1);
            } else if (x == 6 && y == 14) {
                qrcode_set(qr, x, y, 1);
            } else if (x == 14 && y == 14) {
                qrcode_set(qr, x, y, 1);
            } else {
                qrcode_set(qr, x, y, 0);
            }
        }
    }

    // Print the QR code
    qrcode_print(qr);

    // Free the QR code
    qrcode_free(qr);

    return 0;
}