//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    int x;
    int y;
    int size;
    int color;
} Pixel;

typedef struct {
    Pixel pixels[WIDTH * HEIGHT];
} Image;

void initImage(Image *image) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            image->pixels[i * HEIGHT + j].x = i;
            image->pixels[i * HEIGHT + j].y = j;
            image->pixels[i * HEIGHT + j].size = 10;
            image->pixels[i * HEIGHT + j].color = rand() % 256;
        }
    }
}

void drawPixel(Image *image, int x, int y) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (image->pixels[i * HEIGHT + j].x == x && image->pixels[i * HEIGHT + j].y == y) {
                image->pixels[i * HEIGHT + j].size += 10;
                break;
            }
        }
    }
}

void erasePixel(Image *image, int x, int y) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (image->pixels[i * HEIGHT + j].x == x && image->pixels[i * HEIGHT + j].y == y) {
                image->pixels[i * HEIGHT + j].size -= 10;
                if (image->pixels[i * HEIGHT + j].size <= 0) {
                    image->pixels[i * HEIGHT + j].color = 0;
                }
                break;
            }
        }
    }
}

void displayImage(Image *image) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (image->pixels[i * HEIGHT + j].color > 0) {
                printf("   %d, %d, %d ", image->pixels[i * HEIGHT + j].x, image->pixels[i * HEIGHT + j].y, image->pixels[i * HEIGHT + j].size);
            }
        }
        printf("\n");
    }
}

int main() {
    Image *image = malloc(sizeof(Pixel) * WIDTH * HEIGHT);
    initImage(image);

    while (1) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        drawPixel(image, x, y);
        displayImage(image);
        printf("Press Enter to continue...");
        getchar();
    }

    free(image);
    return 0;
}