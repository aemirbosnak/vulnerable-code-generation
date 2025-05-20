//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define QR_CODE_SIZE 256
#define QR_CODE_DATA_SIZE 128

typedef struct Pixel {
    int x;
    int y;
    int r;
    int g;
    int b;
} Pixel;

Pixel generatePixel(int x, int y, int r, int g, int b) {
    Pixel pixel;
    pixel.x = x;
    pixel.y = y;
    pixel.r = r;
    pixel.g = g;
    pixel.b = b;
    return pixel;
}

void drawQRCode(Pixel **pixels, int size) {
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            pixels[x][y].r = pixels[x][y].g = pixels[x][y].b = 255;
        }
    }

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            pixels[x][y].r = pixels[x][y].g = pixels[x][y].b = 0;
        }
    }

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            switch (pixels[x][y].r) {
                case 255:
                    pixels[x][y].r = pixels[x][y].g = pixels[x][y].b = 0;
                    break;
                case 0:
                    pixels[x][y].r = pixels[x][y].g = pixels[x][y].b = 255;
                    break;
            }
        }
    }
}

int main() {
    Pixel **pixels = (Pixel**)malloc(QR_CODE_SIZE * sizeof(Pixel*));
    for (int i = 0; i < QR_CODE_SIZE; i++) {
        pixels[i] = (Pixel*)malloc(QR_CODE_SIZE * sizeof(Pixel));
    }

    drawQRCode(pixels, QR_CODE_SIZE);

    for (int y = 0; y < QR_CODE_SIZE; y++) {
        for (int x = 0; x < QR_CODE_SIZE; x++) {
            printf("%d ", pixels[x][y].r);
        }
        printf("\n");
    }

    for (int i = 0; i < QR_CODE_SIZE; i++) {
        free(pixels[i]);
    }
    free(pixels);

    return 0;
}