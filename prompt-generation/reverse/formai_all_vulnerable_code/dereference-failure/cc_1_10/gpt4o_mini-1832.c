//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <jpeglib.h>
#include <stdint.h>

#define ASCII_CHARS "@%#*+=-:. " // Characters used for ASCII art

// Function to map intensity to ASCII character
char intensity_to_ascii(uint8_t intensity) {
    int index = (intensity * (strlen(ASCII_CHARS) - 1)) / 255;
    return ASCII_CHARS[index];
}

// Function to convert JPEG image to ASCII art
void jpeg_to_ascii(const char *filename) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    FILE *infile;
    
    // Open the JPEG file
    if ((infile = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "Error opening file %s!\n", filename);
        return;
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    // Allocate buffer for one row of pixels
    int row_stride = cinfo.output_width * cinfo.output_components;
    uint8_t *buffer = (uint8_t *)malloc(row_stride);

    // Read and process pixels
    while (cinfo.output_scanline < cinfo.output_height) {
        jpeg_read_scanlines(&cinfo, &buffer, 1);
        for (int x = 0; x < cinfo.output_width; x++) {
            uint8_t r = buffer[x * cinfo.output_components];
            uint8_t g = buffer[x * cinfo.output_components + 1];
            uint8_t b = buffer[x * cinfo.output_components + 2];

            // Convert to grayscale using luminosity method
            uint8_t gray = (uint8_t)(0.21 * r + 0.72 * g + 0.07 * b);
            putchar(intensity_to_ascii(gray));
        }
        putchar('\n'); // New line for each row
    }

    // Cleanup
    jpeg_finish_decompress(&cinfo);
    free(buffer);
    fclose(infile);
}

// Main function
int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image-file.jpg>\n", argv[0]);
        return EXIT_FAILURE;
    }

    jpeg_to_ascii(argv[1]);

    return EXIT_SUCCESS;
}