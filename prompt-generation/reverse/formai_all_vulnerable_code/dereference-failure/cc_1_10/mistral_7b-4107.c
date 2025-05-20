//MISTRAL-7B DATASET v1.0 Category: Pixel Art Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 50
#define HEIGHT 50
#define COLORS 6

typedef struct {
    int r;
    int g;
    int b;
} Color;

Color palette[COLORS] = {
    {255, 0, 0},  // Red
    {0, 255, 0},  // Green
    {0, 0, 255},  // Blue
    {128, 128, 128}, // Gray
    {255, 255, 255}, // White
    {0, 0, 0}       // Black
};

void print_pixel_art(int width, int height, Color** pixels) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Color pixel = pixels[y][x];
            printf("%d %d %d ", pixel.r, pixel.g, pixel.b);
        }
        printf("\n");
    }
}

void generate_checkerboard(Color** pixels) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if ((x + y) % 2 == 0) {
                pixels[y][x] = palette[0];
            } else {
                pixels[y][x] = palette[1];
            }
        }
    }
}

void generate_stripes(Color** pixels) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x % 2 == 0) {
                pixels[y][x] = palette[2];
            } else {
                pixels[y][x] = palette[3];
            }
        }
    }
}

void generate_random(Color** pixels) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            pixels[y][x] = palette[rand() % COLORS];
        }
    }
}

int main() {
    Color** pixels = malloc(HEIGHT * sizeof(Color*));
    for (int i = 0; i < HEIGHT; i++) {
        pixels[i] = malloc(WIDTH * sizeof(Color));
    }

    int choice;
    printf("Choose a pattern: \n1. Checkerboard\n2. Stripes\n3. Random\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            generate_checkerboard(pixels);
            break;
        case 2:
            generate_stripes(pixels);
            break;
        case 3:
            generate_random(pixels);
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    print_pixel_art(WIDTH, HEIGHT, pixels);

    for (int i = 0; i < HEIGHT; i++) {
        free(pixels[i]);
    }
    free(pixels);

    return 0;
}