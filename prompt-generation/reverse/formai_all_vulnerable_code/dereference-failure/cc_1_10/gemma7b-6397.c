//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 256

typedef struct Image {
    int width;
    int height;
    unsigned char **pixels;
} Image;

Image *image_new(int w, int h) {
    Image *img = malloc(sizeof(Image));
    img->width = w;
    img->height = h;
    img->pixels = malloc(h * sizeof(unsigned char *) + h);
    for (int i = 0; i < h; i++) {
        img->pixels[i] = malloc(w * sizeof(unsigned char));
    }
    return img;
}

void image_free(Image *img) {
    for (int i = 0; i < img->height; i++) {
        free(img->pixels[i]);
    }
    free(img->pixels);
    free(img);
}

void image_draw(Image *img, int x, int y, unsigned char value) {
    if (x < 0 || x >= img->width || y < 0 || y >= img->height) {
        return;
    }
    img->pixels[y][x] = value;
}

void image_to_ascii(Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            unsigned char value = img->pixels[y][x];
            switch (value) {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(":");
                    break;
                case 2:
                    printf("=");
                    break;
                case 3:
                    printf("$");
                    break;
                default:
                    printf("?");
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    Image *img = image_new(8, 8);
    image_draw(img, 0, 0, 2);
    image_draw(img, 1, 1, 1);
    image_draw(img, 2, 2, 3);
    image_to_ascii(img);
    image_free(img);

    return 0;
}