//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 30
#define HEIGHT 10

typedef struct {
    unsigned char r, g, b;
} pixel;

void read_image(const char *filename, pixel **pixels) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int magic_number;
    fread(&magic_number, sizeof(int), 1, file);

    if (magic_number != 0x4d42) { // 'M' 'B' for BMP
        fprintf(stderr, "Invalid file format\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    int file_size = 0;
    fread(&file_size, sizeof(int), 1, file);

    int offset_data = 0;
    fread(&offset_data, sizeof(int), 1, file);

    *pixels = malloc(WIDTH * HEIGHT * sizeof(pixel));

    int lines = (file_size - offset_data) / (3 * WIDTH);
    if (lines * WIDTH * 3 != file_size) {
        fprintf(stderr, "Invalid image size\n");
        free(*pixels);
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fseek(file, offset_data, SEEK_SET);
    fread(*pixels, sizeof(pixel), WIDTH * HEIGHT, file);
    fclose(file);
}

void print_pixel(FILE *asc_file, pixel p) {
    int level = 8;
    int i;

    for (i = 0; i < level; i++) {
        if (i < 5)
            putc((p.r >> (7 - i) & 1) ? '#' : '.', asc_file);
        if (i < 3)
            putc((p.g >> (5 - i) & 1) ? '#' : '.', asc_file);
        if (i < 1)
            putc((p.b >> (3 - i) & 1) ? '#' : '.', asc_file);
    }
}

void write_ascii(const char *input_image, const char *output_file) {
    pixel *pixels;
    read_image(input_image, &pixels);

    FILE *asc_file = fopen(output_file, "w");

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int line = y * WIDTH + x;
            print_pixel(asc_file, pixels[line]);
        }
        putc('\n', asc_file);
    }

    free(pixels);
    fclose(asc_file);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_image> <output_ascii>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    write_ascii(argv[1], argv[2]);
    return EXIT_SUCCESS;
}