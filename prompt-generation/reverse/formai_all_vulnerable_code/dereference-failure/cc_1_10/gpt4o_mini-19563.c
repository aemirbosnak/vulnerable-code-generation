//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <jpeglib.h>

#define MAX_WIDTH 800
#define MAX_HEIGHT 800
#define ASCII_CHARS "@%#*+=-:. "

void convert_rgb_to_gray(uint8_t r, uint8_t g, uint8_t b, uint8_t *gray) {
    // Convert RGB to grayscale using luminance formula
    *gray = (uint8_t)(0.299 * r + 0.587 * g + 0.114 * b);
}

void image_to_ascii(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Unable to open file: %s\n", filename);
        return;
    }
    
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, file);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    int width = cinfo.output_width;
    int height = cinfo.output_height;

    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        fprintf(stderr, "Image is too large. Max size is %dx%d.\n", MAX_WIDTH, MAX_HEIGHT);
        jpeg_destroy_decompress(&cinfo);
        fclose(file);
        return;
    }

    // Allocate memory for pixel data
    int row_stride = cinfo.output_width * cinfo.output_components;
    uint8_t *buffer = (uint8_t *)malloc(row_stride * height);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed.\n");
        jpeg_destroy_decompress(&cinfo);
        fclose(file);
        return;
    }

    // Read scanlines one at a time
    while (cinfo.output_scanline < cinfo.output_height) {
        uint8_t *row_pointer = buffer + (cinfo.output_scanline) * row_stride;
        jpeg_read_scanlines(&cinfo, &row_pointer, 1);
    }

    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);
    fclose(file);

    // Convert image data to ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            uint8_t r = buffer[i * row_stride + j * cinfo.output_components + 0];
            uint8_t g = buffer[i * row_stride + j * cinfo.output_components + 1];
            uint8_t b = buffer[i * row_stride + j * cinfo.output_components + 2];

            uint8_t gray;
            convert_rgb_to_gray(r, g, b, &gray);

            // Map the brightness to ASCII characters
            int ascii_index = gray * (strlen(ASCII_CHARS) - 1) / 255;
            putchar(ASCII_CHARS[ascii_index]);
        }
        putchar('\n');
    }

    free(buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    image_to_ascii(argv[1]);
    return EXIT_SUCCESS;
}