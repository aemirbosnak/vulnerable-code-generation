//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 100
#define HEIGHT 100
#define MAX_CHARS 70

// Simple ASCII art characters for shades
const char *ASCII_CHARS = "@%#*+=-:. "; // more dense to less dense

// Function to calculate the luminance of a pixel
float luminance(unsigned char r, unsigned char g, unsigned char b) {
    return 0.299 * r + 0.587 * g + 0.114 * b;
}

// Function to scale the image down
void scale_image(unsigned char *image, unsigned char *scaled_image, int original_width, int original_height, int scale_factor) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int orig_x = x * scale_factor;
            int orig_y = y * scale_factor;
            if (orig_x < original_width && orig_y < original_height) {
                int index = (orig_y * original_width + orig_x) * 3;
                scaled_image[(y * WIDTH + x) * 3] = image[index];       // R
                scaled_image[(y * WIDTH + x) * 3 + 1] = image[index + 1]; // G
                scaled_image[(y * WIDTH + x) * 3 + 2] = image[index + 2]; // B
            }
        }
    }
}

// Function to convert the image to ASCII art
void convert_to_ascii(unsigned char *image) {
    unsigned char scaled_image[WIDTH * HEIGHT * 3];
    scale_image(image, scaled_image, WIDTH, HEIGHT, 8); // setting scale factor to 8

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int index = (y * WIDTH + x) * 3;
            float lum = luminance(scaled_image[index], scaled_image[index + 1], scaled_image[index + 2]);
            int char_index = (int)(lum / 255 * (strlen(ASCII_CHARS) - 1));
            putchar(ASCII_CHARS[char_index]);
        }
        putchar('\n');
    }
}

// Function to load the image (dummy implementation for demo)
unsigned char *load_image(const char *filename, int *width, int *height) {
    // For this demo, we'd return a placeholder dummy image (pure white)
    int size = WIDTH * HEIGHT * 3;
    unsigned char *image = (unsigned char *)malloc(size);

    for (int i = 0; i < size; i++) {
        image[i] = 255; // White color
    }

    *width = WIDTH;
    *height = HEIGHT;
    return image;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    int width, height;
    unsigned char *image = load_image(argv[1], &width, &height);

    if (image == NULL) {
        fprintf(stderr, "Could not load image: %s\n", argv[1]);
        return 1;
    }

    printf("Generating ASCII art for image: %s\n", argv[1]);
    convert_to_ascii(image);

    free(image);
    return 0;
}