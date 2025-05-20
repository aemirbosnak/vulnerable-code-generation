//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jpeglib.h>

#define MAX_ASCII_LEN 100
#define ASCII_CHARS " .:-=+*%@#"

void print_ascii_art(unsigned char *image_buffer, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int pixel_index = (i * width + j) * 3; // 3 channels: RGB
            int r = image_buffer[pixel_index];
            int g = image_buffer[pixel_index + 1];
            int b = image_buffer[pixel_index + 2];

            // Calculate grayscale value
            int gray = (r + g + b) / 3;

            // Map grayscale value to ASCII character
            int char_index = (gray * (strlen(ASCII_CHARS) - 1)) / 255;
            putchar(ASCII_CHARS[char_index]);
        }
        putchar('\n');
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image-file>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    FILE *infile = fopen(filename, "rb");
    if (!infile) {
        fprintf(stderr, "Error opening JPEG file: %s\n", filename);
        return 1;
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    int width = cinfo.output_width;
    int height = cinfo.output_height;
    int num_channels = cinfo.output_components;

    unsigned char *image_buffer = (unsigned char *) malloc(width * height * num_channels);
    if (!image_buffer) {
        fprintf(stderr, "Failed to allocate memory for image buffer\n");
        return 1;
    }

    unsigned char *row_pointer = image_buffer;
    while (cinfo.output_scanline < height) {
        row_pointer = image_buffer + cinfo.output_scanline * width * num_channels;
        jpeg_read_scanlines(&cinfo, &row_pointer, 1);
    }

    jpeg_finish_decompress(&cinfo);
    fclose(infile);

    print_ascii_art(image_buffer, width, height);

    free(image_buffer);
    jpeg_destroy_decompress(&cinfo);
    return 0;
}