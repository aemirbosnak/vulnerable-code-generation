//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <jpeglib.h>

#define WIDTH 80
#define HEIGHT 40

// ASCII character set used for mapping pixel brightness
const char *ASCII_CHARS = "@%#*+=-:. ";

void error_exit(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(1);
}

void convert_jpeg_to_ascii(const char *input_filename) {
    // Prepare for JPEG decompression
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    FILE *infile;
    unsigned char *buffer;
    int row_stride;

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);

    if ((infile = fopen(input_filename, "rb")) == NULL) {
        error_exit("Cannot open input JPEG file!");
    }

    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    row_stride = cinfo.output_width * cinfo.output_components;
    buffer = (unsigned char *)malloc(row_stride);

    int ascii_index = 0;
    char ascii_image[HEIGHT][WIDTH + 1];

    while (cinfo.output_scanline < cinfo.output_height && ascii_index < HEIGHT) {
        jpeg_read_scanlines(&cinfo, &buffer, 1);
        for (int i = 0; i < WIDTH; i++) {
            if (i < cinfo.output_width) {
                // Calculate brightness
                int pixel_value = 0;
                if (cinfo.output_components == 3) { // RGB
                    pixel_value = (buffer[i * 3] + buffer[i * 3 + 1] + buffer[i * 3 + 2]) / 3;
                } else { // Grayscale
                    pixel_value = buffer[i];
                }
                // Map brightness to ascii index
                int ascii_index = (pixel_value * (strlen(ASCII_CHARS) - 1)) / 255;
                ascii_image[ascii_index][i] = ASCII_CHARS[ascii_index];
            } else {
                ascii_image[ascii_index][i] = ' ';
            }
        }
        ascii_image[ascii_index][WIDTH] = '\0'; // Null-terminate the string
        ascii_index++;
    }

    // Cleanup
    jpeg_finish_decompress(&cinfo);
    fclose(infile);
    free(buffer);

    // Output ASCII art
    for (int i = 0; i < HEIGHT; i++) {
        printf("%s\n", ascii_image[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <jpeg_file>\n", argv[0]);
        return 1;
    }

    convert_jpeg_to_ascii(argv[1]);
    
    return 0;
}