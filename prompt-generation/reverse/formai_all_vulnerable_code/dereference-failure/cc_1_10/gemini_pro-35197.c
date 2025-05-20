//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Structure to represent an image
typedef struct {
    int width;
    int height;
    unsigned char* data;
} Image;

// Function to read an image from a file
Image* read_image(char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Read the header information
    unsigned char header[14];
    fread(header, sizeof(header), 1, fp);

    // Check if the file is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: Invalid BMP file\n");
        fclose(fp);
        return NULL;
    }

    // Read the width and height of the image
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Allocate memory for the image data
    unsigned char* data = (unsigned char*)malloc(width * height * 3);
    if (data == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        return NULL;
    }

    // Read the image data
    fread(data, width * height * 3, 1, fp);

    // Close the file
    fclose(fp);

    // Create the image struct
    Image* image = (Image*)malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = data;

    return image;
}

// Function to write an image to a file
void write_image(Image* image, char* filename) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    // Write the header information
    unsigned char header[14] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
    fwrite(header, sizeof(header), 1, fp);

    // Write the width and height of the image
    int width = image->width;
    int height = image->height;
    fwrite(&width, sizeof(int), 1, fp);
    fwrite(&height, sizeof(int), 1, fp);

    // Write the image data
    fwrite(image->data, width * height * 3, 1, fp);

    // Close the file
    fclose(fp);
}

// Function to flip an image horizontally
void flip_horizontal(Image* image) {
    int width = image->width;
    int height = image->height;
    unsigned char* data = image->data;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            unsigned char temp = data[y * width + x];
            data[y * width + x] = data[y * width + width - x - 1];
            data[y * width + width - x - 1] = temp;
        }
    }
}

// Function to flip an image vertically
void flip_vertical(Image* image) {
    int width = image->width;
    int height = image->height;
    unsigned char* data = image->data;

    for (int y = 0; y < height / 2; y++) {
        for (int x = 0; x < width; x++) {
            unsigned char temp = data[y * width + x];
            data[y * width + x] = data[(height - y - 1) * width + x];
            data[(height - y - 1) * width + x] = temp;
        }
    }
}

// Function to change the brightness of an image
void change_brightness(Image* image, int brightness) {
    int width = image->width;
    int height = image->height;
    unsigned char* data = image->data;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < 3; c++) {
                int value = data[y * width * 3 + x * 3 + c] + brightness;
                if (value < 0) {
                    value = 0;
                } else if (value > 255) {
                    value = 255;
                }
                data[y * width * 3 + x * 3 + c] = value;
            }
        }
    }
}

// Function to change the contrast of an image
void change_contrast(Image* image, double contrast) {
    int width = image->width;
    int height = image->height;
    unsigned char* data = image->data;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < 3; c++) {
                int value = (data[y * width * 3 + x * 3 + c] - 128) * contrast + 128;
                if (value < 0) {
                    value = 0;
                } else if (value > 255) {
                    value = 255;
                }
                data[y * width * 3 + x * 3 + c] = value;
            }
        }
    }
}

// Main function
int main(int argc, char** argv) {
    // Check if the user specified an input file
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file> [output_file]\n", argv[0]);
        return 1;
    }

    // Read the input image
    Image* image = read_image(argv[1]);
    if (image == NULL) {
        return 1;
    }

    // Check if the user specified an output file
    char* output_file = NULL;
    if (argc >= 3) {
        output_file = argv[2];
    } else {
        output_file = "output.bmp";
    }

    // Flip the image horizontally
    flip_horizontal(image);

    // Flip the image vertically
    flip_vertical(image);

    // Change the brightness of the image
    change_brightness(image, 50);

    // Change the contrast of the image
    change_contrast(image, 1.5);

    // Write the output image
    write_image(image, output_file);

    // Free the memory allocated for the image
    free(image->data);
    free(image);

    return 0;
}