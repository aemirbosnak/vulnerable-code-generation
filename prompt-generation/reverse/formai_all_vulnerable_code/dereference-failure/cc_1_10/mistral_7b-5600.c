//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define WIDTH 30
#define HEIGHT 10
#define MAX_CHAR 128

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

void rgb_to_grayscale(pixel *pix, float alpha) {
    float grayscale;

    grayscale = 0.299 * pix->r + 0.587 * pix->g + 0.114 * pix->b + alpha;
    pix->r = grayscale > 255 ? 255 : (unsigned char)grayscale;
}

void image_to_ascii(const pixel *image, char *ascii_art, int width, int height) {
    int i, j, index;
    float alpha = 0.3;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            rgb_to_grayscale(&image[i * width + j], alpha);
            index = (image[i * width + j].r / 32) % 94;
            ascii_art[i * WIDTH + j] = index < 32 ? ' ' : '.',
                          '`' + index - 32;
        }
        ascii_art[i * WIDTH + j] += i < height - 1 ? '\n' : '\0';
    }
}

int main() {
    int i, j;
    pixel *image;
    char ascii_art[HEIGHT * WIDTH + HEIGHT];

    image = calloc(WIDTH * HEIGHT, sizeof(pixel));

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            image[i * WIDTH + j].r = i < HEIGHT / 2 ? j < WIDTH / 2 ? 255 : 0 :
                                                     j >= WIDTH - WIDTH / 2 ? 255 : 0;
            image[i * WIDTH + j].g = i < HEIGHT / 2 ? j >= WIDTH / 2 ? 255 : 0 :
                                                     j < WIDTH - WIDTH / 2 ? 255 : 0;
            image[i * WIDTH + j].b = i >= HEIGHT / 2 && j >= WIDTH / 2 ? 255 : 0;
        }
    }

    image_to_ascii(image, ascii_art, WIDTH, HEIGHT);

    printf("%s\n", ascii_art);

    free(image);

    return 0;
}