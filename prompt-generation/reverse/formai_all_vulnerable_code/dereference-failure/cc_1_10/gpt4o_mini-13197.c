//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jpeglib.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define CHAR_SET " .:-=+*%@#"

void decodeImage(const char *filename, unsigned char image[MAX_HEIGHT][MAX_WIDTH][3], int *width, int *height) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
  
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    FILE *infile = fopen(filename, "rb");
  
    if (infile == NULL) {
        fprintf(stderr, "Error opening JPEG file: %s\n", filename);
        exit(1);
    }
  
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);
  
    *width = cinfo.output_width;
    *height = cinfo.output_height;
  
    int row_stride = cinfo.output_width * cinfo.output_components;
    while (cinfo.output_scanline < cinfo.output_height) {
        unsigned char *buffer_array[1];
        buffer_array[0] = (unsigned char*)malloc(row_stride);
        jpeg_read_scanlines(&cinfo, buffer_array, 1);
  
        for (int x = 0; x < cinfo.output_width; x++) {
            int r = buffer_array[0][x * 3];
            int g = buffer_array[0][x * 3 + 1];
            int b = buffer_array[0][x * 3 + 2];
            unsigned char grayscale = (r + g + b) / 3;
            image[cinfo.output_scanline - 1][x][0] = grayscale;
        }
        free(buffer_array[0]);
    }
  
    jpeg_finish_decompress(&cinfo);
    fclose(infile);
}

void createAsciiArt(unsigned char image[MAX_HEIGHT][MAX_WIDTH][3], int width, int height) {
    printf("Behold, the art of pixels transformed into verses:\n\n");
  
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char grayscale = image[i][j][0];
            char asciiChar = CHAR_SET[(grayscale * (strlen(CHAR_SET) - 1)) / 255];
            putchar(asciiChar);
        }
        putchar('\n');
    }
  
    printf("\nThis creation, born of love and light, whispers gently to your heart,\n");
    printf("Each character a promise, each pixel a sigh,\n");
    printf("Join me in this dance of shades, where romance blooms in the night...\n");
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image.jpg>\n", argv[0]);
        return 1;
    }

    unsigned char image[MAX_HEIGHT][MAX_WIDTH][3] = {0};
    int width, height;

    decodeImage(argv[1], image, &width, &height);
  
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        fprintf(stderr, "Image size exceeds maximum allowed dimensions (100x100).\n");
        return 1;
    }

    createAsciiArt(image, width, height);
    return 0;
}