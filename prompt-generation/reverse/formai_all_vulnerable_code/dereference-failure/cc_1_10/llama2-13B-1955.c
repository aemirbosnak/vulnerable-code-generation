//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 480
#define MAX_COLORS 256

typedef struct {
    int x, y;
    int color;
} Pixel;

typedef struct {
    Pixel pixels[WIDTH * HEIGHT];
} Image;

void init_image(Image *image) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            image->pixels[i * HEIGHT + j].x = i;
            image->pixels[i * HEIGHT + j].y = j;
            image->pixels[i * HEIGHT + j].color = rand() % MAX_COLORS;
        }
    }
}

void draw_line(Image *image, int x1, int y1, int x2, int y2) {
    int i, j;
    for (i = x1; i <= x2; i++) {
        for (j = y1; j <= y2; j++) {
            image->pixels[i * HEIGHT + j].color = image->pixels[i * HEIGHT + j].color | (image->pixels[i * HEIGHT + j].color << 1);
        }
    }
}

void draw_rectangle(Image *image, int x, int y, int width, int height) {
    int i, j;
    for (i = x; i < x + width; i++) {
        for (j = y; j < y + height; j++) {
            image->pixels[i * HEIGHT + j].color = image->pixels[i * HEIGHT + j].color | (image->pixels[i * HEIGHT + j].color << 1);
        }
    }
}

void draw_circle(Image *image, int x, int y, int radius) {
    int i, j;
    for (i = x - radius; i <= x + radius; i++) {
        for (j = y - radius; j <= y + radius; j++) {
            if (sqrt((i * i) + (j * j)) <= radius) {
                image->pixels[i * HEIGHT + j].color = image->pixels[i * HEIGHT + j].color | (image->pixels[i * HEIGHT + j].color << 1);
            }
        }
    }
}

void draw_text(Image *image, char *text, int x, int y) {
    int i, j;
    for (i = 0; text[i] != '\0'; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (text[i] == 'A' || text[i] == 'a') {
                image->pixels[x * HEIGHT + j].color = image->pixels[x * HEIGHT + j].color | (image->pixels[x * HEIGHT + j].color << 1);
            } else if (text[i] == 'B' || text[i] == 'b') {
                image->pixels[x * HEIGHT + j].color = image->pixels[x * HEIGHT + j].color | (image->pixels[x * HEIGHT + j].color << 2);
            } else if (text[i] == 'C' || text[i] == 'c') {
                image->pixels[x * HEIGHT + j].color = image->pixels[x * HEIGHT + j].color | (image->pixels[x * HEIGHT + j].color << 3);
            }
        }
        x++;
    }
}

void display_image(Image *image) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            printf("%d", image->pixels[i * HEIGHT + j].color);
        }
        printf("\n");
    }
}

int main() {
    Image *image = malloc(sizeof(Image));
    init_image(image);

    draw_line(image, 0, 0, WIDTH, HEIGHT);
    draw_rectangle(image, 100, 100, 200, 100);
    draw_circle(image, 250, 250, 100);
    draw_text(image, "Hello, world!", 300, 300);

    display_image(image);

    return 0;
}