//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WATERMARK_SIZE 100
#define IMAGE_SIZE 500

// Function to generate a random watermark
void generate_watermark(char* watermark, int size) {
    for (int i = 0; i < size; i++) {
        watermark[i] = rand() % 26 + 'a';
    }
    watermark[size] = '\0';
}

// Function to embed the watermark into the image
void embed_watermark(char* image, char* watermark, int size) {
    for (int i = 0; i < size; i++) {
        int index = rand() % IMAGE_SIZE;
        image[index] = watermark[i];
    }
}

// Function to extract the watermark from the image
char* extract_watermark(char* image, int size) {
    char* watermark = malloc(size + 1);
    for (int i = 0; i < size; i++) {
        int index = rand() % IMAGE_SIZE;
        if (image[index] >= 'a' && image[index] <= 'z') {
            watermark[i] = image[index];
        }
    }
    watermark[size] = '\0';
    return watermark;
}

int main() {
    char* image = malloc(IMAGE_SIZE + 1);
    char* watermark = malloc(WATERMARK_SIZE + 1);

    // Generate a random image
    for (int i = 0; i < IMAGE_SIZE; i++) {
        image[i] = rand() % 26 + 'a';
    }
    image[IMAGE_SIZE] = '\0';

    // Generate a random watermark
    generate_watermark(watermark, WATERMARK_SIZE);

    // Embed the watermark into the image
    embed_watermark(image, watermark, WATERMARK_SIZE);

    // Print the watermarked image
    printf("Watermarked image:\n%s\n", image);

    // Extract the watermark from the image
    char* extracted_watermark = extract_watermark(image, WATERMARK_SIZE);

    // Print the extracted watermark
    printf("Extracted watermark:\n%s\n", extracted_watermark);

    free(image);
    free(watermark);
    free(extracted_watermark);

    return 0;
}