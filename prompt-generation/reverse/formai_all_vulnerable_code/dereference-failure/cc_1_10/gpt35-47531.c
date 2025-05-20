//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Image dimensions
const int WIDTH = 800;
const int HEIGHT = 600;

// Brightness values
const int MAX_BRIGHTNESS = 255;
const int MIN_BRIGHTNESS = -255;

// Contrast values
const int MAX_CONTRAST = 100;
const int MIN_CONTRAST = -100;

// Function to flip an image horizontally
void flip_horizontal(unsigned char *image) {
    unsigned char *temp = (unsigned char *) malloc(WIDTH * 3 * sizeof(unsigned char));
    for (int y = 0; y < HEIGHT; y++) {
        int index = y * WIDTH * 3;
        for (int x = 0; x < WIDTH * 3; x += 3) {
            temp[x] = image[index + (WIDTH - 1 - x/3) * 3];
            temp[x + 1] = image[index + (WIDTH - 1 - x/3) * 3 + 1];
            temp[x + 2] = image[index + (WIDTH - 1 - x/3) * 3 + 2];
        }
        memcpy(&image[index], temp, WIDTH * 3);
    }
    free(temp);
}

// Function to adjust brightness
void adjust_brightness(unsigned char *image, int brightness) {
    for (int y = 0; y < HEIGHT; y++) {
        int index = y * WIDTH * 3;
        for (int x = 0; x < WIDTH * 3; x++) {
            int new_value = (int)image[index + x] + brightness;
            if (new_value < 0) {
                image[index + x] = 0;
            } else if (new_value > MAX_BRIGHTNESS) {
                image[index + x] = MAX_BRIGHTNESS;
            } else {
                image[index + x] = (unsigned char)new_value;
            }
        }
    }
}

// Function to adjust contrast
void adjust_contrast(unsigned char *image, int contrast) {
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for (int y = 0; y < HEIGHT; y++) {
        int index = y * WIDTH * 3;
        for (int x = 0; x < WIDTH * 3; x++) {
            int new_value = (int)(factor * ((float)image[index + x] - 128.0) + 128.0);
            if (new_value < 0) {
                image[index + x] = 0;
            } else if (new_value > MAX_BRIGHTNESS) {
                image[index + x] = MAX_BRIGHTNESS;
            } else {
                image[index + x] = (unsigned char)new_value;
            }
        }
    }
}

int main() {
    // Open image file for reading in binary mode
    FILE *file = fopen("image.bmp", "rb");
    if (!file) {
        printf("Error: Cannot open file\n");
        return 1;
    }

    // Read header information
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);

    // Read image data
    unsigned char *data = (unsigned char *)malloc(WIDTH * HEIGHT * 3 * sizeof(unsigned char));
    fread(data, sizeof(unsigned char), WIDTH * HEIGHT * 3, file);
    fclose(file);

    // Flip the image horizontally
    flip_horizontal(data);

    // Adjust the brightness by 50
    adjust_brightness(data, 50);

    // Adjust the contrast by -50
    adjust_contrast(data, -50);

    // Write the modified image to a new file
    FILE *outfile = fopen("modified.bmp", "wb");
    if (!outfile) {
        printf("Error: Cannot create file\n");
        return 1;
    }
    fwrite(header, sizeof(unsigned char), 54, outfile);
    fwrite(data, sizeof(unsigned char), WIDTH * HEIGHT * 3, outfile);
    fclose(outfile);

    // Free memory
    free(data);

    return 0;
}