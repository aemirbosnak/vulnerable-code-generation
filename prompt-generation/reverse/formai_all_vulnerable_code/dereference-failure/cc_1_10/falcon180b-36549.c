//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_COLORS 256

typedef struct {
    int r;
    int g;
    int b;
} Color;

int main(int argc, char **argv) {
    // Initialize random seed
    srand(time(NULL));

    // Initialize colors
    Color *colors = malloc(MAX_COLORS * sizeof(Color));
    for (int i = 0; i < MAX_COLORS; i++) {
        colors[i].r = rand() % 256;
        colors[i].g = rand() % 256;
        colors[i].b = rand() % 256;
    }

    // Create image
    unsigned char *image = malloc(WIDTH * HEIGHT * 3);
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int colorIndex = rand() % MAX_COLORS;
            Color color = colors[colorIndex];
            image[(y * WIDTH + x) * 3] = color.r;
            image[(y * WIDTH + x) * 3 + 1] = color.g;
            image[(y * WIDTH + x) * 3 + 2] = color.b;
        }
    }

    // Save image as PNG
    FILE *fp = fopen("pixel_art.png", "wb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    fwrite(image, 1, WIDTH * HEIGHT * 3, fp);

    fclose(fp);

    return 0;
}