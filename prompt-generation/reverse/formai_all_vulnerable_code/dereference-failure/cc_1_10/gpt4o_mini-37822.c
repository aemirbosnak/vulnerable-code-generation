//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <jpeglib.h>

#define ASCII_CHARS "@%#*+=-:. "
#define ASCII_LENGTH (sizeof(ASCII_CHARS) - 1)

void rgb_to_ascii(uint8_t r, uint8_t g, uint8_t b, char *ascii_char) {
    int grey = (r + g + b) / 3;
    int index = (grey * ASCII_LENGTH) / 256; // Normalize to ASCII length
    *ascii_char = ASCII_CHARS[index];
}

void jpeg_to_ascii(const char *filename) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    FILE *infile;
    uint8_t *buffer;
    int row_stride;

    if ((infile = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "Cannot open %s\n", filename);
        return;
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    row_stride = cinfo.output_width * cinfo.output_components;
    buffer = (uint8_t *)malloc(row_stride);

    printf("Image converted to ASCII art:\n");

    while (cinfo.output_scanline < cinfo.output_height) {
        jpeg_read_scanlines(&cinfo, &buffer, 1);
        for (int x = 0; x < cinfo.output_width; x += 2) {
            char ascii_char;
            rgb_to_ascii(buffer[x * cinfo.output_components],
                         buffer[x * cinfo.output_components + 1],
                         buffer[x * cinfo.output_components + 2], &ascii_char);
            printf("%c", ascii_char);
        }
        printf("\n");
    }

    free(buffer);
    jpeg_finish_decompress(&cinfo);
    fclose(infile);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    jpeg_to_ascii(filename);

    return EXIT_SUCCESS;
}