//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 32
#define HEIGHT 16

// Define color codes
#define BLACK   0
#define WHITE   255

// Define a pixel struct
struct Pixel {
    unsigned char r, g, b, a;
};

// Define a canvas struct
struct Canvas {
    int width, height;
    struct Pixel* pixels;
};

// Create a new canvas
struct Canvas newCanvas(int width, int height) {
    struct Canvas canvas;
    canvas.width = width;
    canvas.height = height;
    canvas.pixels = malloc(width * height * sizeof(struct Pixel));
    return canvas;
}

// Set a pixel color
void setPixelColor(struct Canvas* canvas, int x, int y, unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    int index = y * canvas->width + x;
    canvas->pixels[index].r = r;
    canvas->pixels[index].g = g;
    canvas->pixels[index].b = b;
    canvas->pixels[index].a = a;
}

// Fill the canvas with a color
void fillCanvas(struct Canvas* canvas, unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    int i;
    for (i = 0; i < canvas->width * canvas->height; i++) {
        canvas->pixels[i].r = r;
        canvas->pixels[i].g = g;
        canvas->pixels[i].b = b;
        canvas->pixels[i].a = a;
    }
}

// Draw a pixel art
void drawPixelArt(struct Canvas* canvas) {
    int i, j;
    for (i = 0; i < canvas->height; i++) {
        for (j = 0; j < canvas->width; j++) {
            if (i % 2 == 0 || j % 2 == 0) {
                setPixelColor(canvas, j, i, BLACK, BLACK, BLACK, WHITE);
            }
            else {
                setPixelColor(canvas, j, i, WHITE, WHITE, WHITE, WHITE);
            }
        }
    }
}

// Print the canvas
void printCanvas(struct Canvas* canvas) {
    int i, j;
    for (i = 0; i < canvas->height; i++) {
        for (j = 0; j < canvas->width; j++) {
            int index = i * canvas->width + j;
            printf("(%d, %d, %d, %d) ", canvas->pixels[index].r, canvas->pixels[index].g, canvas->pixels[index].b, canvas->pixels[index].a);
        }
        printf("\n");
    }
}

int main() {
    struct Canvas canvas = newCanvas(WIDTH, HEIGHT);
    fillCanvas(&canvas, 255, 255, 255, 255);
    drawPixelArt(&canvas);
    printCanvas(&canvas);
    free(canvas.pixels);
    return 0;
}