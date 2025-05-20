//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Function to print the image for demonstration
void printImage(int **image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%3d ", image[i][j]);
        }
        printf("\n");
    }
}

// Function to embed a watermark
void embedWatermark(int **image, int width, int height, int **watermark, int wm_width, int wm_height) {
    for (int i = 0; i < wm_height; i++) {
        for (int j = 0; j < wm_width; j++) {
            // Ensure we don't run out of bounds
            if (i < height && j < width) {
                // Simple procedure to combine image and watermark pixel
                image[i][j] = (image[i][j] * 0.8) + (watermark[i][j] * 0.2);
            }
        }
    }
}

// Main function to demonstrate the watermarking
int main() {
    int width = 8, height = 8; // Size of the main image
    int wm_width = 4, wm_height = 4; // Size of the watermark

    // Create a sample grayscale image (8x8)
    int **image = malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        image[i] = malloc(width * sizeof(int));
        for (int j = 0; j < width; j++) {
            image[i][j] = rand() % 256; // Random grayscale values
        }
    }

    // Create a sample watermark (4x4)
    int **watermark = malloc(wm_height * sizeof(int *));
    for (int i = 0; i < wm_height; i++) {
        watermark[i] = malloc(wm_width * sizeof(int));
        for (int j = 0; j < wm_width; j++) {
            watermark[i][j] = (i + j) * (255 / (wm_width + wm_height)); // Gradual pattern
        }
    }

    printf("Original Image:\n");
    printImage(image, width, height);

    // Embed watermark into image
    embedWatermark(image, width, height, watermark, wm_width, wm_height);

    printf("\nWatermarked Image:\n");
    printImage(image, width, height);

    // Free allocated memory
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    for (int i = 0; i < wm_height; i++) {
        free(watermark[i]);
    }
    free(watermark);

    return 0;
}