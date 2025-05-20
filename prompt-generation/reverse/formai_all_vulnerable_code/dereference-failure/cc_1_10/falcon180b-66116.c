//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

// Function to generate watermark
void generate_watermark(int *watermark, int size, int strength) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        watermark[i] = rand() % 256;
    }
    for (int i = 0; i < size; i++) {
        watermark[i] += strength;
        if (watermark[i] > 255) {
            watermark[i] = 255;
        }
    }
}

// Function to embed watermark in image
void embed_watermark(int *image, int *watermark, int size, int strength) {
    for (int i = 0; i < size; i++) {
        image[i] += watermark[i] * strength;
    }
}

// Function to extract watermark from image
int extract_watermark(int *image, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += image[i];
    }
    return sum;
}

// Function to check if watermark is present in image
int check_watermark(int *image, int *watermark, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += image[i] - watermark[i];
    }
    if (sum == 0) {
        return TRUE;
    }
    return FALSE;
}

int main() {
    // Example usage
    int image_size = 100;
    int watermark_size = 10;
    int watermark_strength = 5;
    int *image = (int *)malloc(image_size * sizeof(int));
    int *watermark = (int *)malloc(watermark_size * sizeof(int));
    generate_watermark(watermark, watermark_size, watermark_strength);
    embed_watermark(image, watermark, image_size, watermark_strength);
    int extracted_watermark = extract_watermark(image, image_size);
    if (check_watermark(image, watermark, image_size)) {
        printf("Watermark found!\n");
    } else {
        printf("Watermark not found.\n");
    }
    free(image);
    free(watermark);
    return 0;
}