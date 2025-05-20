//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int width;
    int height;
    char *data;
} PixelArt;

PixelArt *pixelArtNew(int width, int height) {
    PixelArt *pixelArt = malloc(sizeof(PixelArt));
    pixelArt->width = width;
    pixelArt->height = height;
    pixelArt->data = malloc(sizeof(char) * width * height);
    return pixelArt;
}

void pixelArtFree(PixelArt *pixelArt) {
    free(pixelArt->data);
    free(pixelArt);
}

void pixelArtSetPixel(PixelArt *pixelArt, int x, int y, char c) {
    if (x < 0 || x >= pixelArt->width || y < 0 || y >= pixelArt->height) {
        return;
    }
    pixelArt->data[y * pixelArt->width + x] = c;
}

char pixelArtGetPixel(PixelArt *pixelArt, int x, int y) {
    if (x < 0 || x >= pixelArt->width || y < 0 || y >= pixelArt->height) {
        return 0;
    }
    return pixelArt->data[y * pixelArt->width + x];
}

void pixelArtPrint(PixelArt *pixelArt) {
    for (int y = 0; y < pixelArt->height; y++) {
        for (int x = 0; x < pixelArt->width; x++) {
            printf("%c", pixelArtGetPixel(pixelArt, x, y));
        }
        printf("\n");
    }
}

PixelArt *pixelArtGenerate(int width, int height) {
    PixelArt *pixelArt = pixelArtNew(width, height);

    srand(time(NULL));

    for (int y = 0; y < pixelArt->height; y++) {
        for (int x = 0; x < pixelArt->width; x++) {
            pixelArtSetPixel(pixelArt, x, y, rand() % 26 + 'a');
        }
    }

    return pixelArt;
}

int main() {
    PixelArt *pixelArt = pixelArtGenerate(100, 100);

    pixelArtPrint(pixelArt);

    pixelArtFree(pixelArt);

    return 0;
}