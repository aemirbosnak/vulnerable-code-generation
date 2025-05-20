//MISTRAL-7B DATASET v1.0 Category: Pixel Art Generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 20
#define MAX_COLOR 3

typedef struct {
    int x, y;
} point;

typedef struct {
    int color[MAX_COLOR];
} palette;

void init_palette(palette* pal) {
    pal->color[0] = 7; // red
    pal->color[1] = 4; // blue
    pal->color[2] = 1; // green
}

void randomize_colors(palette* pal) {
    int i, j, temp;

    for (i = 0; i < MAX_COLOR - 1; i++) {
        j = rand() % (MAX_COLOR - i) + i;
        temp = pal->color[i];
        pal->color[i] = pal->color[j];
        pal->color[j] = temp;
    }
}

void generate_pixel(int** image, int x, int y, palette pal) {
    int i;

    image[y][x] = pal.color[rand() % MAX_COLOR];

    for (i = 0; i < 5; i++) {
        int dx = rand() % 2 ? 1 : -1;
        int dy = rand() % 2 ? 1 : -1;

        if (x + dx >= 0 && x + dx < WIDTH && y + dy >= 0 && y + dy < HEIGHT) {
            generate_pixel(image, x + dx, y + dy, pal);
        }
    }
}

int main() {
    int i, j;
    int** image;
    palette pal;

    init_palette(&pal);

    srand(time(NULL));
    randomize_colors(&pal);

    image = calloc(HEIGHT, sizeof(int*) );
    for (i = 0; i < HEIGHT; i++) {
        image[i] = calloc(WIDTH, sizeof(int) );
    }

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                image[i][j] = pal.color[0];
                continue;
            }

            generate_pixel(image, j, i, pal);
        }
    }

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            putchar(image[i][j] + 48);
        }
        putchar('\n');
    }

    for (i = 0; i < HEIGHT; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}