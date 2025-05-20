//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define IMAGE_WIDTH 8
#define IMAGE_HEIGHT 8
#define WATERMARK_WIDTH 3
#define WATERMARK_HEIGHT 3

// Function to display the image
void display_image(uint8_t image[IMAGE_HEIGHT][IMAGE_WIDTH]) {
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            printf("%3d ", image[i][j]);
        }
        printf("\n");
    }
}

// Function to embed a watermark into an image
void embed_watermark(uint8_t image[IMAGE_HEIGHT][IMAGE_WIDTH], uint8_t watermark[WATERMARK_HEIGHT][WATERMARK_WIDTH], int start_x, int start_y) {
    for (int i = 0; i < WATERMARK_HEIGHT; i++) {
        for (int j = 0; j < WATERMARK_WIDTH; j++) {
            if ((start_x + i < IMAGE_HEIGHT) && (start_y + j < IMAGE_WIDTH)) {
                // Embed the watermark using XOR operation
                image[start_x + i][start_y + j] ^= watermark[i][j];
            }
        }
    }
}

// Function to extract the watermark from the image
void extract_watermark(uint8_t image[IMAGE_HEIGHT][IMAGE_WIDTH], uint8_t watermark[WATERMARK_HEIGHT][WATERMARK_WIDTH], int start_x, int start_y) {
    for (int i = 0; i < WATERMARK_HEIGHT; i++) {
        for (int j = 0; j < WATERMARK_WIDTH; j++) {
            if ((start_x + i < IMAGE_HEIGHT) && (start_y + j < IMAGE_WIDTH)) {
                // Extract the watermark using XOR operation
                watermark[i][j] = image[start_x + i][start_y + j] ^ (255);  // Assuming original pixel value was 255
            }
        }
    }
}

int main() {
    // Sample grayscale image (8x8)
    uint8_t image[IMAGE_HEIGHT][IMAGE_WIDTH] = {
        {255, 255, 255, 255, 255, 255, 255, 255},
        {255, 200, 200, 200, 200, 255, 255, 255},
        {255, 200, 255, 255, 200, 255, 255, 255},
        {255, 200, 255, 200, 200, 255, 255, 255},
        {255, 255, 255, 255, 255, 255, 255, 255},
        {255, 255, 255, 255, 255, 255, 255, 255},
        {255, 255, 255, 255, 255, 255, 255, 255},
        {255, 255, 255, 255, 255, 255, 255, 255}
    };

    // Sample watermark (3x3)
    uint8_t watermark[WATERMARK_HEIGHT][WATERMARK_WIDTH] = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    int start_x = 1, start_y = 1;

    printf("Original Image:\n");
    display_image(image);

    // Embed the watermark
    embed_watermark(image, watermark, start_x, start_y);
    printf("\nImage After Watermarking:\n");
    display_image(image);

    // Prepare to extract the watermark
    uint8_t extracted_watermark[WATERMARK_HEIGHT][WATERMARK_WIDTH] = {0};

    // Extract the watermark
    extract_watermark(image, extracted_watermark, start_x, start_y);
    printf("\nExtracted Watermark:\n");
    display_image(extracted_watermark);

    return 0;
}