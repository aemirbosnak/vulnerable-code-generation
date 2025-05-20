//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 800
#define MAX_HEIGHT 600
#define MAX_COLORS 256

typedef struct {
    int x, y;
    int r, g, b;
} Pixel;

int main(int argc, char *argv[]) {
    srand(time(NULL));

    int width = rand() % MAX_WIDTH + 1;
    int height = rand() % MAX_HEIGHT + 1;

    Pixel *image = malloc(sizeof(Pixel) * width * height);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int r = rand() % MAX_COLORS;
            int g = rand() % MAX_COLORS;
            int b = rand() % MAX_COLORS;

            image[y * width + x].x = x;
            image[y * width + x].y = y;
            image[y * width + x].r = r;
            image[y * width + x].g = g;
            image[y * width + x].b = b;
        }
    }

    printf("P6\n%d %d\n%d\n", width, height, MAX_COLORS);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            Pixel pixel = image[y * width + x];

            printf("%d %d %d ", pixel.r, pixel.g, pixel.b);
        }
        printf("\n");
    }

    free(image);

    return 0;
}