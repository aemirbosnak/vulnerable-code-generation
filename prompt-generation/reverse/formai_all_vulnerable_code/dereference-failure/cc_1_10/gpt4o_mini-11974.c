//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <jpeglib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 40
#define ASCII_CHARS "@%#*+=-:. " 

void generate_ascii_art(const char *image_path);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image_path>\n", argv[0]);
        return EXIT_FAILURE;
    }
    generate_ascii_art(argv[1]);
    return EXIT_SUCCESS;
}

void generate_ascii_art(const char *image_path) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    FILE *input_file = fopen(image_path, "rb");
    if (!input_file) {
        fprintf(stderr, "Error: Could not open file %s\n", image_path);
        return;
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, input_file);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    int width = cinfo.output_width;
    int height = cinfo.output_height;
    int num_channels = cinfo.output_components;

    unsigned char *buffer = malloc(width * height * num_channels);
    unsigned char *row_pointer[1];

    // Read the image data into buffer
    while (cinfo.output_scanline < height) {
        row_pointer[0] = buffer + (cinfo.output_scanline) * width * num_channels;
        jpeg_read_scanlines(&cinfo, row_pointer, 1);
    }

    // Start converting to ASCII art
    printf("ASCII Art Representation:\n");
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int pixel_index = (y * (height / HEIGHT) * width + x * (width / WIDTH)) * num_channels;
            int grayscale = (buffer[pixel_index] + buffer[pixel_index + 1] + buffer[pixel_index + 2]) / 3;
            int ascii_index = (grayscale * (strlen(ASCII_CHARS) - 1)) / 255;
            putchar(ASCII_CHARS[ascii_index]);
        }
        putchar('\n');
    }

    // Cleanup
    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);
    free(buffer);
    fclose(input_file);
}