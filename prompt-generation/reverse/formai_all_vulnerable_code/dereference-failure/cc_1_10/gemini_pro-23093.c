//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Image data structure
typedef struct {
    unsigned char *data;
    int width;
    int height;
} Image;

// Function to read an image from a file
Image *read_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    // Read the header
    unsigned char header[18];
    fread(header, sizeof(unsigned char), 18, file);

    // Check if the file is a BMP image
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: %s is not a BMP image\n", filename);
        fclose(file);
        return NULL;
    }

    // Get the image dimensions
    int width = header[18] | (header[19] << 8);
    int height = header[22] | (header[23] << 8);

    // Allocate memory for the image data
    Image *image = malloc(sizeof(Image));
    image->data = malloc(width * height * 3);
    image->width = width;
    image->height = height;

    // Read the image data
    fread(image->data, sizeof(unsigned char), width * height * 3, file);

    // Close the file
    fclose(file);

    return image;
}

// Function to write an image to a file
void write_image(const char *filename, const Image *image) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    // Write the header
    unsigned char header[18] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0, 40, 0, 0, 0};
    header[18] = image->width & 0xFF;
    header[19] = (image->width >> 8) & 0xFF;
    header[22] = image->height & 0xFF;
    header[23] = (image->height >> 8) & 0xFF;
    fwrite(header, sizeof(unsigned char), 18, file);

    // Write the image data
    fwrite(image->data, sizeof(unsigned char), image->width * image->height * 3, file);

    // Close the file
    fclose(file);
}

// Function to flip an image horizontally
void flip_horizontally(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width / 2; j++) {
            unsigned char tmp = image->data[i * image->width * 3 + j * 3];
            image->data[i * image->width * 3 + j * 3] = image->data[i * image->width * 3 + (image->width - j - 1) * 3];
            image->data[i * image->width * 3 + (image->width - j - 1) * 3] = tmp;
            tmp = image->data[i * image->width * 3 + j * 3 + 1];
            image->data[i * image->width * 3 + j * 3 + 1] = image->data[i * image->width * 3 + (image->width - j - 1) * 3 + 1];
            image->data[i * image->width * 3 + (image->width - j - 1) * 3 + 1] = tmp;
            tmp = image->data[i * image->width * 3 + j * 3 + 2];
            image->data[i * image->width * 3 + j * 3 + 2] = image->data[i * image->width * 3 + (image->width - j - 1) * 3 + 2];
            image->data[i * image->width * 3 + (image->width - j - 1) * 3 + 2] = tmp;
        }
    }
}

// Function to change the brightness of an image
void change_brightness(Image *image, int brightness) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int k = 0; k < 3; k++) {
                int new_value = image->data[i * image->width * 3 + j * 3 + k] + brightness;
                if (new_value < 0) {
                    new_value = 0;
                } else if (new_value > 255) {
                    new_value = 255;
                }
                image->data[i * image->width * 3 + j * 3 + k] = new_value;
            }
        }
    }
}

// Function to change the contrast of an image
void change_contrast(Image *image, double contrast) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int k = 0; k < 3; k++) {
                int new_value = (image->data[i * image->width * 3 + j * 3 + k] - 127.5) * contrast + 127.5;
                if (new_value < 0) {
                    new_value = 0;
                } else if (new_value > 255) {
                    new_value = 255;
                }
                image->data[i * image->width * 3 + j * 3 + k] = new_value;
            }
        }
    }
}

// Main function
int main() {
    // Read the input image
    Image *image = read_image("input.bmp");
    if (image == NULL) {
        return 1;
    }

    // Flip the image horizontally
    flip_horizontally(image);

    // Change the brightness of the image
    change_brightness(image, 50);

    // Change the contrast of the image
    change_contrast(image, 1.5);

    // Write the output image
    write_image("output.bmp", image);

    // Free the memory allocated for the image
    free(image->data);
    free(image);

    return 0;
}