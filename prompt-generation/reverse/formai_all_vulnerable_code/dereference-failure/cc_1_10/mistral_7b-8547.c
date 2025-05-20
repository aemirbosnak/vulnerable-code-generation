//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 30
#define HEIGHT 10
#define MAX_COLOR 7
#define FILENAME "image.bmp"

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} pixel;

void read_bmp(const char *filename, unsigned char *image, int *width, int *height) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) return;

    char magic_number[2];
    fread(magic_number, sizeof(char), 2, fp);
    if (strncmp(magic_number, "BM", 2) != 0) {
        fclose(fp);
        return;
    }

    unsigned int file_size;
    fread(&file_size, sizeof(unsigned int), 1, fp);
    file_size -= sizeof(unsigned int) * 2;

    unsigned short reserved1, reserved2;
    fread(&reserved1, sizeof(unsigned short), 1, fp);
    fread(&reserved2, sizeof(unsigned short), 1, fp);

    unsigned int offset_data = file_size;
    fread(&offset_data, sizeof(unsigned int), 1, fp);

    *width = *(unsigned int*)(fp + 18);
    *height = *(unsigned int*)(fp + 22);

    int line_size = (*width) * (sizeof(pixel) / 8);
    image = malloc(line_size * *height);

    for (int y = 0; y < *height; y++) {
        fread(image + y * line_size, sizeof(pixel), *width, fp);
    }

    fclose(fp);
}

void print_ascii(pixel *image, int width, int height) {
    const char symbols[] = {
        ' ', '.', ':', ';', '=', '>', '^', '|', '`', '~',
        '!', '@', '#', '%', '&', '*', '(', ')', '_', '+',
        '`', '|', '\\', '/', '?', '>', '=', '-', '+', '|'
    };

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int brightness = image[y * width + x].red + image[y * width + x].green + image[y * width + x].blue;
            brightness /= 3;
            if (brightness > 128) brightness -= 128;
            int symbol_index = brightness * (sizeof(symbols) / sizeof(symbols[0]));
            printf("%c", symbols[symbol_index]);
        }
        printf("\n");
    }
}

int main() {
    unsigned char *image;
    int width, height;

    read_bmp(FILENAME, image, &width, &height);
    print_ascii(image, width, height);

    free(image);
    return 0;
}