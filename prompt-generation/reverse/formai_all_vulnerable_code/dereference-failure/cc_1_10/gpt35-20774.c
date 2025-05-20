//FormAI DATASET v1.0 Category: Image Editor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRID_SIZE 10

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int rows, cols;
    Pixel **pixels;
} Image;

Image createImage(int rows, int cols) {
    Image img;
    img.rows = rows;
    img.cols = cols;
    img.pixels = malloc(rows * sizeof(Pixel *));
    for (int i = 0; i < rows; ++i) {
        img.pixels[i] = malloc(cols * sizeof(Pixel));
    }
    return img;
}

void destroyImage(Image img) {
    for (int i = 0; i < img.rows; ++i) {
        free(img.pixels[i]);
    }
    free(img.pixels);
}

void setPixel(Image img, int row, int col, unsigned char r, unsigned char g, unsigned char b) {
    img.pixels[row][col].r = r;
    img.pixels[row][col].g = g;
    img.pixels[row][col].b = b;
}

void clear(Image img, unsigned char r, unsigned char g, unsigned char b) {
    for (int row = 0; row < img.rows; ++row) {
        for (int col = 0; col < img.cols; ++col) {
            setPixel(img, row, col, r, g, b);
        }
    }
}

void drawLine(Image img, int row1, int col1, int row2, int col2, unsigned char r, unsigned char g, unsigned char b) {
    int dx = abs(col2 - col1);
    int dy = abs(row2 - row1);
    int sx = col1 < col2 ? 1 : -1;
    int sy = row1 < row2 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;
    while (1) {
        setPixel(img, row1, col1, r, g, b);
        if (row1 == row2 && col1 == col2) break;
        e2 = err;
        if (e2 > -dx) {
            err -= dy;
            col1 += sx;
        }
        if (e2 < dy) {
            err += dx;
            row1 += sy;
        }
    }
}

int main() {
    Image img = createImage(GRID_SIZE, GRID_SIZE);
    clear(img, 0, 0, 0);
    drawLine(img, 0, 0, GRID_SIZE - 1, GRID_SIZE - 1, 255, 0, 0);
    drawLine(img, GRID_SIZE - 1, 0, 0, GRID_SIZE - 1, 0, 255, 0);
    for (int row = 0; row < img.rows; ++row) {
        for (int col = 0; col < img.cols; ++col) {
            printf("%02x%02x%02x ", img.pixels[row][col].r, img.pixels[row][col].g, img.pixels[row][col].b);
        }
        printf("\n");
    }
    destroyImage(img);
    return 0;
}