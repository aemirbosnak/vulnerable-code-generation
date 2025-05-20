//Falcon2-11B DATASET v1.0 Category: Pixel Art Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXEL_SIZE 50
#define MIN_PIXEL_SIZE 5
#define PIXEL_SIZE_INCREMENT 10

typedef struct {
    int x;
    int y;
    char color;
} pixel_t;

pixel_t generate_pixel(int x, int y, char color) {
    pixel_t p;
    p.x = x;
    p.y = y;
    p.color = color;
    return p;
}

void draw_pixel(pixel_t p) {
    printf("%c %d %d\n", p.color, p.x, p.y);
}

void draw_pixel_grid(pixel_t *pixels, int num_pixels) {
    int x = 0;
    int y = 0;
    for (int i = 0; i < num_pixels; i++) {
        if (x < MAX_PIXEL_SIZE && y < MAX_PIXEL_SIZE) {
            draw_pixel(pixels[i]);
            x += PIXEL_SIZE_INCREMENT;
            y += PIXEL_SIZE_INCREMENT;
        } else if (x > 0 && y > 0) {
            x -= PIXEL_SIZE_INCREMENT;
            y -= PIXEL_SIZE_INCREMENT;
        } else {
            break;
        }
    }
}

int main() {
    pixel_t *pixels = malloc(sizeof(pixel_t) * MAX_PIXEL_SIZE * MAX_PIXEL_SIZE);
    for (int i = 0; i < MAX_PIXEL_SIZE * MAX_PIXEL_SIZE; i++) {
        pixels[i] = generate_pixel(i % MAX_PIXEL_SIZE, i / MAX_PIXEL_SIZE, 'x');
    }
    draw_pixel_grid(pixels, MAX_PIXEL_SIZE * MAX_PIXEL_SIZE);
    free(pixels);
    return 0;
}