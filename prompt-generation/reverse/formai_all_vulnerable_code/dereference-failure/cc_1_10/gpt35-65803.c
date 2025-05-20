//FormAI DATASET v1.0 Category: Image Editor ; Style: intelligent
// A unique C Image Editor program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to load an image file
void load_image(char *file_name, unsigned char *image_data, int width, int height) {
    FILE *fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("Error: Failed to open file.\n");
        return;
    }
    fread(image_data, 1, width*height*3, fp);
    fclose(fp);
}

// Function to save an image file
void save_image(char *file_name, unsigned char *image_data, int width, int height) {
    FILE *fp = fopen(file_name, "wb");
    if (fp == NULL) {
        printf("Error: Failed to open file.\n");
        return;
    }
    fwrite(image_data, 1, width*height*3, fp);
    fclose(fp);
}

// Function to invert the colors of an image
void invert_colors(unsigned char *image_data, int width, int height) {
    int i;
    for (i = 0; i < width*height*3; i++) {
        image_data[i] = 255 - image_data[i];
    }
}

// Function to adjust the brightness of an image
void adjust_brightness(unsigned char *image_data, int width, int height, int delta) {
    int i;
    for (i = 0; i < width*height*3; i++) {
        int value = image_data[i] + delta;
        if (value < 0) {
            image_data[i] = 0;
        }
        else if (value > 255) {
            image_data[i] = 255;
        }
        else {
            image_data[i] = (unsigned char) value;
        }
    }
}

// Function to apply a Gaussian blur to an image
void gaussian_blur(unsigned char *image_data, int width, int height) {
    unsigned char *temp_data = (unsigned char*) malloc(width*height*3);
    memcpy(temp_data, image_data, width*height*3); // copy image_data to temp_data

    // Gaussian blur kernel
    float kernel[25] = { 0.003765, 0.015019, 0.023792, 0.015019, 0.003765,
                         0.015019, 0.059912, 0.094907, 0.059912, 0.015019,
                         0.023792, 0.094907, 0.150342, 0.094907, 0.023792,
                         0.015019, 0.059912, 0.094907, 0.059912, 0.015019,
                         0.003765, 0.015019, 0.023792, 0.015019, 0.003765 };

    int x, y, i, j, k;
    for (y = 2; y < height-2; y++) {
        for (x = 2; x < width-2; x++) {
            float r = 0, g = 0, b = 0;
            k = 0;
            for (j = y-2; j <= y+2; j++) {
                for (i = x-2; i <= x+2; i++) {
                    r += temp_data[(j*width+i)*3] * kernel[k];
                    g += temp_data[(j*width+i)*3+1] * kernel[k];
                    b += temp_data[(j*width+i)*3+2] * kernel[k];
                    k++;
                }
            }
            image_data[(y*width+x)*3] = (unsigned char) r;
            image_data[(y*width+x)*3+1] = (unsigned char) g;
            image_data[(y*width+x)*3+2] = (unsigned char) b;
        }
    }
    free(temp_data);
}

int main() {
    // Load image into memory
    const char* file_name = "input.jpg";
    int width = 800, height = 600;
    unsigned char* image_data = (unsigned char*) malloc(width*height*3);
    load_image((char*)file_name, image_data, width, height);

    // Invert colors
    invert_colors(image_data, width, height);

    // Adjust brightness
    int brightness_delta = 40;
    adjust_brightness(image_data, width, height, brightness_delta);

    // Apply Gaussian blur
    gaussian_blur(image_data, width, height);

    // Save edited image
    const char* output_file_name = "output.jpg";
    save_image((char*)output_file_name, image_data, width, height);

    // Free memory
    free(image_data);

    return 0;
}