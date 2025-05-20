//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define WIDTH 512
#define HEIGHT 512
#define SIZE (WIDTH * HEIGHT)
#define MAX_WATERMARK_SIZE 32
#define WATERMARK_SIZE 16
#define WATERMARK_SEED (time(NULL))

typedef struct {
    int x, y;
} Point;

typedef struct {
    int r, g, b;
} Color;

typedef struct {
    int w, h;
    int* pixels;
} Image;

Image* createImage() {
    Image* image = (Image*)malloc(sizeof(Image));
    image->w = WIDTH;
    image->h = HEIGHT;
    image->pixels = (int*)malloc(sizeof(int) * SIZE);
    for (int i = 0; i < SIZE; i++) {
        image->pixels[i] = rand() % 256;
    }
    return image;
}

void destroyImage(Image* image) {
    free(image->pixels);
    free(image);
}

void printImage(Image* image) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int index = y * WIDTH + x;
            printf("%d ", image->pixels[index]);
        }
        printf("\n");
    }
}

void addWatermark(Image* image, char* watermark) {
    int watermarkSize = strlen(watermark);
    if (watermarkSize > MAX_WATERMARK_SIZE) {
        watermarkSize = MAX_WATERMARK_SIZE;
    }
    int watermarkSeed = WATERMARK_SEED + rand();
    srand(watermarkSeed);
    for (int i = 0; i < SIZE; i++) {
        if (image->pixels[i] < 128) {
            image->pixels[i] += rand() % (watermarkSize + 1);
        }
    }
}

int main() {
    srand(time(NULL));
    Image* image = createImage();
    addWatermark(image, "My watermark");
    printImage(image);
    destroyImage(image);
    return 0;
}