//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

#define SIZE 1024   // The size of the image
#define MAX_THREADS 4   // The maximum number of threads

// The function to apply digital watermark
void digitalWatermark(int* image, char* watermark, int watermarkLen)
{
    int i, j, idx;
    #pragma omp parallel for shared(image, watermark) private(i, j, idx)
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            // Apply the watermark to the lower 2 bits of each pixel value
            idx = (i * SIZE + j) * 3;
            image[idx] = (image[idx] & 252) | ((watermark[(idx / 3) % watermarkLen] & 3) << 0);
            image[idx+1] = (image[idx+1] & 252) | ((watermark[(idx / 3) % watermarkLen] & 12) >> 2);
            image[idx+2] = (image[idx+2] & 252) | ((watermark[(idx / 3) % watermarkLen] & 48) >> 4);
        }
    }
}

int main() {
    int* image;
    char* watermark;
    int watermarkLen, i;
    FILE* imageFile;
    FILE* watermarkFile;

    // Read the image
    imageFile = fopen("image.dat", "r");
    if (!imageFile) {
        printf("Error opening image.dat\n");
        return 1;
    }
    image = (int*)malloc(sizeof(int) * SIZE * SIZE * 3);
    fread(image, sizeof(int), SIZE * SIZE * 3, imageFile);
    fclose(imageFile);

    // Read the watermark
    watermarkFile = fopen("watermark.dat", "r");
    if (!watermarkFile) {
        printf("Error opening watermark.dat\n");
        return 1;
    }
    fseek(watermarkFile, 0, SEEK_END);
    watermarkLen = ftell(watermarkFile);
    rewind(watermarkFile);
    watermark = (char*)malloc(sizeof(char) * watermarkLen);
    fread(watermark, sizeof(char), watermarkLen, watermarkFile);
    fclose(watermarkFile);

    // Apply digital watermark using multiple threads
    #pragma omp parallel num_threads(MAX_THREADS)
    {
        digitalWatermark(image, watermark, watermarkLen);
    }

    // Save the watermarked image
    imageFile = fopen("watermarked_image.dat", "w");
    if (!imageFile) {
        printf("Error opening watermarked_image.dat\n");
        return 1;
    }
    fwrite(image, sizeof(int), SIZE * SIZE * 3, imageFile);
    fclose(imageFile);

    // Free memory
    free(image);
    free(watermark);

    return 0;
}