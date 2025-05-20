//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 768

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image *image_new(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * 3);
    return image;
}

void image_free(Image *image) {
    free(image->data);
    free(image);
}

void image_load(Image *image, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("fopen");
        exit(1);
    }

    // Read the header
    unsigned char header[54];
    if (fread(header, 1, 54, file) != 54) {
        perror("fread");
        exit(1);
    }

    // Check if the file is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Invalid BMP file\n");
        exit(1);
    }

    // Read the image data
    if (fread(image->data, 1, image->width * image->height * 3, file) != image->width * image->height * 3) {
        perror("fread");
        exit(1);
    }

    fclose(file);
}

void image_save(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("fopen");
        exit(1);
    }

    // Write the header
    unsigned char header[54] = {
        0x42, 0x4D, // Magic number
        0x36, 0x00, 0x00, 0x00, // File size
        0x00, 0x00, // Reserved
        0x00, 0x00, // Reserved
        0x36, 0x00, 0x00, 0x00, // Offset to image data
        0x28, 0x00, 0x00, 0x00, // DIB header size
        0x00, 0x00, // Image width
        0x00, 0x00, // Image height
        0x01, 0x00, // Number of color planes
        0x18, 0x00, // Number of bits per pixel
        0x00, 0x00, 0x00, 0x00, // Compression type
        0x00, 0x00, 0x00, 0x00, // Image data size
        0x00, 0x00, 0x00, 0x00, // Horizontal resolution
        0x00, 0x00, 0x00, 0x00, // Vertical resolution
        0x00, 0x00, 0x00, 0x00, // Number of colors
        0x00, 0x00, 0x00, 0x00, // Number of important colors
    };

    header[2] = (image->width * image->height * 3) + 54;
    header[18] = image->width;
    header[22] = image->height;

    if (fwrite(header, 1, 54, file) != 54) {
        perror("fwrite");
        exit(1);
    }

    // Write the image data
    if (fwrite(image->data, 1, image->width * image->height * 3, file) != image->width * image->height * 3) {
        perror("fwrite");
        exit(1);
    }

    fclose(file);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input file> <output file> <operation>\n", argv[0]);
        exit(1);
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];
    const char *operation = argv[3];

    Image *image = image_new(MAX_WIDTH, MAX_HEIGHT);
    image_load(image, input_filename);

    if (strcmp(operation, "grayscale") == 0) {
        for (int i = 0; i < image->width * image->height; i++) {
            unsigned char gray = (image->data[i * 3] + image->data[i * 3 + 1] + image->data[i * 3 + 2]) / 3;
            image->data[i * 3] = gray;
            image->data[i * 3 + 1] = gray;
            image->data[i * 3 + 2] = gray;
        }
    } else if (strcmp(operation, "invert") == 0) {
        for (int i = 0; i < image->width * image->height; i++) {
            image->data[i * 3] = 255 - image->data[i * 3];
            image->data[i * 3 + 1] = 255 - image->data[i * 3 + 1];
            image->data[i * 3 + 2] = 255 - image->data[i * 3 + 2];
        }
    } else if (strcmp(operation, "blur") == 0) {
        // TODO
    } else if (strcmp(operation, "sharpen") == 0) {
        // TODO
    } else {
        fprintf(stderr, "Invalid operation: %s\n", operation);
        exit(1);
    }

    image_save(image, output_filename);
    image_free(image);

    return 0;
}