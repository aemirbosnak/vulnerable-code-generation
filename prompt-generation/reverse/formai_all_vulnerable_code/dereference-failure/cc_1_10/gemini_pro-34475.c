//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int width;
    int height;
    char *pixels;
} Image;

Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height);
    return image;
}

void free_image(Image *image) {
    free(image->pixels);
    free(image);
}

void set_pixel(Image *image, int x, int y, char pixel) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return;
    }
    image->pixels[x + y * image->width] = pixel;
}

char get_pixel(Image *image, int x, int y) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return 0;
    }
    return image->pixels[x + y * image->width];
}

void save_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(file, "P1\n%d %d\n", image->width, image->height);
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            fprintf(file, "%c", get_pixel(image, x, y));
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

int main() {
    Image *image = new_image(100, 100);

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            if (x < image->width / 2) {
                set_pixel(image, x, y, '0');
            } else {
                set_pixel(image, x, y, '1');
            }
        }
    }

    save_image(image, "output.pbm");

    free_image(image);

    return 0;
}