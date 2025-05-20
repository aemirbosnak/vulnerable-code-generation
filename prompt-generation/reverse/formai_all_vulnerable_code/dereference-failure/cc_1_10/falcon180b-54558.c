//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_VALUE 255
#define WATERMARK_VALUE 128
#define THRESHOLD 0.1

typedef struct {
    int x, y;
} Point;

typedef struct {
    int width, height;
    int **data;
} Image;

void createImage(Image *image) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            image->data[i][j] = rand() % MAX_VALUE;
        }
    }
}

void printImage(Image *image) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            printf("%d ", image->data[i][j]);
        }
        printf("\n");
    }
}

void addWatermark(Image *image, int x, int y, int value) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            if (image->data[i][j] < THRESHOLD && (sqrt(pow(i - x, 2) + pow(j - y, 2)) < 50)) {
                image->data[i][j] += value;
            }
        }
    }
}

void detectWatermark(Image *image, Point *watermark) {
    int i, j;
    int count = 0;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            if (image->data[i][j] == WATERMARK_VALUE) {
                count++;
            }
        }
    }
    if (count > 0) {
        watermark->x = count / image->height;
        watermark->y = count % image->height;
    } else {
        watermark->x = -1;
        watermark->y = -1;
    }
}

int main() {
    Image image1, image2;
    Point watermark;

    createImage(&image1);
    createImage(&image2);

    addWatermark(&image2, 100, 100, WATERMARK_VALUE);

    detectWatermark(&image2, &watermark);

    printf("Watermark detected at (%d, %d)\n", watermark.x, watermark.y);

    return 0;
}