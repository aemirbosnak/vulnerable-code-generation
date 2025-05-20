//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define ASCII_CHARS ".:+*#@"

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

void load_image(const char *filename, Image *image) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    rewind(file);

    image->data = malloc(filesize);
    fread(image->data, filesize, 1, file);
    fclose(file);

    image->width = filesize / image->height;
}

void save_ascii_art(const char *filename, const char *ascii_art) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    fputs(ascii_art, file);
    fclose(file);
}

void image_to_ascii_art(Image *image, char *ascii_art) {
    int ascii_index = 0;
    for (int y = 0; y < image->height; ++y) {
        for (int x = 0; x < image->width; ++x) {
            int value = image->data[y * image->width + x];
            int brightness = value >> 4;

            ascii_art[ascii_index++] = ASCII_CHARS[brightness];
        }
        ascii_art[ascii_index++] = '\n';
    }
    ascii_art[ascii_index] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input.bmp output.txt\n", argv[0]);
        return 1;
    }

    Image image;
    load_image(argv[1], &image);

    char ascii_art[MAX_WIDTH * MAX_HEIGHT + 1];
    image_to_ascii_art(&image, ascii_art);

    save_ascii_art(argv[2], ascii_art);

    printf("ASCII art saved to %s\n", argv[2]);

    return 0;
}