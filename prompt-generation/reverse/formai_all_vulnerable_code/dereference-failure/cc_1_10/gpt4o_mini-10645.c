//GPT-4o-mini DATASET v1.0 Category: Pixel Art Generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 40
#define MAX_HEIGHT 20

typedef struct {
    char symbol;
    int r, g, b;  // RGB values
} Pixel;

Pixel palette[] = {
    {' ', 255, 255, 255}, // White
    {'#', 255, 0, 0},     // Red
    {'@', 0, 255, 0},     // Green
    {'$', 0, 0, 255},     // Blue
    {'%', 255, 255, 0},   // Yellow
    {'&', 255, 0, 255},   // Magenta
    {'*', 0, 255, 255}    // Cyan
};

int randomColorIndex() {
    return rand() % (sizeof(palette) / sizeof(palette[0]));
}

void generatePixelArt(int width, int height) {
    Pixel canvas[MAX_HEIGHT][MAX_WIDTH];

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int colorIndex = randomColorIndex();
            canvas[y][x].symbol = palette[colorIndex].symbol;
            canvas[y][x].r = palette[colorIndex].r;
            canvas[y][x].g = palette[colorIndex].g;
            canvas[y][x].b = palette[colorIndex].b;
        }
    }

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            printf("%c", canvas[y][x].symbol);
        }
        printf("\n");
    }
}

void displayColorInfo(int width, int height) {
    printf("Pixel Art Color Info:\n");
    for(int i = 0; i < sizeof(palette) / sizeof(palette[0]); ++i) {
        printf("Symbol: %c, RGB(%d, %d, %d)\n", palette[i].symbol, palette[i].r, palette[i].g, palette[i].b);
    }
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    int width = MAX_WIDTH, height = MAX_HEIGHT;

    if (argc > 2) {
        width = atoi(argv[1]);
        height = atoi(argv[2]);
    } else if (argc > 1) {
        width = atoi(argv[1]);
    }

    if (width > MAX_WIDTH) width = MAX_WIDTH;
    if (height > MAX_HEIGHT) height = MAX_HEIGHT;

    printf("Generating Pixel Art (%d x %d):\n", width, height);
    generatePixelArt(width, height);
    
    displayColorInfo(width, height);

    return 0;
}