//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 50
#define MAX_COLORS 256

typedef struct {
    int r;
    int g;
    int b;
} Color;

int main() {
    srand(time(0));

    Color *palette = (Color *)malloc(MAX_COLORS * sizeof(Color));
    int num_colors = 0;

    for (int i = 0; i < MAX_COLORS; i++) {
        palette[i].r = rand() % 256;
        palette[i].g = rand() % 256;
        palette[i].b = rand() % 256;
        num_colors++;
    }

    printf("Generated %d colors:\n", num_colors);
    for (int i = 0; i < num_colors; i++) {
        printf("Color %d: (%d, %d, %d)\n", i, palette[i].r, palette[i].g, palette[i].b);
    }

    int image[HEIGHT][WIDTH];
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            image[y][x] = rand() % num_colors;
        }
    }

    printf("\nPixel art:\n");
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("  ");
            for (int k = 0; k < 8; k++) {
                if (image[y][x] & (1 << k)) {
                    printf("█");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    free(palette);
    return 0;
}