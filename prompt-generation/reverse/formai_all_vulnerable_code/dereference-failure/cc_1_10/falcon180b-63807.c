//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_VALUE 255
#define THRESHOLD 0.5

typedef struct {
    int x, y;
    int value;
} Pixel;

void readImage(char *filename, Pixel *image) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: cannot open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);

    image = (Pixel *) malloc(filesize);

    fread(image, sizeof(Pixel), WIDTH*HEIGHT, fp);

    fclose(fp);
}

void writeImage(char *filename, Pixel *image) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: cannot open file %s\n", filename);
        exit(1);
    }

    fwrite(image, sizeof(Pixel), WIDTH*HEIGHT, fp);

    fclose(fp);
}

void addWatermark(Pixel *image, char *watermark) {
    int w = strlen(watermark);
    int x = (WIDTH - w) / 2;
    int y = (HEIGHT - 8) / 2;

    for (int i = 0; i < w; i++) {
        int value = (int) watermark[i] - 33;
        value = value * (MAX_VALUE / 94) + 1;
        image[y*WIDTH + x + i].value = value;
    }
}

void detectWatermark(Pixel *image, char *watermark) {
    int w = strlen(watermark);
    int x = (WIDTH - w) / 2;
    int y = (HEIGHT - 8) / 2;

    int sum = 0;
    for (int i = 0; i < w; i++) {
        int value = image[y*WIDTH + x + i].value;
        sum += value;
    }

    if (sum >= w*THRESHOLD) {
        printf("Watermark found!\n");
    } else {
        printf("Watermark not found.\n");
    }
}

int main() {
    Pixel image[WIDTH*HEIGHT];
    char watermark[100] = "Dennis Ritchie";

    readImage("image.bmp", image);

    addWatermark(image, watermark);

    writeImage("watermarked_image.bmp", image);

    detectWatermark(image, watermark);

    return 0;
}