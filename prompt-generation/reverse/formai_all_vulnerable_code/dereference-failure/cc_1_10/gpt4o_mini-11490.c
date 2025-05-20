//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 5
#define HEIGHT 5
#define MAX_WATERMARK_LENGTH 15

// Function to embed a watermark into an image
void embedWatermark(int image[HEIGHT][WIDTH][3], const char *watermark) {
    int watermarkLength = strlen(watermark);
    int k = 0;

    for (int i = 0; i < HEIGHT && k < watermarkLength; i++) {
        for (int j = 0; j < WIDTH && k < watermarkLength; j++) {
            // Retrieve current pixel (RGB)
            for (int color = 0; color < 3; color++) {
                // Adjust the least significant bit of the color value
                image[i][j][color] = (image[i][j][color] & ~1) | ((watermark[k] >> (2 - color)) & 1);
            }
            k++;
        }
    }
}

// Function to extract the watermark from an image
void extractWatermark(int image[HEIGHT][WIDTH][3], char *watermark) {
    int k = 0;

    for (int i = 0; i < HEIGHT && k < MAX_WATERMARK_LENGTH; i++) {
        for (int j = 0; j < WIDTH && k < MAX_WATERMARK_LENGTH; j++) {
            watermark[k] = 0; // Initialize the watermark character
            for (int color = 0; color < 3; color++) {
                // Retrieve the least significant bit
                watermark[k] |= (image[i][j][color] & 1) << (2 - color);
            }
            k++;
        }
    }
    watermark[k] = '\0'; // Null-terminate the watermark string
}

void printImage(int image[HEIGHT][WIDTH][3]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("(%d, %d, %d) ", image[i][j][0], image[i][j][1], image[i][j][2]);
        }
        printf("\n");
    }
}

int main() {
    int image[HEIGHT][WIDTH][3] = {
        {{255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 0}, {0, 255, 255}},
        {{255, 255, 255}, {128, 128, 128}, {64, 64, 64}, {0, 0, 0}, {255, 128, 0}},
        {{128, 128, 0}, {0, 128, 128}, {128, 0, 128}, {255, 128, 128}, {128, 255, 128}},
        {{128, 0, 0}, {0, 128, 0}, {0, 0, 128}, {150, 150, 150}, {200, 200, 200}},
        {{0, 0, 0}, {255, 0, 255}, {255, 255, 255}, {100, 0, 200}, {50, 100, 150}}
    };

    char watermark[MAX_WATERMARK_LENGTH] = "Hi!";
    printf("Original Image:\n");
    printImage(image);

    embedWatermark(image, watermark);
    printf("\nImage After Watermark Embedding:\n");
    printImage(image);

    char extractedWatermark[MAX_WATERMARK_LENGTH];
    extractWatermark(image, extractedWatermark);
    printf("\nExtracted Watermark: %s\n", extractedWatermark);

    return 0;
}