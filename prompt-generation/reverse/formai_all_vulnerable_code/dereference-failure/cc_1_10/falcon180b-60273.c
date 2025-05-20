//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
    char *pixels;
    int width;
    int height;
} Image;

Image load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    char *data = malloc(size);
    fread(data, size, 1, fp);
    fclose(fp);

    Image img = { data, MAX_WIDTH, MAX_HEIGHT };
    return img;
}

void free_image(Image *img) {
    free(img->pixels);
}

int get_pixel(Image *img, int x, int y) {
    if (x < 0 || x >= img->width || y < 0 || y >= img->height) {
        return 0;
    }

    char *p = img->pixels + y * img->width + x;
    return *p;
}

int main() {
    Image img = load_image("example.bmp");

    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.width; x++) {
            int pixel = get_pixel(&img, x, y);
            if (pixel == 0) {
                putchar(' ');
            } else {
                putchar('*');
            }
        }
        putchar('\n');
    }

    free_image(&img);

    return 0;
}