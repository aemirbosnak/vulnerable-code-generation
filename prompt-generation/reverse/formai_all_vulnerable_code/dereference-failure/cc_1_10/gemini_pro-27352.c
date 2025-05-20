//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * sizeof(unsigned char));
    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

void load_image(Image *image, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    // Read the header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);

    // Check the header magic number
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: not a valid BMP file\n");
        exit(1);
    }

    // Get the image width and height
    image->width = *(int *)&header[18];
    image->height = *(int *)&header[22];

    // Read the image data
    int data_size = image->width * image->height * 3;
    image->data = malloc(data_size);
    fread(image->data, sizeof(unsigned char), data_size, file);

    fclose(file);
}

void save_image(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    // Write the header
    unsigned char header[54];
    memset(header, 0, sizeof(unsigned char) * 54);
    header[0] = 'B';
    header[1] = 'M';
    *(int *)&header[18] = image->width;
    *(int *)&header[22] = image->height;
    *(int *)&header[28] = 24;
    *(int *)&header[34] = image->width * image->height * 3;

    fwrite(header, sizeof(unsigned char), 54, file);

    // Write the image data
    fwrite(image->data, sizeof(unsigned char), image->width * image->height * 3, file);

    fclose(file);
}

void invert_colors(Image *image) {
    for (int i = 0; i < image->width * image->height * 3; i++) {
        image->data[i] = 255 - image->data[i];
    }
}

void grayscale(Image *image) {
    for (int i = 0; i < image->width * image->height * 3; i += 3) {
        unsigned char gray = (image->data[i] + image->data[i + 1] + image->data[i + 2]) / 3;
        image->data[i] = gray;
        image->data[i + 1] = gray;
        image->data[i + 2] = gray;
    }
}

void sepia(Image *image) {
    for (int i = 0; i < image->width * image->height * 3; i += 3) {
        unsigned char red = image->data[i];
        unsigned char green = image->data[i + 1];
        unsigned char blue = image->data[i + 2];
        image->data[i] = (red * .393) + (green * .769) + (blue * .189);
        image->data[i + 1] = (red * .349) + (green * .686) + (blue * .168);
        image->data[i + 2] = (red * .272) + (green * .534) + (blue * .131);
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    Image *image = new_image(MAX_WIDTH, MAX_HEIGHT);
    load_image(image, argv[1]);

    // Apply the desired filter
    invert_colors(image);
    grayscale(image);
    sepia(image);

    save_image(image, argv[2]);
    free_image(image);

    return 0;
}