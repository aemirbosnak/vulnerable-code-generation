//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: protected
#define _CRT_SECURE_NO_WARNINGS
#define MAX_IMAGE_SIZE 10000
#define ASCII_CHARSET " .:!*oe%$#@"
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

typedef struct {
    int width;
    int height;
    uint8_t* data;
} Image;

Image read_image(const char* filename);
void free_image(Image img);
void image_to_ascii(const Image img, const char* output_filename);

Image read_image(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fseek(file, 2, SEEK_SET); // Skip file signature and jump to image dimensions

    Image img;
    fread(&img.width, sizeof(int), 1, file);
    fread(&img.height, sizeof(int), 1, file);

    if (img.width <= 0 || img.height <= 0) {
        fprintf(stderr, "Error: Invalid image dimensions %d x %d\n", img.width, img.height);
        exit(EXIT_FAILURE);
    }

    img.data = (uint8_t*) malloc(img.width * img.height * sizeof(uint8_t));
    fread(img.data, sizeof(uint8_t), img.width * img.height, file);

    fclose(file);
    return img;
}

void free_image(Image img) {
    free(img.data);
}

void image_to_ascii(const Image img, const char* output_filename) {
    FILE* output_file = fopen(output_filename, "w");
    if (!output_file) {
        fprintf(stderr, "Error: Unable to open output file %s\n", output_filename);
        exit(EXIT_FAILURE);
    }

    for (int y = 0; y < img.height; ++y) {
        for (int x = 0; x < img.width; ++x) {
            uint8_t pixel = img.data[y * img.width + x];
            putchar('\n');
            for (int col = MIN(x, img.width - x - 1); col > 0; --col) {
                putchar(ASCII_CHARSET[MIN(255 * pixel / (img.width * img.height), 15)]);
            }
            putchar(ASCII_CHARSET[MIN(255 * pixel / img.width, 15)]);
            for (int col = 0; col < MIN(img.width - x - 1, img.width); ++col) {
                putchar(ASCII_CHARSET[MIN(255 * pixel / (img.width * img.height), 15)]);
            }
        }
        putchar('\n');
    }

    fclose(output_file);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_image> <output_ascii>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    Image img = read_image(argv[1]);
    image_to_ascii(img, argv[2]);
    free_image(img);

    return EXIT_SUCCESS;
}