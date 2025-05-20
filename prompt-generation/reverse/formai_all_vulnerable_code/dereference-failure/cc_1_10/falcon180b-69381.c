//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_POINTS 1000
#define MAX_COLORS 256

typedef struct {
    int x, y;
    int r, g, b;
} Point;

int main() {
    srand(time(NULL));

    int points[MAX_POINTS];
    int num_points = 0;
    Point *pixels = malloc(WIDTH * HEIGHT * sizeof(Point));

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            pixels[i * HEIGHT + j].x = i;
            pixels[i * HEIGHT + j].y = j;
            pixels[i * HEIGHT + j].r = rand() % 256;
            pixels[i * HEIGHT + j].g = rand() % 256;
            pixels[i * HEIGHT + j].b = rand() % 256;
        }
    }

    int last_x = -1, last_y = -1;
    int current_x, current_y;

    while (num_points < MAX_POINTS) {
        current_x = rand() % WIDTH;
        current_y = rand() % HEIGHT;

        if (last_x!= -1 && last_y!= -1) {
            double dx = current_x - last_x;
            double dy = current_y - last_y;
            double distance = sqrt(dx * dx + dy * dy);

            if (distance < 10) {
                continue;
            }
        }

        last_x = current_x;
        last_y = current_y;

        points[num_points++] = current_x * HEIGHT + current_y;
    }

    for (int i = 0; i < num_points; i++) {
        int index = points[i] / HEIGHT * WIDTH + points[i] % HEIGHT;

        pixels[index].r = 0;
        pixels[index].g = 0;
        pixels[index].b = 0;
    }

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            printf("%d %d %d\n", pixels[i * HEIGHT + j].r, pixels[i * HEIGHT + j].g, pixels[i * HEIGHT + j].b);
        }
    }

    free(pixels);

    return 0;
}