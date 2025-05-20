//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512
#define WATERMARK_WIDTH 64
#define WATERMARK_HEIGHT 64

unsigned char image[IMAGE_WIDTH][IMAGE_HEIGHT];
unsigned char watermark[WATERMARK_WIDTH][WATERMARK_HEIGHT];
unsigned char watermarkedImage[IMAGE_WIDTH][IMAGE_HEIGHT];

void readImage(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }
    fread(image, sizeof(unsigned char), IMAGE_WIDTH * IMAGE_HEIGHT, file);
    fclose(file);
}

void readWatermark(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }
    fread(watermark, sizeof(unsigned char), WATERMARK_WIDTH * WATERMARK_HEIGHT, file);
    fclose(file);
}

void writeImage(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }
    fwrite(watermarkedImage, sizeof(unsigned char), IMAGE_WIDTH * IMAGE_HEIGHT, file);
    fclose(file);
}

void embedWatermark() {
    for (int i = 0; i < IMAGE_WIDTH; i++) {
        for (int j = 0; j < IMAGE_HEIGHT; j++) {
            if (i % WATERMARK_WIDTH == 0 && j % WATERMARK_HEIGHT == 0) {
                watermarkedImage[i][j] = (image[i][j] & 0xF0) | (watermark[i / WATERMARK_WIDTH][j / WATERMARK_HEIGHT] & 0x0F);
            } else {
                watermarkedImage[i][j] = image[i][j];
            }
        }
    }
}

void extractWatermark() {
    for (int i = 0; i < IMAGE_WIDTH; i++) {
        for (int j = 0; j < IMAGE_HEIGHT; j++) {
            if (i % WATERMARK_WIDTH == 0 && j % WATERMARK_HEIGHT == 0) {
                watermark[i / WATERMARK_WIDTH][j / WATERMARK_HEIGHT] = watermarkedImage[i][j] & 0x0F;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <image> <watermark> <watermarked_image> <extract>\n", argv[0]);
        return 1;
    }

    readImage(argv[1]);
    readWatermark(argv[2]);

    if (strcmp(argv[4], "embed") == 0) {
        embedWatermark();
        writeImage(argv[3]);
        printf("Watermark embedded successfully.\n");
    } else if (strcmp(argv[4], "extract") == 0) {
        extractWatermark();
        writeImage(argv[3]);
        printf("Watermark extracted successfully.\n");
    } else {
        printf("Invalid argument: %s\n", argv[4]);
        return 1;
    }

    return 0;
}