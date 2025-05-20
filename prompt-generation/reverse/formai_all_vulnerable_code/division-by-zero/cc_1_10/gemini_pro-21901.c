//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define WIDTH 640
#define HEIGHT 480

#define MAX_COLORS 256

typedef struct {
    uint8_t r, g, b;
} Color;

typedef struct {
    Color colors[MAX_COLORS];
    uint8_t num_colors;
} Palette;

typedef struct {
    uint8_t w, h;
    uint8_t pixels[WIDTH * HEIGHT];
} Image;

void load_palette(Palette *palette, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("fopen");
        exit(1);
    }

    fread(&palette->num_colors, sizeof(uint8_t), 1, file);
    for (int i = 0; i < palette->num_colors; i++) {
        fread(&palette->colors[i], sizeof(Color), 1, file);
    }

    fclose(file);
}

void load_image(Image *image, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("fopen");
        exit(1);
    }

    fread(&image->w, sizeof(uint8_t), 1, file);
    fread(&image->h, sizeof(uint8_t), 1, file);
    fread(image->pixels, sizeof(uint8_t), image->w * image->h, file);

    fclose(file);
}

void save_image(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("fopen");
        exit(1);
    }

    fwrite(&image->w, sizeof(uint8_t), 1, file);
    fwrite(&image->h, sizeof(uint8_t), 1, file);
    fwrite(image->pixels, sizeof(uint8_t), image->w * image->h, file);

    fclose(file);
}

void generate_image(Image *image, Palette *palette) {
    for (int y = 0; y < image->h; y++) {
        for (int x = 0; x < image->w; x++) {
            image->pixels[y * image->w + x] = rand() % palette->num_colors;
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <palette file> <image file> <output file>\n", argv[0]);
        exit(1);
    }

    Palette palette;
    load_palette(&palette, argv[1]);

    Image image;
    load_image(&image, argv[2]);

    generate_image(&image, &palette);

    save_image(&image, argv[3]);

    return 0;
}