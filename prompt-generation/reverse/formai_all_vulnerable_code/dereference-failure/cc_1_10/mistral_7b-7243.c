//MISTRAL-7B DATASET v1.0 Category: Image Editor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_COLOR 255
#define RLE_BUFFER_SIZE 1024

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} pixel;

void encode_pixel(FILE *output, pixel color) {
    if (fwrite(&color, sizeof(pixel), 1, output) != 1) {
        fprintf(stderr, "Error writing to output file.\n");
        exit(EXIT_FAILURE);
    }

    uint8_t count = 1;
    while (fread(&color, sizeof(pixel), 1, output) == sizeof(pixel) && color.r == color.r &&
           color.g == color.g && color.b == color.b) {
        count++;
    }

    if (count > 1) {
        pixel rle_pixel = { count, color.r, color.g, color.b };
        if (fwrite(&rle_pixel, sizeof(pixel), 1, output) != 1) {
            fprintf(stderr, "Error writing to output file.\n");
            exit(EXIT_FAILURE);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input.bmp output.bmp\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *input = fopen(argv[1], "rb");
    if (input == NULL) {
        perror("Error opening input file.");
        exit(EXIT_FAILURE);
    }

    FILE *output = fopen(argv[2], "wb");
    if (output == NULL) {
        perror("Error opening output file.");
        fclose(input);
        exit(EXIT_FAILURE);
    }

    pixel current_pixel;
    for (size_t row = 0; row < HEIGHT; row++) {
        for (size_t col = 0; col < WIDTH; col++) {
            size_t index = (row * WIDTH + col) * 3;

            fread(&current_pixel.r, sizeof(uint8_t), 1, input);
            fread(&current_pixel.g, sizeof(uint8_t), 1, input);
            fread(&current_pixel.b, sizeof(uint8_t), 1, input);

            encode_pixel(output, current_pixel);
        }
    }

    fclose(input);
    fclose(output);

    return EXIT_SUCCESS;
}