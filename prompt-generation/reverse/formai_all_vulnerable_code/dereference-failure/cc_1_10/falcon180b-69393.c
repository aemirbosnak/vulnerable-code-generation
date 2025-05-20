//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_COLORS 256

typedef struct {
    int r;
    int g;
    int b;
} Color;

int main() {
    srand(time(NULL));

    int screen[HEIGHT][WIDTH];
    memset(screen, 0, sizeof(screen));

    Color* palette = malloc(MAX_COLORS * sizeof(Color));
    for (int i = 0; i < MAX_COLORS; i++) {
        palette[i].r = rand() % 256;
        palette[i].g = rand() % 256;
        palette[i].b = rand() % 256;
    }

    int num_colors = 0;

    while (num_colors < MAX_COLORS) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;

        if (screen[y][x] == 0) {
            screen[y][x] = num_colors;
            num_colors++;
        }
    }

    for (int i = 0; i < num_colors; i++) {
        int count = 0;
        while (count < 10) {
            int x = rand() % WIDTH;
            int y = rand() % HEIGHT;

            if (screen[y][x] == i) {
                count++;
            }
        }
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int color_index = screen[y][x];
            Color color = palette[color_index];

            printf("%d ", color.r);
            printf("%d ", color.g);
            printf("%d ", color.b);
        }
        printf("\n");
    }

    free(palette);

    return 0;
}