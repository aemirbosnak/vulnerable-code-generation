//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <assert.h>

#define WATERMARK_SIZE 256
#define IMAGE_SIZE 512

// function to generate watermark
void generate_watermark(int* watermark) {
    srand(time(NULL));
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        watermark[i] = rand() % 256;
    }
}

// function to embed watermark in image
void embed_watermark(int* image, int* watermark) {
    for (int i = 0; i < IMAGE_SIZE; i++) {
        int watermark_index = i % WATERMARK_SIZE;
        int image_index = i / WATERMARK_SIZE;
        int bit = watermark[watermark_index] & 1;
        if (bit) {
            image[image_index] += 1;
        } else {
            image[image_index] -= 1;
        }
    }
}

// function to extract watermark from image
void extract_watermark(int* image, int* watermark) {
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        int sum = 0;
        for (int j = i * IMAGE_SIZE / WATERMARK_SIZE; j < (i + 1) * IMAGE_SIZE / WATERMARK_SIZE; j++) {
            sum += image[j];
        }
        watermark[i] = (sum > 0)? 1 : 0;
    }
}

int main() {
    int* image = (int*) malloc(IMAGE_SIZE * sizeof(int));
    int* watermark = (int*) malloc(WATERMARK_SIZE * sizeof(int));

    generate_watermark(watermark);
    for (int i = 0; i < IMAGE_SIZE; i++) {
        image[i] = rand() % 256;
    }

    embed_watermark(image, watermark);

    for (int i = 0; i < IMAGE_SIZE; i++) {
        printf("%d ", image[i]);
    }
    printf("\n");

    int* extracted_watermark = (int*) malloc(WATERMARK_SIZE * sizeof(int));
    extract_watermark(image, extracted_watermark);

    for (int i = 0; i < WATERMARK_SIZE; i++) {
        printf("%d ", extracted_watermark[i]);
    }
    printf("\n");

    free(image);
    free(watermark);
    free(extracted_watermark);

    return 0;
}