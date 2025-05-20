//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define WIDTH 512
#define HEIGHT 512
#define WATERMARK_WIDTH 64
#define WATERMARK_HEIGHT 64
#define MAX_VALUE 255
#define MIN_VALUE 0

typedef struct {
    int x, y;
} Point;

typedef struct {
    int *data;
    int width;
    int height;
} Image;

void loadImage(Image *image, char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error loading image: %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    rewind(fp);

    image->data = malloc(filesize);
    fread(image->data, filesize, 1, fp);

    fclose(fp);

    image->width = WIDTH;
    image->height = HEIGHT;
}

void saveImage(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error saving image: %s\n", filename);
        exit(1);
    }

    fwrite(image->data, image->width * image->height, 1, fp);

    fclose(fp);
}

void addWatermark(Image *image, Image *watermark) {
    int x = (image->width - watermark->width) / 2;
    int y = (image->height - watermark->height) / 2;

    for (int i = 0; i < watermark->height; i++) {
        for (int j = 0; j < watermark->width; j++) {
            int value = (*(watermark->data + i * watermark->width + j)) * (MAX_VALUE - MIN_VALUE) / MAX_VALUE + MIN_VALUE;
            int index = (i + y) * image->width + (j + x);
            *(image->data + index) = value;
        }
    }
}

void printImage(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int value = (*(image->data + i * image->width + j)) * (MAX_VALUE - MIN_VALUE) / MAX_VALUE + MIN_VALUE;
            printf("%d ", value);
        }
        printf("\n");
    }
}

void main() {
    srand(time(NULL));

    Image image, watermark;

    loadImage(&image, "image.bmp");
    loadImage(&watermark, "watermark.bmp");

    addWatermark(&image, &watermark);

    saveImage(&image, "watermarked.bmp");

    printImage(&image);
}