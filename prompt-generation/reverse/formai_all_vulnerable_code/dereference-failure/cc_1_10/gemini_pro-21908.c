//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    char **data;
} PixelArt;

PixelArt *create_pixel_art(int width, int height) {
    PixelArt *art = malloc(sizeof(PixelArt));
    art->width = width;
    art->height = height;
    art->data = malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++) {
        art->data[i] = malloc(sizeof(char) * width);
        memset(art->data[i], ' ', width);
    }
    return art;
}

void destroy_pixel_art(PixelArt *art) {
    for (int i = 0; i < art->height; i++) {
        free(art->data[i]);
    }
    free(art->data);
    free(art);
}

void set_pixel(PixelArt *art, int x, int y, char c) {
    if (x >= 0 && x < art->width && y >= 0 && y < art->height) {
        art->data[y][x] = c;
    }
}

char get_pixel(PixelArt *art, int x, int y) {
    if (x >= 0 && x < art->width && y >= 0 && y < art->height) {
        return art->data[y][x];
    } else {
        return ' ';
    }
}

void print_pixel_art(PixelArt *art) {
    for (int i = 0; i < art->height; i++) {
        printf("%s\n", art->data[i]);
    }
}

int main() {
    // Create a new pixel art canvas with a width of 80 and a height of 25
    PixelArt *art = create_pixel_art(80, 25);

    // Draw a rectangle in the center of the canvas
    for (int i = 20; i < 60; i++) {
        for (int j = 10; j < 15; j++) {
            set_pixel(art, i, j, '#');
        }
    }

    // Draw a triangle in the top-left corner of the canvas
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < i + 1; j++) {
            set_pixel(art, i, j, '*');
        }
    }

    // Draw a circle in the bottom-right corner of the canvas
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if ((i - 5) * (i - 5) + (j - 5) * (j - 5) <= 25) {
                set_pixel(art, 70 + i, 20 + j, 'o');
            }
        }
    }

    // Print the pixel art to the console
    print_pixel_art(art);

    // Destroy the pixel art canvas
    destroy_pixel_art(art);

    return 0;
}