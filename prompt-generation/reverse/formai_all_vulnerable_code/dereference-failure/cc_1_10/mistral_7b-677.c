//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 3
#define HEIGHT 3
#define MAX_COLOR 3

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

void rgb_to_ascii(Pixel color) {
    const char *ascii_chars = ":oXx%@&*()";
    int r = color.r, g = color.g, b = color.b;

    if (r > g && r > b) {
        putchar(ascii_chars[r / 50]);
        putchar(ascii_chars[r % 50 < 30 ? 32 : 48]);
    } else if (g > r && g > b) {
        putchar(ascii_chars[g / 50]);
        putchar(ascii_chars[g % 50 < 30 ? 32 : 48]);
    } else {
        putchar(ascii_chars[b / 50]);
        putchar(ascii_chars[b % 50 < 30 ? 32 : 48]);
    }
}

void print_ascii_image(Pixel image[WIDTH][HEIGHT]) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            rgb_to_ascii(image[j][i]);
            putchar(' ');
        }
        putchar('\n');
    }
}

int main() {
    Pixel image[WIDTH][HEIGHT];

    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            image[j][i].r = i < 2 || j > 0 ? 255 : 0;
            image[j][i].g = j < 2 ? 255 : 0;
            image[j][i].b = i > 0 ? 255 : 0;
        }
    }

    print_ascii_image(image);

    return 0;
}

// Surprised face ASCII art
//  _____
// |    |
// | O.o|
// |    |
// |----|