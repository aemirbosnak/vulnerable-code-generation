//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

#define WATERMARK_SIZE 512
#define WATERMARK_VALUE 42

void generate_watermark(unsigned char *watermark, int size) {
    for (int i = 0; i < size; i++) {
        watermark[i] = rand() % 256;
    }
}

void embed_watermark(unsigned char *image, int width, int height, unsigned char *watermark, int watermark_size) {
    int image_size = width * height * 3;
    unsigned char *image_data = (unsigned char *)malloc(image_size);
    memcpy(image_data, image, image_size);

    int watermark_offset = 0;
    while (watermark_offset < image_size - watermark_size) {
        for (int i = 0; i < watermark_size; i++) {
            image_data[watermark_offset + i] += watermark[i];
        }
        watermark_offset += watermark_size;
    }

    memcpy(image, image_data, image_size);
    free(image_data);
}

void extract_watermark(unsigned char *image, int width, int height, unsigned char *watermark, int watermark_size) {
    int image_size = width * height * 3;
    unsigned char *image_data = (unsigned char *)malloc(image_size);
    memcpy(image_data, image, image_size);

    int watermark_offset = 0;
    while (watermark_offset < image_size - watermark_size) {
        int sum = 0;
        for (int i = 0; i < watermark_size; i++) {
            sum += image_data[watermark_offset + i];
        }
        if (sum == watermark_size * WATERMARK_VALUE) {
            memcpy(watermark, image_data + watermark_offset, watermark_size);
            break;
        }
        watermark_offset += watermark_size;
    }

    free(image_data);
}

int main() {
    srand(time(NULL));

    unsigned char *image_data = (unsigned char *)malloc(WATERMARK_SIZE * 3);
    for (int i = 0; i < WATERMARK_SIZE * 3; i++) {
        image_data[i] = rand() % 256;
    }

    unsigned char *watermark = (unsigned char *)malloc(WATERMARK_SIZE);
    generate_watermark(watermark, WATERMARK_SIZE);

    embed_watermark(image_data, WATERMARK_SIZE, 1, watermark, WATERMARK_SIZE);

    printf("Embedded watermark:\n");
    for (int i = 0; i < WATERMARK_SIZE * 3; i++) {
        printf("%02X ", image_data[i]);
    }
    printf("\n");

    unsigned char *extracted_watermark = (unsigned char *)malloc(WATERMARK_SIZE);
    extract_watermark(image_data, WATERMARK_SIZE, 1, extracted_watermark, WATERMARK_SIZE);

    printf("Extracted watermark:\n");
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        printf("%02X ", extracted_watermark[i]);
    }
    printf("\n");

    free(image_data);
    free(watermark);
    free(extracted_watermark);

    return 0;
}