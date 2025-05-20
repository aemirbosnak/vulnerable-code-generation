//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <string.h>

#define WIDTH 640
#define HEIGHT 480

typedef struct {
    int x, y;
    int r, g, b;
} Pixel;

typedef struct {
    Pixel pixels[WIDTH * HEIGHT];
} Image;

void initImage(Image *image) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            image->pixels[i * HEIGHT + j].x = i;
            image->pixels[i * HEIGHT + j].y = j;
            image->pixels[i * HEIGHT + j].r = i % 2 == 0 ? 0xFF : 0x00;
            image->pixels[i * HEIGHT + j].g = j % 2 == 0 ? 0xFF : 0x00;
            image->pixels[i * HEIGHT + j].b = i % 3 == 0 ? 0xFF : 0x00;
        }
    }
}

void drawLine(Image *image, int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int err = dx + dy;
    int y = y1;

    for (int x = x1; x <= x2; x++) {
        image->pixels[x * HEIGHT + y].r = (x - x1) * (y - y1) / err;
        image->pixels[x * HEIGHT + y].g = (x - x1) * (y - y1) / err;
        image->pixels[x * HEIGHT + y].b = (x - x1) * (y - y1) / err;
        y += dy;
        if (y >= HEIGHT) {
            y = 0;
            x++;
        }
    }
}

void drawCircle(Image *image, int x, int y, int radius) {
    int x1 = x - radius;
    int y1 = y - radius;
    int x2 = x + radius;
    int y2 = y + radius;

    drawLine(image, x1, y1, x2, y2);
    drawLine(image, x1, y2, x2, y1);
    drawLine(image, x1, y1, x2, y2);
}

void drawColor(Image *image, int x, int y, int r, int g, int b) {
    image->pixels[x * HEIGHT + y].r = r;
    image->pixels[x * HEIGHT + y].g = g;
    image->pixels[x * HEIGHT + y].b = b;
}

void display(Image *image) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            printf("%02X%02X%02X", image->pixels[i * HEIGHT + j].r, image->pixels[i * HEIGHT + j].g, image->pixels[i * HEIGHT + j].b);
        }
        printf("\n");
    }
}

int main() {
    Image *image = malloc(sizeof(Image));
    initImage(image);

    drawCircle(image, 100, 100, 50);
    drawLine(image, 200, 100, 300, 200);
    drawColor(image, 150, 250, 0xFF, 0x00, 0xFF);

    display(image);

    return 0;
}