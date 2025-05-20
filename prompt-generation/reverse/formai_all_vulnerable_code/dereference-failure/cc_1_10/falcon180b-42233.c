//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WATERMARK_SIZE 64
#define IMAGE_SIZE 512
#define IMAGE_WIDTH 64
#define IMAGE_HEIGHT 64

typedef struct {
    int x, y;
} Point;

typedef struct {
    int *data;
    int width;
    int height;
} Image;

void createRandomWatermark(int *watermark, int size) {
    for (int i = 0; i < size; i++) {
        watermark[i] = rand() % 256;
    }
}

void embedWatermark(Image *image, int *watermark, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int index = (i * size) + j;
            image->data[index] += watermark[index];
        }
    }
}

void extractWatermark(Image *image, int *watermark, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int index = (i * size) + j;
            watermark[index] = image->data[index];
        }
    }
}

int main() {
    Image image, watermark;
    int *watermarkData;

    srand(time(NULL));

    // Create a random watermark
    watermark.width = WATERMARK_SIZE;
    watermark.height = WATERMARK_SIZE;
    watermark.data = (int *)malloc(watermark.width * watermark.height * sizeof(int));
    createRandomWatermark(watermark.data, watermark.width * watermark.height);

    // Create an image to embed the watermark
    image.width = IMAGE_WIDTH;
    image.height = IMAGE_HEIGHT;
    image.data = (int *)malloc(image.width * image.height * sizeof(int));
    for (int i = 0; i < image.width * image.height; i++) {
        image.data[i] = rand() % 256;
    }

    // Embed the watermark in the image
    embedWatermark(&image, watermark.data, watermark.width * watermark.height);

    // Extract the watermark from the image
    watermarkData = (int *)malloc(watermark.width * watermark.height * sizeof(int));
    extractWatermark(&image, watermarkData, watermark.width * watermark.height);

    // Print the extracted watermark
    printf("Extracted watermark:\n");
    for (int i = 0; i < watermark.width * watermark.height; i++) {
        printf("%d ", watermarkData[i]);
    }
    printf("\n");

    free(watermark.data);
    free(image.data);
    free(watermarkData);

    return 0;
}