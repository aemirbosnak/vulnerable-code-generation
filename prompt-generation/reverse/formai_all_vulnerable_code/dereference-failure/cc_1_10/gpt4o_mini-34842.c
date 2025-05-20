//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <jpeglib.h>
#include <stdint.h>

#define ASCII_CHARS "@%#*+=-:. "

void convert_image_to_ascii(const char *filename, int width, int height) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    FILE *infile = fopen(filename, "rb");
    if (!infile) {
        fprintf(stderr, "Can't open %s\n", filename);
        return;
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    int row_stride = cinfo.output_width * cinfo.output_components;
    unsigned char *buffer = (unsigned char *)malloc(row_stride);
    int pixel_count = 0;

    while (cinfo.output_scanline < cinfo.output_height) {
        jpeg_read_scanlines(&cinfo, &buffer, 1);
        for (int x = 0; x < cinfo.output_width; x += width) {
            int gray = 0;
            for (int comp = 0; comp < cinfo.output_components; ++comp) {
                gray += buffer[x * cinfo.output_components + comp];
            }
            gray /= cinfo.output_components;

            // Map the gray value to an ASCII character
            int ascii_index = (gray * (strlen(ASCII_CHARS) - 1)) / 255;
            putchar(ASCII_CHARS[ascii_index]);
            pixel_count++;

            // Newline when row width is reached
            if ((pixel_count % (cinfo.output_width / width)) == 0) {
                putchar('\n');
            }
        }
    }

    free(buffer);
    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);
    fclose(infile);
}

void print_usage(const char *program_name) {
    fprintf(stderr, "Usage: %s <image.jpg> <width> <height>\n", program_name);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    int width = atoi(argv[2]);
    int height = atoi(argv[3]);

    if (width <= 0 || height <= 0) {
        fprintf(stderr, "Width and height must be positive integers.\n");
        return EXIT_FAILURE;
    }

    convert_image_to_ascii(filename, width, height);
    return EXIT_SUCCESS;
}