//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned int width;
    unsigned int height;
    unsigned char *data;
} Image;

Image *new_image(unsigned int width, unsigned int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * 3);
    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

void load_image(Image *image, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    // Read the header
    unsigned char header[54];
    fread(header, sizeof(header), 1, file);

    // Check if the file is a BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: file %s is not a BMP file\n", filename);
        fclose(file);
        return;
    }

    // Read the image dimensions
    unsigned int width = *(unsigned int *)&header[18];
    unsigned int height = *(unsigned int *)&header[22];

    // Check if the image dimensions are valid
    if (width == 0 || height == 0) {
        fprintf(stderr, "Error: image dimensions are invalid\n");
        fclose(file);
        return;
    }

    // Read the image data
    fread(image->data, width * height * 3, 1, file);

    fclose(file);
}

void save_image(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    // Write the header
    unsigned char header[54] = {
        'B', 'M', // Magic number
        0, 0, 0, 0, // File size (filled in later)
        0, 0, // Reserved
        0, 0, // Offset to image data
        40, 0, 0, 0, // DIB header size
        0, 0, 0, 0, // Image width
        0, 0, 0, 0, // Image height
        1, 0, // Number of color planes
        24, 0, // Number of bits per pixel
        0, 0, 0, 0, // Compression type
        0, 0, 0, 0, // Image size (filled in later)
        0, 0, 0, 0, // Horizontal resolution
        0, 0, 0, 0, // Vertical resolution
        0, 0, 0, 0, // Number of colors in palette
        0, 0, 0, 0, // Number of important colors
    };

    // Fill in the file size
    *(unsigned int *)&header[2] = 54 + image->width * image->height * 3;

    // Fill in the image dimensions
    *(unsigned int *)&header[18] = image->width;
    *(unsigned int *)&header[22] = image->height;

    // Fill in the image size
    *(unsigned int *)&header[34] = image->width * image->height * 3;

    fwrite(header, sizeof(header), 1, file);

    // Write the image data
    fwrite(image->data, image->width * image->height * 3, 1, file);

    fclose(file);
}

void invert_image(Image *image) {
    for (int i = 0; i < image->width * image->height * 3; i++) {
        image->data[i] = 255 - image->data[i];
    }
}

void grayscale_image(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        unsigned char gray = (image->data[i * 3] + image->data[i * 3 + 1] + image->data[i * 3 + 2]) / 3;
        image->data[i * 3] = gray;
        image->data[i * 3 + 1] = gray;
        image->data[i * 3 + 2] = gray;
    }
}

void rotate_image(Image *image) {
    // Create a new image to store the rotated image
    Image *rotated_image = new_image(image->height, image->width);

    // Rotate the image pixels
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            rotated_image->data[(image->height - y - 1) * image->width * 3 + x * 3] = image->data[y * image->width * 3 + x * 3];
            rotated_image->data[(image->height - y - 1) * image->width * 3 + x * 3 + 1] = image->data[y * image->width * 3 + x * 3 + 1];
            rotated_image->data[(image->height - y - 1) * image->width * 3 + x * 3 + 2] = image->data[y * image->width * 3 + x * 3 + 2];
        }
    }

    // Free the old image data
    free(image->data);

    // Copy the rotated image data to the original image
    image->data = rotated_image->data;
    image->width = rotated_image->width;
    image->height = rotated_image->height;

    // Free the rotated image
    free(rotated_image);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
        return 1;
    }

    // Load the image
    Image *image = new_image(0, 0);
    load_image(image, argv[1]);

    // Invert the image
    invert_image(image);

    // Grayscale the image
    grayscale_image(image);

    // Rotate the image
    rotate_image(image);

    // Save the image
    save_image(image, "output.bmp");

    // Free the image
    free_image(image);

    return 0;
}