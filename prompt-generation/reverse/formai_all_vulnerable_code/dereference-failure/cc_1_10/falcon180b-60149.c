//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_PIXELS 1000
#define MIN_PIXEL_SIZE 1
#define MAX_PIXEL_SIZE 10
#define BG_COLOR 0x000000
#define PIXEL_COLOR 0xffffff

int main() {
    srand(time(NULL));
    int width = WIDTH;
    int height = HEIGHT;
    int num_pixels = rand() % (MAX_PIXELS - MIN_PIXEL_SIZE + 1) + MIN_PIXEL_SIZE;
    int max_pixel_size = rand() % (MAX_PIXEL_SIZE - MIN_PIXEL_SIZE + 1) + MIN_PIXEL_SIZE;
    int **pixels = (int **)malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        pixels[i] = (int *)malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++) {
            pixels[i][j] = BG_COLOR;
        }
    }
    for (int i = 0; i < num_pixels; i++) {
        int x = rand() % width;
        int y = rand() % height;
        int size = rand() % (max_pixel_size - MIN_PIXEL_SIZE + 1) + MIN_PIXEL_SIZE;
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                int distance = sqrt(pow(j - x, 2) + pow(k - y, 2));
                if (distance <= size / 2) {
                    pixels[y + j][x + k] = PIXEL_COLOR;
                }
            }
        }
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", pixels[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < height; i++) {
        free(pixels[i]);
    }
    free(pixels);
    return 0;
}