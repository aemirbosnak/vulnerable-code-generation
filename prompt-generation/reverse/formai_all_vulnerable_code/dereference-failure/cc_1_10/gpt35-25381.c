//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 640
#define HEIGHT 480

// Flip image horizontally
void flip_image(unsigned char* data, int width, int height) {
    unsigned char temp[3];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            for (int k = 0; k < 3; k++) {
                temp[k] = data[i * width * 3 + j * 3 + k];
                data[i * width * 3 + j * 3 + k] = data[i * width * 3 + (width - j - 1) * 3 + k];
                data[i * width * 3 + (width - j - 1) * 3 + k] = temp[k];
            }
        }
    }
}

// Change brightness of image
void change_brightness(unsigned char* data, int width, int height, int delta) {
    for (int i = 0; i < width * height * 3; i++) {
        int value = (int)data[i] + delta;
        if (value < 0) {
            value = 0;
        } else if (value > 255) {
            value = 255;
        }
        data[i] = (unsigned char)value;
    }
}

// Change contrast of image
void change_contrast(unsigned char* data, int width, int height, float factor) {
    float delta = 0.5 * (1.0 - factor);
    for (int i = 0; i < width * height * 3; i++) {
        int value = (int)((float)data[i] * factor + delta);
        if (value < 0) {
            value = 0;
        } else if (value > 255) {
            value = 255;
        }
        data[i] = (unsigned char)value;
    }
}

int main() {
    // Load image data into an unsigned char array
    unsigned char* data = (unsigned char*)malloc(WIDTH * HEIGHT * 3);
    FILE* file = fopen("input.raw", "rb");
    fread(data, sizeof(unsigned char), WIDTH * HEIGHT * 3, file);
    fclose(file);

    // Flip image horizontally, change brightness, and change contrast
    flip_image(data, WIDTH, HEIGHT);
    change_brightness(data, WIDTH, HEIGHT, 50);
    change_contrast(data, WIDTH, HEIGHT, 1.5);

    // Save image data to an output file
    FILE* outfile = fopen("output.raw", "wb");
    fwrite(data, sizeof(unsigned char), WIDTH * HEIGHT * 3, outfile);
    fclose(outfile);

    free(data);
    return 0;
}