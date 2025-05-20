//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_VALUE 255
#define THRESHOLD 0.7

typedef struct {
    int x, y;
    int value;
} Point;

void readImage(char *filename, int **image) {
    FILE *fp = fopen(filename, "rb");
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    *image = (int *)malloc(size);
    fread(*image, sizeof(int), WIDTH * HEIGHT, fp);
    fclose(fp);
}

void writeImage(char *filename, int *image) {
    FILE *fp = fopen(filename, "wb");
    fwrite(image, sizeof(int), WIDTH * HEIGHT, fp);
    fclose(fp);
}

void addWatermark(int *image, int *watermark) {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        int value = (int)round(MAX_VALUE * (image[i] + watermark[i] / THRESHOLD));
        image[i] = value;
    }
}

void detectWatermark(int *image, int *watermark) {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        if (image[i] > MAX_VALUE * THRESHOLD && watermark[i] > 0) {
            printf("Watermark detected at (%d, %d)\n", i % WIDTH, i / WIDTH);
        }
    }
}

int main() {
    char filename[100];
    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    int *image = NULL;
    readImage(filename, &image);

    char watermark[100];
    printf("Enter the name of the watermark image file: ");
    scanf("%s", watermark);

    int *watermarkImage = NULL;
    readImage(watermark, &watermarkImage);

    addWatermark(image, watermarkImage);

    writeImage("watermarked.bmp", image);

    detectWatermark(image, watermarkImage);

    free(image);
    free(watermarkImage);

    return 0;
}