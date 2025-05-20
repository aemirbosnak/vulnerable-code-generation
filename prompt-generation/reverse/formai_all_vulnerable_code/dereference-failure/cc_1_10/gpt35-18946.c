//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function flips the image vertically
void flip_vertical(unsigned char* buffer, int width, int height) {
    int row_size = width * 3;
    unsigned char* row_buffer = malloc(row_size * sizeof(unsigned char));

    for(int row = 0; row < height / 2; row++) {
        memcpy(row_buffer, buffer + row * row_size, row_size);
        memcpy(buffer + row * row_size, buffer + (height - row - 1) * row_size, row_size);
        memcpy(buffer + (height - row - 1) * row_size, row_buffer, row_size);
    }

    free(row_buffer);
}

// This function adjusts the brightness of the image by a given value
void adjust_brightness(unsigned char* buffer, int width, int height, int brightness) {
    for(int i = 0; i < width * height * 3; i++) {
        int new_value = buffer[i] + brightness;
        if(new_value < 0) new_value = 0;
        if(new_value > 255) new_value = 255;
        buffer[i] = (unsigned char)new_value;
    }
}

// This function adjusts the contrast of the image by a given factor
void adjust_contrast(unsigned char* buffer, int width, int height, float contrast) {
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));

    for(int i = 0; i < width * height * 3; i++) {
        int new_value = (int)(factor * (buffer[i] - 128.0) + 128.0);
        if(new_value < 0) new_value = 0;
        if(new_value > 255) new_value = 255;
        buffer[i] = (unsigned char)new_value;
    }
}

int main() {
    // Load image from file
    FILE* image_file = fopen("image.bmp", "rb");
    if(image_file == NULL) {
        printf("Could not open image.bmp\n");
        return 1;
    }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, image_file);

    int width = *(int*)(header + 18);
    int height = *(int*)(header + 22);

    unsigned char* buffer = malloc(width * height * 3 * sizeof(unsigned char));
    fread(buffer, sizeof(unsigned char), width * height * 3, image_file);

    fclose(image_file);

    // Process image
    flip_vertical(buffer, width, height);
    adjust_brightness(buffer, width, height, 50);
    adjust_contrast(buffer, width, height, 50.0);

    // Save processed image to file
    image_file = fopen("processed_image.bmp", "wb");
    if(image_file == NULL) {
        printf("Could not create processed_image.bmp\n");
        return 2;
    }

    fwrite(header, sizeof(unsigned char), 54, image_file);
    fwrite(buffer, sizeof(unsigned char), width * height * 3, image_file);

    fclose(image_file);

    free(buffer);

    return 0;
}