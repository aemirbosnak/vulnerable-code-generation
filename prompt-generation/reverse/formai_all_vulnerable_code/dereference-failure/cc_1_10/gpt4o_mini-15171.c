//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <jpeglib.h>

#define MAX_WIDTH 800
#define MAX_HEIGHT 800
#define ASCII_CHARS "@%#*+=-:. "

typedef struct {
    unsigned char r, g, b;
} Pixel;

void invert_color(Pixel *pixel) {
    pixel->r = 255 - pixel->r;
    pixel->g = 255 - pixel->g;
    pixel->b = 255 - pixel->b;
}

int get_brightness(Pixel pixel) {
    return (0.3 * pixel.r) + (0.59 * pixel.g) + (0.11 * pixel.b);
}

char pixel_to_ascii(Pixel pixel) {
    int brightness = get_brightness(pixel);
    int index = (brightness * (strlen(ASCII_CHARS) - 1)) / 255;
    return ASCII_CHARS[index];
}

void jpeg_to_pixels(const char *filename, Pixel *pixels, int *width, int *height) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    FILE *infile = fopen(filename, "rb");
    if (!infile) {
        fprintf(stderr, "Could not open %s\n", filename);
        exit(1);
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    *width = cinfo.output_width;
    *height = cinfo.output_height;

    if (*width > MAX_WIDTH || *height > MAX_HEIGHT) {
        fprintf(stderr, "Image dimensions exceed the maximum allowed size of %dx%d\n", MAX_WIDTH, MAX_HEIGHT);
        exit(1);
    }

    for (int y = 0; y < cinfo.output_height; y++) {
        for (int x = 0; x < cinfo.output_width; x++) {
            Pixel pixel;
            unsigned char tmp[3];
            jpeg_read_scanlines(&cinfo, &tmp, 1);
            pixel.r = tmp[0];
            pixel.g = tmp[1];
            pixel.b = tmp[2];
            invert_color(&pixel);
            pixels[y * (*width) + x] = pixel;
        }
    }

    jpeg_finish_decompress(&cinfo);
    fclose(infile);
}

void convert_to_ascii(const Pixel *pixels, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            putchar(pixel_to_ascii(pixels[y * width + x]));
        }
        putchar('\n');
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image_file.jpg>\n", argv[0]);
        return 1;
    }

    Pixel pixels[MAX_WIDTH * MAX_HEIGHT];
    int width = 0, height = 0;

    jpeg_to_pixels(argv[1], pixels, &width, &height);
    printf("\033[2J\033[H");  // Clear screen and reset cursor position.
    convert_to_ascii(pixels, width, height);

    return 0;
}