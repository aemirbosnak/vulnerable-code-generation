//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WATERMARK_SIZE 32
#define WATERMARK_VALUE 42

void add_watermark(unsigned char* watermark, unsigned char* image, int width, int height) {
    int i, j, k;
    int watermark_value = WATERMARK_VALUE;
    int watermark_size = WATERMARK_SIZE;
    int image_size = width * height;

    for (i = 0; i < watermark_size; i++) {
        for (j = 0; j < watermark_size; j++) {
            if (watermark[i * watermark_size + j] == 0) {
                watermark[i * watermark_size + j] = watermark_value;
            }
        }
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int index = i * width + j;
            int watermark_index = (i / watermark_size) * watermark_size + (j / watermark_size);

            if (image[index] < 128) {
                image[index] += watermark[watermark_index];
            } else {
                image[index] -= watermark[watermark_index];
            }
        }
    }
}

int main() {
    unsigned char* watermark = (unsigned char*)malloc(WATERMARK_SIZE * WATERMARK_SIZE);
    unsigned char* image = (unsigned char*)malloc(1024 * 1024);

    memset(watermark, 0, WATERMARK_SIZE * WATERMARK_SIZE);
    memset(image, 0, 1024 * 1024);

    add_watermark(watermark, image, 1024, 1024);

    FILE* fp = fopen("watermarked_image.bmp", "wb");
    fwrite(image, 1024 * 1024, 1, fp);
    fclose(fp);

    free(watermark);
    free(image);

    return 0;
}