//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <jpeglib.h>

#define WIDTH 80
#define HEIGHT 40
#define ASCII_CHARS "@%#*+=-:. "

// A tender function to handle the image loading
void load_image(const char *filename, unsigned char (*image)[3]) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    FILE *infile;

    if ((infile = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "Cannot open %s.\n", filename);
        exit(1);
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    while (cinfo.output_scanline < cinfo.output_height) {
        unsigned char *buffer_array[1];
        buffer_array[0] = (unsigned char *)malloc(cinfo.output_width * cinfo.output_components);
        jpeg_read_scanlines(&cinfo, buffer_array, 1);
        for (int i = 0; i < cinfo.output_width; i++) {
            int index = (cinfo.output_scanline - 1) * WIDTH + i;
            image[index][0] = buffer_array[0][i * 3];   // Red
            image[index][1] = buffer_array[0][i * 3 + 1]; // Green
            image[index][2] = buffer_array[0][i * 3 + 2]; // Blue
        }
        free(buffer_array[0]);
    }

    jpeg_finish_decompress(&cinfo);
    fclose(infile);
}

// A function to depict the artistry through grayscale
char pixel_to_ascii(unsigned char r, unsigned char g, unsigned char b) {
    float gray = (0.3 * r + 0.59 * g + 0.11 * b) / 255.0;
    int char_idx = gray * (strlen(ASCII_CHARS) - 1);
    return ASCII_CHARS[char_idx];
}

// A sonnet to the transformation
void print_ascii_art(unsigned char (*image)[3]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            char ascii = pixel_to_ascii(image[y * WIDTH + x][0],
                                         image[y * WIDTH + x][1],
                                         image[y * WIDTH + x][2]);
            putchar(ascii);
        }
        putchar('\n');
    }
}

// For love knows no bounds, run the program
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <jpeg-file>\n", argv[0]);
        return 1;
    }

    unsigned char (*image)[3] = malloc(WIDTH * HEIGHT * sizeof(*image));
    if (image == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    load_image(argv[1], image);
    print_ascii_art(image);
    free(image);

    return 0;
}