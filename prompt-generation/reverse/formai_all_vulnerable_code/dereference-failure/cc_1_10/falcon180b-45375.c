//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_COLORS 256
#define PIXEL_SIZE 4
#define COLOR_DEPTH 32

typedef struct {
    int r;
    int g;
    int b;
} Color;

Color generateRandomColor() {
    Color color;
    color.r = rand() % 256;
    color.g = rand() % 256;
    color.b = rand() % 256;
    return color;
}

void initImage(Color **image) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            image[i][j] = generateRandomColor();
        }
    }
}

void printImage(Color **image) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%02X%02X%02X ", image[i][j].r, image[i][j].g, image[i][j].b);
        }
        printf("\n");
    }
}

int main() {
    Color **image;
    srand(time(NULL));
    image = (Color **)malloc(HEIGHT * sizeof(Color *));
    for (int i = 0; i < HEIGHT; i++) {
        image[i] = (Color *)malloc(WIDTH * sizeof(Color));
    }
    initImage(image);
    printImage(image);
    free(image);
    return 0;
}