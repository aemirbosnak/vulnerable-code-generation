//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define WIDTH 3
#define HEIGHT 3
#define MAX_CHAR 94
#define ASCII_ART_WIDTH (WIDTH * 3)
#define ASCII_ART_HEIGHT (HEIGHT * 3)

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} RGB;

RGB read_pixel(const unsigned char *image, int x, int y) {
    RGB pixel;
    int pos = 3 * (y * WIDTH + x);
    pixel.r = image[pos];
    pixel.g = image[pos + 1];
    pixel.b = image[pos + 2];
    return pixel;
}

void print_ascii_char(int ascii_code, int value) {
    if (value > 0) {
        putchar((ascii_code + value >= 32 && ascii_code + value <= 126) ? (ascii_code + value) : '?');
    } else {
        putchar(' ');
    }
}

void print_ascii_row(const char *ascii_art, int value) {
    for (int i = 0; i < ASCII_ART_WIDTH; ++i) {
        print_ascii_char(ascii_art[i], value);
    }
    putchar('\n');
}

void convert_image_to_ascii_art(const unsigned char *image) {
    const char *ascii_art = "  /|\\  ";
    RGB pixel;
    int row, col;

    for (row = 0; row < HEIGHT; ++row) {
        for (col = 0; col < WIDTH; ++col) {
            pixel = read_pixel(image, col, row);
            int intensity = (pixel.r + pixel.g + pixel.b) / 3;
            int ascii_code = 48 + (intensity * (MAX_CHAR - 48) / 255);
            print_ascii_row(ascii_art, ascii_code - 48);
        }
    }
}

int main() {
    unsigned char image[WIDTH * HEIGHT * 3] = {
        255, 255, 255,  // White background
        64, 64, 64,      // Black pixel at (0,0)
        128, 128, 128   // Gray pixel at (1,1)
    };

    convert_image_to_ascii_art(image);

    return 0;
}