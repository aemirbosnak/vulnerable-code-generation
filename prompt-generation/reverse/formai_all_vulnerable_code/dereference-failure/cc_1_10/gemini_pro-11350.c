//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int width;
    int height;
    char **pixels;
} Image;

Image *create_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++) {
        image->pixels[i] = malloc(sizeof(char) * width);
    }
    return image;
}

void destroy_image(Image *image) {
    for (int i = 0; i < image->height; i++) {
        free(image->pixels[i]);
    }
    free(image->pixels);
    free(image);
}

void set_pixel(Image *image, int x, int y, char c) {
    if (x >= 0 && x < image->width && y >= 0 && y < image->height) {
        image->pixels[y][x] = c;
    }
}

char get_pixel(Image *image, int x, int y) {
    if (x >= 0 && x < image->width && y >= 0 && y < image->height) {
        return image->pixels[y][x];
    }
    return ' ';
}

void print_image(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            printf("%c", get_pixel(image, j, i));
        }
        printf("\n");
    }
}

int main() {
    Image *image = create_image(10, 10);

    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height; j++) {
            if (i == 0 || i == image->width - 1 || j == 0 || j == image->height - 1) {
                set_pixel(image, i, j, '#');
            } else {
                set_pixel(image, i, j, ' ');
            }
        }
    }

    print_image(image);

    destroy_image(image);

    return 0;
}