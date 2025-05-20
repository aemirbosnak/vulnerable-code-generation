//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ASCII_CHARS = " .,-:;i1tfLCG08@";
int MAX_PIXEL_VAL = 255;

int get_pixel_val(unsigned char *pixels, int x, int y, int width) {
    return *(pixels + (y * width) + x);
}

int get_closest_ascii(int pixel_val) {
    int num_chars = strlen(ASCII_CHARS);
    int val_range = MAX_PIXEL_VAL / num_chars;
    return pixel_val / val_range;
}

void convert_to_ascii(unsigned char *pixels, int width, int height) {
    int ascii_width = 100;
    int ascii_height = (int)((float)height / ((float)width / (float)ascii_width) * 0.5);
    char ascii[ascii_height][ascii_width];

    for (int y = 0; y < ascii_height; y++) {
        for (int x = 0; x < ascii_width; x++) {
            int img_x = (int)((float)x / (float)ascii_width * (float)width);
            int img_y = (int)((float)y / (float)ascii_height * (float)height);
            int pixel_val = get_pixel_val(pixels, img_x, img_y, width);
            int closest_ascii = get_closest_ascii(pixel_val);
            ascii[y][x] = ASCII_CHARS[closest_ascii];
        }
    }

    for (int y = 0; y < ascii_height; y++) {
        printf("%s\n", ascii[y]);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s [IMAGE_PATH]\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        printf("Error opening file.\n");
        exit(1);
    }

    char header[54];
    fread(header, sizeof(unsigned char), 54, file);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bits_per_pixel = *(int*)&header[28];

    // Make sure it's an 8-bit grayscale image
    if (bits_per_pixel != 8) {
        printf("Unsupported image format.\n");
        exit(1);
    }

    unsigned char *pixels = malloc(width * height);
    fread(pixels, sizeof(unsigned char), width * height, file);

    fclose(file);

    convert_to_ascii(pixels, width, height);

    free(pixels);

    return 0;
}