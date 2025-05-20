//MISTRAL-7B DATASET v1.0 Category: Pixel Art Generator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WIDTH 80
#define HEIGHT 20

typedef struct {
    unsigned char r, g, b;
} pixel;

pixel palette[16] = {
    {255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 0},
    {0, 255, 255}, {255, 0, 255}, {128, 128, 128}, {0, 0, 0},
    {192, 192, 192}, {255, 128, 0}, {0, 192, 0}, {0, 0, 192},
    {128, 0, 128}, {192, 0, 192}, {128, 128, 128}
};

pixel **image;

void createImage() {
    int i, j;

    image = (pixel **)calloc(HEIGHT, sizeof(pixel *));

    for (i = 0; i < HEIGHT; i++) {
        image[i] = (pixel *)calloc(WIDTH, sizeof(pixel));
    }
}

void clearImage() {
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            image[i][j] = palette[0];
        }
    }
}

void drawRect(int x, int y, int width, int height, pixel fillColor) {
    int i, j;

    for (i = y; i < y + height; i++) {
        for (j = x; j < x + width; j++) {
            image[i][j] = fillColor;
        }
    }
}

void saveImage(const char *filename) {
    FILE *fp;
    int i, j;
    char fileType[3] = "PGM";

    fp = fopen(filename, "wb");

    fprintf(fp, "%s%c%d %d %d %d\n", fileType, 13, WIDTH, HEIGHT, 255);

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            fprintf(fp, "%d ", image[i][j].b);
            fprintf(fp, "%d ", image[i][j].g);
            fprintf(fp, "%d\n", image[i][j].r);
        }
    }

    fclose(fp);
}

int main() {
    createImage();
    clearImage();

    drawRect(10, 10, 10, 10, palette[3]);
    drawRect(20, 20, 10, 10, palette[5]);
    drawRect(30, 30, 10, 10, palette[7]);

    saveImage("output.pgm");

    clearImage();
    free(image);

    return 0;
}