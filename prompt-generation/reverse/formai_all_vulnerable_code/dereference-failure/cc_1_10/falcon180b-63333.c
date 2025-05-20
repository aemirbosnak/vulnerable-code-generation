//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 50
#define CHAR_WIDTH 8
#define CHAR_HEIGHT 12
#define NUM_COLORS 7

// Define color palette
const char* colors[] = {"\033[0;31m","\033[0;32m","\033[0;33m","\033[0;34m","\033[0;35m","\033[0;36m","\033[0m"};

void print_pixel(int x, int y, int color) {
    int index = (y * WIDTH) + x;
    printf(colors[color]);
    printf("\033[H");
    for (int i = 0; i < y; i++) {
        printf("\033[%dA\033[2K", i * CHAR_HEIGHT);
    }
    printf("\033[%d;%dH", y * CHAR_HEIGHT + (x * CHAR_WIDTH), color);
    fflush(stdout);
}

void generate_art(int seed) {
    srand(seed);

    int num_pixels = WIDTH * HEIGHT;
    int* pixels = malloc(num_pixels * sizeof(int));

    for (int i = 0; i < num_pixels; i++) {
        pixels[i] = rand() % NUM_COLORS;
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int index = (y * WIDTH) + x;
            int color = pixels[index];
            print_pixel(x, y, color);
        }
    }

    free(pixels);
}

int main() {
    int seed;

    printf("Enter a seed for the random number generator: ");
    scanf("%d", &seed);

    printf("\033[2J"); // Clear console

    generate_art(seed);

    return 0;
}