//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80    // maximum width of ASCII art output
#define MAX_HEIGHT 80   // maximum height of ASCII art output

/* Function to convert image to ASCII art */
void image_to_ascii(char *img_path) {
    FILE *fp;
    char *pixels;
    char ascii_pixels[MAX_HEIGHT][MAX_WIDTH];
    int width, height, i, j;
    float pixel_ratio;
    char *ascii_chars[11] = {" ", ".", ":", "-", "=", "+", "*", "#", "%", "@", "$"};

    // Open image file in binary mode
    fp = fopen(img_path, "rb");

    // Check if file exists
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", img_path);
        return;
    }

    // Read image dimensions
    fseek(fp, 18, SEEK_SET);
    fread(&width, 4, 1, fp);
    fread(&height, 4, 1, fp);

    // Calculate pixel ratio for image resizing
    pixel_ratio = (float)height / MAX_HEIGHT;

    // Allocate memory for pixel data
    pixels = (char*)calloc(width * height * 3, sizeof(char));

    // Read pixel data
    fseek(fp, 54, SEEK_SET);
    fread(pixels, sizeof(char), width * height * 3, fp);

    // Close image file
    fclose(fp);

    // Convert pixel data to ASCII art
    for (i = 0; i < MAX_HEIGHT; i++) {
        for (j = 0; j < MAX_WIDTH; j++) {
            float original_pixel_x = j * pixel_ratio;
            float original_pixel_y = i * pixel_ratio;
            int original_pixel_index = ((int)original_pixel_y * width + (int)original_pixel_x) * 3;
            int avg_pixel_value = (pixels[original_pixel_index] + pixels[original_pixel_index + 1] + pixels[original_pixel_index + 2]) / 3;
            int ascii_index = ((float)avg_pixel_value / 255) * 10;
            ascii_pixels[i][j] = *ascii_chars[ascii_index];
        }
        ascii_pixels[i][MAX_WIDTH] = '\0';
    }

    // Print ASCII art to console
    for (i = 0; i < MAX_HEIGHT; i++) {
        printf("%s\n", ascii_pixels[i]);
    }

    // Free allocated memory
    free(pixels);
}

int main() {
    char *img_path = "example_image.bmp";
    image_to_ascii(img_path);
    return 0;
}