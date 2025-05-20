//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char *data;
    int width;
    int height;
} Image;

Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->data = malloc(width * height * sizeof(unsigned char));
    image->width = width;
    image->height = height;
    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

void read_image(Image *image, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Read the header
    unsigned char header[14];
    fread(header, sizeof(unsigned char), 14, file);

    // Check if the file is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: File is not a valid BMP file\n");
        exit(1);
    }

    // Read the image data
    int data_size = header[13];
    image->data = malloc(data_size);
    fread(image->data, sizeof(unsigned char), data_size, file);

    // Close the file
    fclose(file);
}

void write_image(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Write the header
    unsigned char header[14];
    header[0] = 'B';
    header[1] = 'M';
    header[2] = (image->width * image->height * 3 + 14) & 0xFF;
    header[3] = ((image->width * image->height * 3 + 14) >> 8) & 0xFF;
    header[4] = header[5] = header[6] = header[7] = 0;
    header[8] = 40;
    header[9] = header[10] = header[11] = header[12] = 0;
    header[13] = 24;
    fwrite(header, sizeof(unsigned char), 14, file);

    // Write the image data
    fwrite(image->data, sizeof(unsigned char), image->width * image->height * 3, file);

    // Close the file
    fclose(file);
}

void flip_image(Image *image) {
    for (int y = 0; y < image->height / 2; y++) {
        for (int x = 0; x < image->width; x++) {
            unsigned char temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[(image->height - y - 1) * image->width + x];
            image->data[(image->height - y - 1) * image->width + x] = temp;
        }
    }
}

void change_brightness(Image *image, int brightness) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int value = image->data[y * image->width + x] + brightness;
            if (value < 0) {
                value = 0;
            } else if (value > 255) {
                value = 255;
            }
            image->data[y * image->width + x] = value;
        }
    }
}

void change_contrast(Image *image, int contrast) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int value = image->data[y * image->width + x] * contrast / 100;
            if (value < 0) {
                value = 0;
            } else if (value > 255) {
                value = 255;
            }
            image->data[y * image->width + x] = value;
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input image> <output image> <operation> <value>\n", argv[0]);
        exit(1);
    }

    // Read the input image
    Image *image = new_image(0, 0);
    read_image(image, argv[1]);

    // Perform the operation
    if (strcmp(argv[3], "flip") == 0) {
        flip_image(image);
    } else if (strcmp(argv[3], "brightness") == 0) {
        change_brightness(image, atoi(argv[4]));
    } else if (strcmp(argv[3], "contrast") == 0) {
        change_contrast(image, atoi(argv[4]));
    } else {
        fprintf(stderr, "Error: Invalid operation\n");
        exit(1);
    }

    // Write the output image
    write_image(image, argv[2]);

    // Free the image
    free_image(image);

    return 0;
}