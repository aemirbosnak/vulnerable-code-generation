//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IMG_WIDTH 640
#define IMG_HEIGHT 480

// Read an image from a file
void read_image(const char *filename, unsigned char *image) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read the image header
    unsigned char header[54];
    fread(header, sizeof(header), 1, fp);

    // Check if the file is a valid BMP image
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: Not a valid BMP image\n");
        exit(EXIT_FAILURE);
    }

    // Get the image width and height
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Check if the image is the expected size
    if (width != IMG_WIDTH || height != IMG_HEIGHT) {
        fprintf(stderr, "Error: Image size is not %dx%d\n", IMG_WIDTH, IMG_HEIGHT);
        exit(EXIT_FAILURE);
    }

    // Read the image data
    fread(image, sizeof(unsigned char) * IMG_WIDTH * IMG_HEIGHT, 1, fp);

    fclose(fp);
}

// Write an image to a file
void write_image(const char *filename, unsigned char *image) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Write the image header
    unsigned char header[54] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0, IMG_WIDTH, 0, IMG_HEIGHT, 0, 1, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    fwrite(header, sizeof(header), 1, fp);

    // Write the image data
    fwrite(image, sizeof(unsigned char) * IMG_WIDTH * IMG_HEIGHT, 1, fp);

    fclose(fp);
}

// Flip an image horizontally
void flip_horizontal(unsigned char *image) {
    for (int i = 0; i < IMG_HEIGHT; i++) {
        for (int j = 0; j < IMG_WIDTH / 2; j++) {
            unsigned char temp = image[i * IMG_WIDTH + j];
            image[i * IMG_WIDTH + j] = image[i * IMG_WIDTH + IMG_WIDTH - j - 1];
            image[i * IMG_WIDTH + IMG_WIDTH - j - 1] = temp;
        }
    }
}

// Flip an image vertically
void flip_vertical(unsigned char *image) {
    for (int i = 0; i < IMG_HEIGHT / 2; i++) {
        for (int j = 0; j < IMG_WIDTH; j++) {
            unsigned char temp = image[i * IMG_WIDTH + j];
            image[i * IMG_WIDTH + j] = image[(IMG_HEIGHT - i - 1) * IMG_WIDTH + j];
            image[(IMG_HEIGHT - i - 1) * IMG_WIDTH + j] = temp;
        }
    }
}

// Adjust the brightness of an image
void adjust_brightness(unsigned char *image, int delta) {
    for (int i = 0; i < IMG_HEIGHT; i++) {
        for (int j = 0; j < IMG_WIDTH; j++) {
            int value = (int)image[i * IMG_WIDTH + j] + delta;
            if (value < 0) {
                value = 0;
            } else if (value > 255) {
                value = 255;
            }
            image[i * IMG_WIDTH + j] = (unsigned char)value;
        }
    }
}

// Adjust the contrast of an image
void adjust_contrast(unsigned char *image, float factor) {
    for (int i = 0; i < IMG_HEIGHT; i++) {
        for (int j = 0; j < IMG_WIDTH; j++) {
            int value = (int)(128 + factor * (image[i * IMG_WIDTH + j] - 128));
            if (value < 0) {
                value = 0;
            } else if (value > 255) {
                value = 255;
            }
            image[i * IMG_WIDTH + j] = (unsigned char)value;
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user specified an input image file
    if (argc < 2) {
        fprintf(stderr, "Error: No input image file specified\n");
        return EXIT_FAILURE;
    }

    // Check if the user specified an output image file
    if (argc < 3) {
        fprintf(stderr, "Error: No output image file specified\n");
        return EXIT_FAILURE;
    }

    // Read the input image
    unsigned char *image = malloc(sizeof(unsigned char) * IMG_WIDTH * IMG_HEIGHT);
    read_image(argv[1], image);

    // Flip the image horizontally
    flip_horizontal(image);

    // Flip the image vertically
    flip_vertical(image);

    // Adjust the brightness of the image
    adjust_brightness(image, 50);

    // Adjust the contrast of the image
    adjust_contrast(image, 1.5);

    // Write the output image
    write_image(argv[2], image);

    free(image);

    return EXIT_SUCCESS;
}