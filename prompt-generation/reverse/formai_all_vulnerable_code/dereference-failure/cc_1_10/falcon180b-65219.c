//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define MAX_PIXELS (WIDTH * HEIGHT)

typedef struct {
    int x;
    int y;
    int color;
} pixel_t;

typedef struct {
    int width;
    int height;
    pixel_t *pixels;
} image_t;

void init_image(image_t *image) {
    image->width = WIDTH;
    image->height = HEIGHT;
    image->pixels = malloc(MAX_PIXELS * sizeof(pixel_t));
    for (int i = 0; i < MAX_PIXELS; i++) {
        image->pixels[i].x = rand() % WIDTH;
        image->pixels[i].y = rand() % HEIGHT;
        image->pixels[i].color = rand() % 7 + 1;
    }
}

void draw_pixel(image_t *image, int x, int y, int color) {
    for (int i = 0; i < MAX_PIXELS; i++) {
        if (image->pixels[i].x == x && image->pixels[i].y == y) {
            image->pixels[i].color = color;
            break;
        }
    }
}

void print_image(image_t *image) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            pixel_t pixel = image->pixels[(y * WIDTH) + x];
            printf("%c", pixel.color == 1? '.' : '*');
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    image_t image;
    init_image(&image);

    int x, y, color;
    while (1) {
        printf("Enter x, y, and color (0 to stop): ");
        scanf("%d %d %d", &x, &y, &color);
        if (color == 0) {
            break;
        }
        draw_pixel(&image, x, y, color);
        print_image(&image);
    }

    free(image.pixels);
    return 0;
}