//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 480
#define BITS_PER_PIXEL 32

typedef struct {
    int x;
    int y;
    int color;
} Pixel;

typedef struct {
    Pixel pixels[WIDTH * HEIGHT];
} Image;

void initImage(Image *image) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            image->pixels[i * HEIGHT + j].color = rand() % 256;
        }
    }
}

void drawLine(Image *image, int x1, int y1, int x2, int y2) {
    int i, j;
    for (i = x1; i <= x2; i++) {
        for (j = y1; j <= y2; j++) {
            image->pixels[i * HEIGHT + j].color = image->pixels[x1 * HEIGHT + y1].color;
        }
    }
}

void drawRectangle(Image *image, int x, int y, int width, int height) {
    int i, j;
    for (i = x; i <= x + width; i++) {
        for (j = y; j <= y + height; j++) {
            image->pixels[i * HEIGHT + j].color = image->pixels[x * HEIGHT + y].color;
        }
    }
}

void drawCircle(Image *image, int x, int y, int radius) {
    int i, j;
    for (i = x - radius; i <= x + radius; i++) {
        for (j = y - radius; j <= y + radius; j++) {
            if (sqrt((i * i) + (j * j)) <= radius) {
                image->pixels[i * HEIGHT + j].color = image->pixels[x * HEIGHT + y].color;
            }
        }
    }
}

void updateImage(Image *image) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (image->pixels[i * HEIGHT + j].color == 255) {
                image->pixels[i * HEIGHT + j].color = rand() % 256;
            }
        }
    }
}

void draw(Image *image) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            printf("%d ", image->pixels[i * HEIGHT + j].color);
        }
        printf("\n");
    }
}

int main() {
    Image *image;
    initImage(&image);
    drawRectangle(image, 100, 100, 200, 100);
    drawCircle(image, 250, 250, 50);
    updateImage(image);
    draw(image);
    return 0;
}