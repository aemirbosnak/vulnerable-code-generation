//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 60
#define MAX_PIXEL_VALUE 255

char ascii_art[HEIGHT][WIDTH];

void convert_pixel_to_ascii(int x, int y, int pixel_value) {
    int chars_per_pixel = ceil(MAX_PIXEL_VALUE / 70.0);      // 70 characters to represent pixel values between 0 and 255
    int ascii_index = ceil(pixel_value / chars_per_pixel);   // determine which ASCII character to use to represent the pixel
    ascii_art[y][x] = (char) (ascii_index + 32);             // offset the ASCII index to correspond to printable characters
}

void print_ascii_art() {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            putchar(ascii_art[i][j]);
        }
        putchar('\n');
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./converter <image_file_path>\n");
        exit(1);
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        fprintf(stderr, "Error: could not open file %s\n", argv[1]);
        exit(1);
    }

    // read file header
    char format[3];
    int width, height, max_value;

    if (fscanf(input_file, "%s\n%d %d\n%d\n", format, &width, &height, &max_value) != 4) {
        fprintf(stderr, "Error: invalid file format\n");
        exit(1);
    }

    if (strcmp(format, "P5")) {
        fprintf(stderr, "Error: only P5 format images are supported\n");
        exit(1);
    }

    if (width != WIDTH || height != HEIGHT) {
        fprintf(stderr, "Error: input image dimensions must be %dx%d\n", WIDTH, HEIGHT);
        exit(1);
    }

    if (max_value != MAX_PIXEL_VALUE) {
        fprintf(stderr, "Error: input image pixel values must be between 0 and %d\n", MAX_PIXEL_VALUE);
        exit(1);
    }

    // read pixel data
    unsigned char *image_data = malloc(sizeof(unsigned char) * width * height);
    fread(image_data, sizeof(unsigned char), width * height, input_file);
    fclose(input_file);
    
    // convert each pixel to ASCII character representation
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            int pixel_value = (int) image_data[y * HEIGHT + x];
            convert_pixel_to_ascii(x, y, pixel_value);
        }
    }

    // print the resulting ASCII art to the console
    print_ascii_art();

    free(image_data);
    return 0;
}