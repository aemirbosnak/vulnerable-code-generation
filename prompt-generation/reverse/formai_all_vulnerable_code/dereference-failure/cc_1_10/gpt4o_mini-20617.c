//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jpeglib.h>
#include <assert.h>

// Cryptic constants to aid transformation
#define WIDTH 100
#define HEIGHT 100
#define CHAR_LIST "@%#*+=-:. "
#define CHAR_LIST_SIZE 10

// Struct to hold pixel data
typedef struct {
    unsigned char r, g, b;
} Pixel;

// Function to convert pixel to grayscale
unsigned char rgb_to_gray(Pixel pixel) {
    return (unsigned char)(0.299 * pixel.r + 0.587 * pixel.g + 0.114 * pixel.b);
}

// Function to load JPEG image
Pixel* load_jpeg(const char *filename, int *width, int *height) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);

    FILE *infile = fopen(filename, "rb");
    if (!infile) {
        fprintf(stderr, "Can't open %s\n", filename);
        return NULL;
    }

    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    *width = cinfo.output_width;
    *height = cinfo.output_height;
    Pixel *pixels = (Pixel *)malloc(sizeof(Pixel) * (*width) * (*height));

    if (!pixels) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    for (int i = 0; i < *height; i++) {
        unsigned char *row_pointer[1];
        row_pointer[0] = (unsigned char *)malloc(cinfo.output_width * cinfo.output_components);
        jpeg_read_scanlines(&cinfo, row_pointer, 1);
        for (int j = 0; j < *width; j++) {
            pixels[i * (*width) + j].r = row_pointer[0][j * 3];
            pixels[i * (*width) + j].g = row_pointer[0][j * 3 + 1];
            pixels[i * (*width) + j].b = row_pointer[0][j * 3 + 2];
        }
        free(row_pointer[0]);
    }

    jpeg_finish_decompress(&cinfo);
    fclose(infile);

    return pixels;
}

// Function to convert image to ASCII
void image_to_ascii(Pixel *pixels, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            unsigned char gray = rgb_to_gray(pixels[y * width + x]);
            int index = gray * CHAR_LIST_SIZE / 256;
            putchar(CHAR_LIST[index]);
        }
        putchar('\n');
    }
}

// Main function to execute the conversion
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int width, height;
    Pixel *pixels = load_jpeg(argv[1], &width, &height);
    if (!pixels) {
        return EXIT_FAILURE;
    }

    if (width > WIDTH) {
        height *= WIDTH / (float)width;
        width = WIDTH;
    }
    if (height > HEIGHT) {
        width *= HEIGHT / (float)height;
        height = HEIGHT;
    }

    image_to_ascii(pixels, width, height);
    free(pixels);

    return EXIT_SUCCESS;
}