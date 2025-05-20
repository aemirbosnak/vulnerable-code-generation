//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_PIXEL_COUNT 5000
#define MAX_COLOR_VALUE 255
#define MAX_LINE_WIDTH 10

typedef struct {
    int x;
    int y;
    int color;
} Pixel;

typedef struct {
    int pixelCount;
    Pixel *pixels;
} Image;

void generateRandomImage(Image *image) {
    srand(time(NULL));
    image->pixelCount = rand() % MAX_PIXEL_COUNT + 1;
    image->pixels = malloc(image->pixelCount * sizeof(Pixel));
    for (int i = 0; i < image->pixelCount; i++) {
        image->pixels[i].x = rand() % MAX_PIXEL_COUNT;
        image->pixels[i].y = rand() % MAX_PIXEL_COUNT;
        image->pixels[i].color = rand() % MAX_COLOR_VALUE;
    }
}

void printImage(Image *image) {
    printf("Pixel Count: %d\n", image->pixelCount);
    for (int i = 0; i < image->pixelCount; i++) {
        printf("(%d, %d, %d)\n", image->pixels[i].x, image->pixels[i].y, image->pixels[i].color);
    }
}

void freeImage(Image *image) {
    free(image->pixels);
    image->pixelCount = 0;
}

int main() {
    Image image;
    generateRandomImage(&image);
    printImage(&image);
    freeImage(&image);
    return 0;
}