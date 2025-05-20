//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define IMAGE_WIDTH 256
#define IMAGE_HEIGHT 256

// Function to read image from file
void readImage(char* filename, unsigned char* image) {
    FILE* fp = fopen(filename, "rb");
    fread(image, IMAGE_WIDTH * IMAGE_HEIGHT, 1, fp);
    fclose(fp);
}

// Function to write image to file
void writeImage(char* filename, unsigned char* image) {
    FILE* fp = fopen(filename, "wb");
    fwrite(image, IMAGE_WIDTH * IMAGE_HEIGHT, 1, fp);
    fclose(fp);
}

// Function to embed watermark in image
void embedWatermark(unsigned char* image, unsigned char* watermark) {
    int i, j;
    for (i = 0; i < IMAGE_HEIGHT; i++) {
        for (j = 0; j < IMAGE_WIDTH; j++) {
            int value = image[i * IMAGE_WIDTH + j];
            value += watermark[i * IMAGE_WIDTH + j] / 2;
            if (value > 255) {
                value = 255;
            }
            image[i * IMAGE_WIDTH + j] = value;
        }
    }
}

// Function to extract watermark from image
void extractWatermark(unsigned char* image, unsigned char* watermark) {
    int i, j;
    for (i = 0; i < IMAGE_HEIGHT; i++) {
        for (j = 0; j < IMAGE_WIDTH; j++) {
            int value = image[i * IMAGE_WIDTH + j];
            watermark[i * IMAGE_WIDTH + j] = value - (value / 2);
        }
    }
}

int main(int argc, char** argv) {
    if (argc!= 4) {
        printf("Usage: %s <image_file> <watermark_file> <output_file>\n", argv[0]);
        return 1;
    }

    char* input_image_file = argv[1];
    char* watermark_file = argv[2];
    char* output_image_file = argv[3];

    unsigned char* input_image = (unsigned char*)malloc(IMAGE_WIDTH * IMAGE_HEIGHT);
    unsigned char* watermark = (unsigned char*)malloc(IMAGE_WIDTH * IMAGE_HEIGHT);

    readImage(input_image_file, input_image);
    readImage(watermark_file, watermark);

    embedWatermark(input_image, watermark);

    writeImage(output_image_file, input_image);

    free(input_image);
    free(watermark);

    return 0;
}