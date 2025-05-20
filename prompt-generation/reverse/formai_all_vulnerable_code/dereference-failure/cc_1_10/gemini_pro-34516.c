//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Allocate memory for an image.
unsigned char *allocate_image(int width, int height) {
    return malloc(width * height * sizeof(unsigned char));
}

// Free the memory allocated for an image.
void free_image(unsigned char *image) {
    free(image);
}

// Read an image from a file.
unsigned char *read_image(const char *filename, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return NULL;
    }

    // Read the header information.
    unsigned char header[54];
    if (fread(header, 1, 54, file) != 54) {
        fprintf(stderr, "Error: could not read header information from file '%s'\n", filename);
        fclose(file);
        return NULL;
    }

    // Check that the file is a valid BMP file.
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: file '%s' is not a valid BMP file\n", filename);
        fclose(file);
        return NULL;
    }

    // Get the image width and height.
    *width = *(int *)&header[18];
    *height = *(int *)&header[22];

    // Allocate memory for the image.
    unsigned char *image = allocate_image(*width, *height);
    if (image == NULL) {
        fprintf(stderr, "Error: could not allocate memory for image\n");
        fclose(file);
        return NULL;
    }

    // Read the image data.
    if (fread(image, 1, *width * *height * sizeof(unsigned char), file) != *width * *height * sizeof(unsigned char)) {
        fprintf(stderr, "Error: could not read image data from file '%s'\n", filename);
        fclose(file);
        free_image(image);
        return NULL;
    }

    // Close the file.
    fclose(file);

    return image;
}

// Write an image to a file.
int write_image(const char *filename, unsigned char *image, int width, int height) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return 1;
    }

    // Write the header information.
    unsigned char header[54];
    memset(header, 0, sizeof(header));
    header[0] = 'B';
    header[1] = 'M';
    *(int *)&header[18] = width;
    *(int *)&header[22] = height;
    *(int *)&header[28] = 24; // Bits per pixel.

    if (fwrite(header, 1, 54, file) != 54) {
        fprintf(stderr, "Error: could not write header information to file '%s'\n", filename);
        fclose(file);
        return 1;
    }

    // Write the image data.
    if (fwrite(image, 1, width * height * sizeof(unsigned char), file) != width * height * sizeof(unsigned char)) {
        fprintf(stderr, "Error: could not write image data to file '%s'\n", filename);
        fclose(file);
        return 1;
    }

    // Close the file.
    fclose(file);

    return 0;
}

// Flip an image vertically.
void flip_image_vertical(unsigned char *image, int width, int height) {
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char temp = image[i * width + j];
            image[i * width + j] = image[(height - i - 1) * width + j];
            image[(height - i - 1) * width + j] = temp;
        }
    }
}

// Flip an image horizontally.
void flip_image_horizontal(unsigned char *image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            unsigned char temp = image[i * width + j];
            image[i * width + j] = image[i * width + width - j - 1];
            image[i * width + width - j - 1] = temp;
        }
    }
}

// Change the brightness of an image.
void change_brightness(unsigned char *image, int width, int height, int brightness) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i * width + j] = image[i * width + j] + brightness;
        }
    }
}

// Change the contrast of an image.
void change_contrast(unsigned char *image, int width, int height, int contrast) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i * width + j] = image[i * width + j] * contrast / 100;
        }
    }
}

// Main function.
int main(int argc, char **argv) {
    // Check that the correct number of arguments has been provided.
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input image> <output image> <operation> <value>\n", argv[0]);
        return 1;
    }

    // Read the input image.
    int width, height;
    unsigned char *image = read_image(argv[1], &width, &height);
    if (image == NULL) {
        return 1;
    }

    // Perform the specified operation on the image.
    if (strcmp(argv[3], "flip-vertical") == 0) {
        flip_image_vertical(image, width, height);
    } else if (strcmp(argv[3], "flip-horizontal") == 0) {
        flip_image_horizontal(image, width, height);
    } else if (strcmp(argv[3], "brightness") == 0) {
        change_brightness(image, width, height, atoi(argv[4]));
    } else if (strcmp(argv[3], "contrast") == 0) {
        change_contrast(image, width, height, atoi(argv[4]));
    } else {
        fprintf(stderr, "Error: invalid operation '%s'\n", argv[3]);
        free_image(image);
        return 1;
    }

    // Write the output image.
    if (write_image(argv[2], image, width, height) != 0) {
        free_image(image);
        return 1;
    }

    // Free the memory allocated for the image.
    free_image(image);

    return 0;
}