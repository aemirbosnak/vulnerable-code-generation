//FormAI DATASET v1.0 Category: Image compression ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define block size for compression
#define BLOCK_SIZE 8

// Structure to store RGB values for each pixel
typedef struct {
    unsigned char r, g, b;
} pixel;

// Function to read image data from file
pixel** read_image_data(const char* filename, int* width, int* height) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: failed to open file '%s'\n", filename);
        return NULL;
    }

    // Read BMP file header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp);
    *width = *(int*)&header[18];
    *height = *(int*)&header[22];
    int padding = 0;
    while ((*width * 3 + padding) % 4 != 0) {
        padding++;
    }

    // Allocate memory to store pixel data
    pixel** image_data = (pixel**) malloc(*height * sizeof(pixel*));
    for (int i = 0; i < *height; i++) {
        image_data[i] = (pixel*) malloc(*width * sizeof(pixel));
    }

    // Read pixel data from file
    for (int y = 0; y < *height; y++) {
        for (int x = 0; x < *width; x++) {
            unsigned char pixel_data[3];
            fread(pixel_data, sizeof(unsigned char), 3, fp);
            image_data[*height - y - 1][x].r = pixel_data[2];
            image_data[*height - y - 1][x].g = pixel_data[1];
            image_data[*height - y - 1][x].b = pixel_data[0];
        }
        fread(NULL, sizeof(unsigned char), padding, fp);
    }

    fclose(fp);
    return image_data;
}

// Function to write image data to file
void write_image_data(const char* filename, pixel** image_data, int width, int height) {
    FILE* fp = fopen(filename, "wb");

    // Write BMP file header
    unsigned char header[54] = {
        0x42, 0x4D, // BM
        0x36, 0x03, 0x00, 0x00, // File size (54 + width * height * 3)
        0x00, 0x00, // Reserved
        0x00, 0x00, // Reserved
        0x36, 0x00, 0x00, 0x00, // Bitmap data offset (54)
        0x28, 0x00, 0x00, 0x00, // Header size (40)
        0x00, 0x00, 0x00, 0x00, // Image width
        0x00, 0x00, 0x00, 0x00, // Image height
        0x01, 0x00, // Color planes (1)
        0x18, 0x00, // Bits per pixel (24)
        0x00, 0x00, 0x00, 0x00, // Compression method
        0x00, 0x03, 0x00, 0x00, // Image size (width * height * 3)
        0x13, 0x0B, 0x00, 0x00, // Horizontal resolution (2835 pixels/meter)
        0x13, 0x0B, 0x00, 0x00, // Vertical resolution (2835 pixels/meter)
        0x00, 0x00, 0x00, 0x00, // Number of colors (0)
        0x00, 0x00, 0x00, 0x00 // Number of important colors (0)
    };
    *(int*)&header[18] = width;
    *(int*)&header[22] = height;
    int padding = 0;
    while ((width * 3 + padding) % 4 != 0) {
        padding++;
    }
    *(int*)&header[2] = 54 + (width * height * 3) + (height * padding);
    fwrite(header, sizeof(unsigned char), 54, fp);

    // Write pixel data to file
    unsigned char padding_data[3] = {0, 0, 0};
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fwrite(&image_data[height - y - 1][x].b, sizeof(unsigned char), 1, fp);
            fwrite(&image_data[height - y - 1][x].g, sizeof(unsigned char), 1, fp);
            fwrite(&image_data[height - y - 1][x].r, sizeof(unsigned char), 1, fp);
        }
        fwrite(padding_data, sizeof(unsigned char), padding, fp);
    }

    fclose(fp);
}

// Function to compress image data
pixel** compress_image_data(pixel** image_data, int width, int height) {
    // Allocate memory to store compressed data
    pixel** compressed_data = (pixel**) malloc(height * sizeof(pixel*));
    for (int i = 0; i < height; i++) {
        compressed_data[i] = (pixel*) malloc(width * sizeof(pixel));
    }

    // Compress each block of pixels
    for (int y = 0; y < height; y += BLOCK_SIZE) {
        for (int x = 0; x < width; x += BLOCK_SIZE) {
            int r_sum = 0, g_sum = 0, b_sum = 0;
            int r_avg, g_avg, b_avg;
            for (int i = y; i < y + BLOCK_SIZE; i++) {
                for (int j = x; j < x + BLOCK_SIZE; j++) {
                    r_sum += image_data[i][j].r;
                    g_sum += image_data[i][j].g;
                    b_sum += image_data[i][j].b;
                }
            }
            r_avg = r_sum / (BLOCK_SIZE * BLOCK_SIZE);
            g_avg = g_sum / (BLOCK_SIZE * BLOCK_SIZE);
            b_avg = b_sum / (BLOCK_SIZE * BLOCK_SIZE);
            for (int i = y; i < y + BLOCK_SIZE; i++) {
                for (int j = x; j < x + BLOCK_SIZE; j++) {
                    compressed_data[i][j].r = r_avg;
                    compressed_data[i][j].g = g_avg;
                    compressed_data[i][j].b = b_avg;
                }
            }
        }
    }

    return compressed_data;
}

int main() {
    int width, height;
    pixel** image_data = read_image_data("input.bmp", &width, &height);
    if (!image_data) {
        return 1;
    }

    pixel** compressed_data = compress_image_data(image_data, width, height);
    write_image_data("output.bmp", compressed_data, width, height);

    // Free memory allocated to image data
    for (int i = 0; i < height; i++) {
        free(image_data[i]);
    }
    free(image_data);

    // Free memory allocated to compressed data
    for (int i = 0; i < height; i++) {
        free(compressed_data[i]);
    }
    free(compressed_data);

    return 0;
}