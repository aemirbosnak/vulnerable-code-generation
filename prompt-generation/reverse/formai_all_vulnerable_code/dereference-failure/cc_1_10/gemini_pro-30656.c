//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 512

void embed_watermark(unsigned char *image, int width, int height, unsigned char *watermark, int watermark_width, int watermark_height) {
    int i, j, k, l;
    double alpha = 0.05; // watermark strength

    for (i = 0; i < height - watermark_height; i++) {
        for (j = 0; j < width - watermark_width; j++) {
            for (k = 0; k < watermark_height; k++) {
                for (l = 0; l < watermark_width; l++) {
                    if (watermark[k * watermark_width + l] == 0) {
                        image[(i + k) * width + (j + l)] -= alpha * (image[(i + k) * width + (j + l)] - 128);
                    } else {
                        image[(i + k) * width + (j + l)] += alpha * (image[(i + k) * width + (j + l)] - 128);
                    }
                }
            }
        }
    }
}

void extract_watermark(unsigned char *image, int width, int height, unsigned char *watermark, int watermark_width, int watermark_height) {
    int i, j, k, l;
    double alpha = 0.05; // watermark strength
    unsigned char *watermark_extracted = (unsigned char *)malloc(watermark_width * watermark_height * sizeof(unsigned char));

    for (i = 0; i < height - watermark_height; i++) {
        for (j = 0; j < width - watermark_width; j++) {
            for (k = 0; k < watermark_height; k++) {
                for (l = 0; l < watermark_width; l++) {
                    watermark_extracted[k * watermark_width + l] += (image[(i + k) * width + (j + l)] - 128) / alpha;
                }
            }
        }
    }

    for (i = 0; i < watermark_height; i++) {
        for (j = 0; j < watermark_width; j++) {
            watermark[i * watermark_width + j] = (watermark_extracted[i * watermark_width + j] > 127) ? 255 : 0;
        }
    }

    free(watermark_extracted);
}

int main() {
    unsigned char *image = (unsigned char *)malloc(MAX_SIZE * MAX_SIZE * sizeof(unsigned char));
    unsigned char *watermark = (unsigned char *)malloc(MAX_SIZE * MAX_SIZE * sizeof(unsigned char));

    int width, height;

    // Read the input image
    FILE *fp = fopen("input.bmp", "rb");
    fread(image, MAX_SIZE * MAX_SIZE * sizeof(unsigned char), 1, fp);
    fclose(fp);

    // Read the watermark image
    fp = fopen("watermark.bmp", "rb");
    fread(watermark, MAX_SIZE * MAX_SIZE * sizeof(unsigned char), 1, fp);
    fclose(fp);

    // Get the width and height of the input image
    width = MAX_SIZE;
    height = MAX_SIZE;

    // Embed the watermark in the input image
    embed_watermark(image, width, height, watermark, 32, 32);

    // Write the watermarked image to a file
    fp = fopen("output.bmp", "wb");
    fwrite(image, MAX_SIZE * MAX_SIZE * sizeof(unsigned char), 1, fp);
    fclose(fp);

    // Extract the watermark from the watermarked image
    extract_watermark(image, width, height, watermark, 32, 32);

    // Write the extracted watermark to a file
    fp = fopen("extracted_watermark.bmp", "wb");
    fwrite(watermark, MAX_SIZE * MAX_SIZE * sizeof(unsigned char), 1, fp);
    fclose(fp);

    // Free the allocated memory
    free(image);
    free(watermark);

    return 0;
}