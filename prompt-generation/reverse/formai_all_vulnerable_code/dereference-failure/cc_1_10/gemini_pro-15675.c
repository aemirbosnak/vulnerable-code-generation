//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int width;
    int height;
    unsigned char *data;
} PixelArt;

PixelArt* pixel_art_create(int width, int height) {
    PixelArt *art = malloc(sizeof(PixelArt));
    art->width = width;
    art->height = height;
    art->data = malloc(width * height * 3);
    return art;
}

void pixel_art_destroy(PixelArt *art) {
    free(art->data);
    free(art);
}

void pixel_art_set_pixel(PixelArt *art, int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    int index = (y * art->width + x) * 3;
    art->data[index + 0] = r;
    art->data[index + 1] = g;
    art->data[index + 2] = b;
}

void pixel_art_save(PixelArt *art, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "P6\n%d %d\n255\n", art->width, art->height);
    fwrite(art->data, 1, art->width * art->height * 3, fp);
    fclose(fp);
}

int main() {
    PixelArt *art = pixel_art_create(256, 256);
    for (int y = 0; y < art->height; y++) {
        for (int x = 0; x < art->width; x++) {
            unsigned char r = (x * 255) / art->width;
            unsigned char g = (y * 255) / art->height;
            unsigned char b = 0;
            pixel_art_set_pixel(art, x, y, r, g, b);
        }
    }
    pixel_art_save(art, "gradient.ppm");
    pixel_art_destroy(art);
    return 0;
}