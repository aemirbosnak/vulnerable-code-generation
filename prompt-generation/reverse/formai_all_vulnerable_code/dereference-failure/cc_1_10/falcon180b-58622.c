//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_COLOR 256
#define MAX_ITER 1000

int x, y, iter;
int color, bg_color;
int *pixels;

void init_pixels() {
    pixels = (int*)malloc(WIDTH * HEIGHT * sizeof(int));
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        pixels[i] = rand() % MAX_COLOR;
    }
}

void generate_art() {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        x = rand() % WIDTH;
        y = rand() % HEIGHT;
        iter = 0;
        while (iter < MAX_ITER) {
            iter++;
            color = (int)pow(iter, 2) % MAX_COLOR;
            if (color > 0) {
                pixels[i] = color;
                break;
            }
        }
    }
}

void print_art() {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        printf("%d ", pixels[i]);
    }
}

int main() {
    srand(time(NULL));
    init_pixels();
    generate_art();
    print_art();
    return 0;
}