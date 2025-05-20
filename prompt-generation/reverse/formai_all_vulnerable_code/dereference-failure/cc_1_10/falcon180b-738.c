//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_VALUE 255
#define THRESHOLD 0.1

typedef struct {
    int x, y;
    int value;
} Pixel;

void readImage(char* filename, Pixel* pixels) {
    FILE* fp = fopen(filename, "rb");
    if(fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    pixels = (Pixel*)malloc(filesize);
    fread(pixels, sizeof(Pixel), filesize / sizeof(Pixel), fp);

    fclose(fp);
}

void writeImage(char* filename, Pixel* pixels) {
    FILE* fp = fopen(filename, "wb");
    if(fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fwrite(pixels, sizeof(Pixel), WIDTH * HEIGHT, fp);

    fclose(fp);
}

void addWatermark(Pixel* image, Pixel* watermark, int alpha) {
    for(int i = 0; i < WIDTH * HEIGHT; i++) {
        if(image[i].value < THRESHOLD) {
            image[i].value = 0;
        } else {
            image[i].value = (int)((double)image[i].value * (1 - alpha) + (double)watermark[i].value * alpha);
        }
    }
}

void removeWatermark(Pixel* image, Pixel* watermark) {
    for(int i = 0; i < WIDTH * HEIGHT; i++) {
        if(image[i].value == watermark[i].value) {
            image[i].value = 0;
        }
    }
}

int main() {
    Pixel image[WIDTH * HEIGHT];
    Pixel watermark[WIDTH * HEIGHT];

    readImage("image.bmp", image);
    readImage("watermark.bmp", watermark);

    addWatermark(image, watermark, 0.5);

    writeImage("watermarked_image.bmp", image);

    removeWatermark(image, watermark);

    writeImage("removed_watermark_image.bmp", image);

    return 0;
}