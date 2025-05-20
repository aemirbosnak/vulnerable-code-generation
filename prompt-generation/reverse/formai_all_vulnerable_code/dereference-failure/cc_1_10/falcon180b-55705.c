//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

#define WIDTH 500
#define HEIGHT 500
#define MAX_COLOR_VALUE 255
#define MAX_PALETTE_SIZE 256
#define MAX_IMAGE_SIZE (WIDTH * HEIGHT)

typedef struct {
    int red;
    int green;
    int blue;
} Color;

typedef struct {
    int index;
    int count;
} PaletteEntry;

typedef struct {
    Color *colors;
    int size;
} Palette;

typedef struct {
    int width;
    int height;
    Color *data;
} Image;

void generate_random_palette(Palette *palette) {
    for (int i = 0; i < palette->size; i++) {
        palette->colors[i] = (Color){rand() % MAX_COLOR_VALUE, rand() % MAX_COLOR_VALUE, rand() % MAX_COLOR_VALUE};
    }
}

void generate_random_image(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        int index = rand() % image->width * image->height;
        Color color = image->data[index];
        image->data[index] = image->data[i];
        image->data[i] = color;
    }
}

void write_bmp_file(const char *filename, const Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);
    fwrite(image->data, sizeof(Color), image->width * image->height, file);

    fclose(file);
}

int main() {
    srand(time(NULL));

    Palette palette;
    generate_random_palette(&palette);

    Image image;
    image.width = WIDTH;
    image.height = HEIGHT;
    image.data = malloc(image.width * image.height * sizeof(Color));
    if (!image.data) {
        printf("Error: could not allocate memory for image\n");
        exit(1);
    }

    generate_random_image(&image);

    write_bmp_file("random.bmp", &image);

    return 0;
}