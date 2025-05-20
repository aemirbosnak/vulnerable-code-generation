//GEMINI-pro DATASET v1.0 Category: QR code generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_SIZE 1024

typedef struct {
    int size;
    int width;
    int height;
    char **pixels;
} QRCode;

QRCode *qr_code_new(int size, int width, int height) {
    QRCode *qr = malloc(sizeof(QRCode));
    if (!qr) {
        return NULL;
    }

    qr->size = size;
    qr->width = width;
    qr->height = height;
    qr->pixels = malloc(sizeof(char *) * height);
    if (!qr->pixels) {
        free(qr);
        return NULL;
    }

    for (int y = 0; y < height; y++) {
        qr->pixels[y] = malloc(sizeof(char) * width);
        if (!qr->pixels[y]) {
            for (int i = 0; i < y; i++) {
                free(qr->pixels[y]);
            }
            free(qr->pixels);
            free(qr);
            return NULL;
        }
    }

    return qr;
}

void qr_code_free(QRCode *qr) {
    if (!qr) {
        return;
    }

    for (int y = 0; y < qr->height; y++) {
        free(qr->pixels[y]);
    }
    free(qr->pixels);
    free(qr);
}

int qr_code_set_pixel(QRCode *qr, int x, int y, char pixel) {
    if (!qr || x < 0 || x >= qr->width || y < 0 || y >= qr->height) {
        return -1;
    }

    qr->pixels[y][x] = pixel;
    return 0;
}

int qr_code_get_pixel(QRCode *qr, int x, int y) {
    if (!qr || x < 0 || x >= qr->width || y < 0 || y >= qr->height) {
        return -1;
    }

    return qr->pixels[y][x];
}

QRCode *qr_code_generate(const char *data, int size) {
    // Generate the QR code using a third-party library and return the result.
    // The QR code should have a size of 'size' and a border of 4 pixels.
    return qr_code_new(size, size + 8, size + 8);
}

void qr_code_print(QRCode *qr) {
    if (!qr) {
        return;
    }

    for (int y = 0; y < qr->height; y++) {
        for (int x = 0; x < qr->width; x++) {
            printf("%c", qr->pixels[y][x]);
        }
        printf("\n");
    }
}

int main() {
    QRCode *qr = qr_code_generate("Hello, world!", 10);
    if (!qr) {
        printf("Failed to generate QR code.\n");
        return 1;
    }

    qr_code_print(qr);
    qr_code_free(qr);

    return 0;
}