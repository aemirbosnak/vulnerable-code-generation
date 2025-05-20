//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define WIDTH 51
#define HEIGHT 5
#define MAX_PIXEL_VALUE 255
#define ASCII_ART_CHARS " .:!*oe%$#@"

typedef struct {
    unsigned char *data;
    int width;
    int height;
} Image;

Image load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    fseek(fp, 2, SEEK_SET); // Skip file header
    Image img;
    img.width = 0;
    img.height = 0;
    fread(&img.width, sizeof(int), 1, fp);
    fread(&img.height, sizeof(int), 1, fp);
    img.data = (unsigned char *)calloc(img.width * img.height, sizeof(unsigned char));
    fread(img.data, img.width * img.height, 1, fp);
    fclose(fp);
    return img;
}

void print_ascii_art(const char *ascii_art, int width) {
    printf("\n");
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < width; ++j) {
            printf("%c", ascii_art[i * WIDTH + j]);
        }
        printf("\n");
    }
}

void convert_image_to_ascii_art(const Image img) {
    char ascii_art[HEIGHT][WIDTH];

    for (int y = 0; y < img.height; ++y) {
        for (int x = 0; x < img.width; ++x) {
            int pixel_value = img.data[y * img.width + x];
            int ascii_index = (int)round((float)pixel_value / (MAX_PIXEL_VALUE / (sizeof(ASCII_ART_CHARS) - 1)));
            ascii_art[y][x] = ASCII_ART_CHARS[ascii_index];
        }
    }

    print_ascii_art(ascii_art[0], img.width);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    Image img = load_image(argv[1]);
    convert_image_to_ascii_art(img);
    free(img.data);
    return 0;
}