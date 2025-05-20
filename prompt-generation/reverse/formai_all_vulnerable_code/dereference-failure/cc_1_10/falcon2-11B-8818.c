//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the size of the image in pixels
#define WIDTH 800
#define HEIGHT 600

// Define the size of the watermark in pixels
#define WATERMARK_WIDTH 100
#define WATERMARK_HEIGHT 100

// Define the RGB values for the watermark
#define WATERMARK_RED 255
#define WATERMARK_GREEN 0
#define WATERMARK_BLUE 0

// Define the RGB values for the background
#define BACKGROUND_RED 255
#define BACKGROUND_GREEN 255
#define BACKGROUND_BLUE 255

// Define the RGB values for the overlay
#define OVERLAY_RED 0
#define OVERLAY_GREEN 0
#define OVERLAY_BLUE 0

// Define the position of the watermark in the image
#define WATERMARK_X 400
#define WATERMARK_Y 400

// Function to create the watermark image
void createWatermark() {
    // Create a new image with the size of the watermark
    unsigned char *watermark = (unsigned char*)malloc(WATERMARK_WIDTH * WATERMARK_HEIGHT * 3);
    
    // Initialize the watermark image
    for (int i = 0; i < WATERMARK_WIDTH * WATERMARK_HEIGHT * 3; i++) {
        watermark[i] = WATERMARK_RED;
    }
    
    // Save the watermark image
    FILE *fp = fopen("watermark.png", "wb");
    fwrite(watermark, sizeof(unsigned char), WATERMARK_WIDTH * WATERMARK_HEIGHT * 3, fp);
    fclose(fp);
}

// Function to create the overlay image
void createOverlay() {
    // Create a new image with the size of the background
    unsigned char *overlay = (unsigned char*)malloc(WIDTH * HEIGHT * 3);
    
    // Initialize the overlay image
    for (int i = 0; i < WIDTH * HEIGHT * 3; i++) {
        overlay[i] = BACKGROUND_RED;
    }
    
    // Save the overlay image
    FILE *fp = fopen("overlay.png", "wb");
    fwrite(overlay, sizeof(unsigned char), WIDTH * HEIGHT * 3, fp);
    fclose(fp);
}

// Function to create the final image
void createFinalImage() {
    // Create a new image with the size of the background
    unsigned char *finalImage = (unsigned char*)malloc(WIDTH * HEIGHT * 3);
    
    // Initialize the final image
    for (int i = 0; i < WIDTH * HEIGHT * 3; i++) {
        finalImage[i] = BACKGROUND_RED;
    }
    
    // Load the watermark and overlay images
    unsigned char *watermark = (unsigned char*)malloc(WATERMARK_WIDTH * WATERMARK_HEIGHT * 3);
    unsigned char *overlay = (unsigned char*)malloc(WIDTH * HEIGHT * 3);
    
    // Load the watermark image
    FILE *fp = fopen("watermark.png", "rb");
    fread(watermark, sizeof(unsigned char), WATERMARK_WIDTH * WATERMARK_HEIGHT * 3, fp);
    fclose(fp);
    
    // Load the overlay image
    fp = fopen("overlay.png", "rb");
    fread(overlay, sizeof(unsigned char), WIDTH * HEIGHT * 3, fp);
    fclose(fp);
    
    // Copy the watermark image to the final image
    for (int y = 0; y < WATERMARK_HEIGHT; y++) {
        for (int x = 0; x < WATERMARK_WIDTH; x++) {
            int index = (WATERMARK_X + x) * HEIGHT + WATERMARK_Y + y * HEIGHT;
            finalImage[index] = overlay[index];
        }
    }
    
    // Copy the overlay image to the final image
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int index = (x + WATERMARK_X) * HEIGHT + y * HEIGHT;
            finalImage[index] = overlay[index];
        }
    }
    
    // Save the final image
    fp = fopen("final.png", "wb");
    fwrite(finalImage, sizeof(unsigned char), WIDTH * HEIGHT * 3, fp);
    fclose(fp);
}

int main() {
    // Create the watermark image
    createWatermark();
    
    // Create the overlay image
    createOverlay();
    
    // Create the final image
    createFinalImage();
    
    return 0;
}