//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600

typedef unsigned char byte;

byte* load_image(const char* filename) {
    byte* image_data = NULL;
    FILE* file = fopen(filename, "rb");
    if (file) {
        fseek(file, 0, SEEK_END);
        int file_size = ftell(file);
        fseek(file, 0, SEEK_SET);
        image_data = malloc(file_size);
        fread(image_data, file_size, 1, file);
        fclose(file);
    }
    return image_data;
}

void save_image(const char* filename, byte* image_data) {
    FILE* file = fopen(filename, "wb");
    if (file) {
        fwrite(image_data, WIDTH * HEIGHT * 3, 1, file);
        fclose(file);
    }
}

void flip_image(byte* image_data) {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH / 2; ++x) {
            byte* left = image_data + (y * WIDTH + x) * 3;
            byte* right = image_data + (y * WIDTH + WIDTH - x - 1) * 3;
            byte temp[3];
            temp[0] = left[0]; temp[1] = left[1]; temp[2] = left[2];
            left[0] = right[0]; left[1] = right[1]; left[2] = right[2];
            right[0] = temp[0]; right[1] = temp[1]; right[2] = temp[2];
        }
    }
}

void adjust_brightness(byte* image_data, int adjustment) {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            byte* pixel = image_data + (y * WIDTH + x) * 3;
            pixel[0] += adjustment;
            pixel[1] += adjustment;
            pixel[2] += adjustment;
        }
    }
}

void adjust_contrast(byte* image_data, float adjustment) {
    float factor = (259.0f * (adjustment + 255.0f)) / (255.0f * (259.0f - adjustment));
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            byte* pixel = image_data + (y * WIDTH + x) * 3;
            pixel[0] = factor * (pixel[0] - 128) + 128;
            pixel[1] = factor * (pixel[1] - 128) + 128;
            pixel[2] = factor * (pixel[2] - 128) + 128;
        }
    }
}

int main() {
    byte* image_data = load_image("input.bmp");
    if (image_data) {
        flip_image(image_data);
        adjust_brightness(image_data, 50);
        adjust_contrast(image_data, 50);
        save_image("output.bmp", image_data);
        free(image_data);
    }
    return 0;
}