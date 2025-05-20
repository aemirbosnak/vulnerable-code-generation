//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define WATERMARK_SIZE 10
#define WATERMARK_VALUE 42

int main() {
    srand(time(NULL));

    // Generate a random image
    int width = rand() % 100 + 100;
    int height = rand() % 100 + 100;
    int* image = (int*) malloc(width * height * sizeof(int));
    for (int i = 0; i < width * height; i++) {
        image[i] = rand() % 256;
    }

    // Embed the watermark
    int watermark[WATERMARK_SIZE][WATERMARK_SIZE] = {{0}};
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        for (int j = 0; j < WATERMARK_SIZE; j++) {
            watermark[i][j] = WATERMARK_VALUE;
        }
    }
    int watermark_pos = rand() % (width - WATERMARK_SIZE) + 1;
    int watermark_size = rand() % (height - WATERMARK_SIZE) + 1;
    for (int i = 0; i < watermark_size; i++) {
        for (int j = 0; j < watermark_size; j++) {
            int index = (watermark_pos + i) * width + (watermark_pos + j);
            if (index >= 0 && index < width * height) {
                image[index] = WATERMARK_VALUE;
            }
        }
    }

    // Save the watermarked image
    FILE* fp = fopen("watermarked.bmp", "wb");
    if (fp == NULL) {
        printf("Error: Failed to save watermarked image.\n");
        return 1;
    }
    fprintf(fp, "BM");
    fwrite(&width, sizeof(int), 1, fp);
    fwrite(&height, sizeof(int), 1, fp);
    fwrite(image, sizeof(int), width * height, fp);
    fclose(fp);

    printf("Watermarked image saved as watermarked.bmp.\n");

    return 0;
}