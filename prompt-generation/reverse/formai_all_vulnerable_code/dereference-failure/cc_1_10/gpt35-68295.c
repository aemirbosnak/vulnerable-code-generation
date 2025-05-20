//FormAI DATASET v1.0 Category: Image Editor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void drawRectangle(char **pixels, int x, int y, int width, int height, char color) {
    for(int i = y; i < y+height; i++) {
        for(int j = x; j < x+width; j++) {
            pixels[i][j] = color;
        }
    }
}

void drawLine(char **pixels, int startX, int startY, int endX, int endY, char color) {
    int dx = abs(endX - startX);
    int dy = abs(endY - startY);

    int sx = (startX < endX) ? 1 : -1;
    int sy = (startY < endY) ? 1 : -1;

    int err = dx - dy;
    int x = startX;
    int y = startY;

    while(1) {
        pixels[y][x] = color;
        if(x == endX && y == endY) break;

        int e2 = 2*err;
        if(e2 > -dy) {
            err -= dy;
            x += sx;
        }
        if(e2 < dx) {
            err += dx;
            y += sy;
        }
    }
}

void saveImage(char **pixels, int width, int height, char* filename) {
    FILE *f = fopen(filename, "w");

    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(f, "P3\n%d %d\n255\n", width, height);

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            fprintf(f, "%d %d %d ", pixels[i][j], pixels[i][j], pixels[i][j]);
        }
        fprintf(f, "\n");
    }

    fclose(f);
}

int main() {
    int width = 800;
    int height = 600;

    char **pixels = (char **)malloc(sizeof(char *) * height);
    for(int i = 0; i < height; i++)
        pixels[i] = (char *)calloc(sizeof(char), width);

    drawRectangle(pixels, 200, 100, 400, 400, 255);

    drawLine(pixels, 100, 50, 500, 50, 255);
    drawLine(pixels, 500, 50, 500, 550, 255);
    drawLine(pixels, 500, 550, 100, 550, 255);
    drawLine(pixels, 100, 550, 100, 50, 255);

    saveImage(pixels, width, height, "output.ppm");

    return 0;
}