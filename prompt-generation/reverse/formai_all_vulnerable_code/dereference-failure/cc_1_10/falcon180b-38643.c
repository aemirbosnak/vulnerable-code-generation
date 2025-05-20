//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PIXELS 1000
#define MAX_COLORS 256

typedef struct {
    int x;
    int y;
    int color;
} pixel_t;

pixel_t *generate_pixels(int num_pixels, int max_x, int max_y) {
    pixel_t *pixels = malloc(num_pixels * sizeof(pixel_t));
    for (int i = 0; i < num_pixels; i++) {
        pixels[i].x = rand() % max_x;
        pixels[i].y = rand() % max_y;
        pixels[i].color = rand() % MAX_COLORS;
    }
    return pixels;
}

void draw_pixel(pixel_t pixel, int *canvas, int canvas_width, int canvas_height) {
    int x = pixel.x;
    int y = pixel.y;
    int color = pixel.color;
    if (x >= 0 && x < canvas_width && y >= 0 && y < canvas_height) {
        int index = y * canvas_width + x;
        canvas[index] = color;
    }
}

void draw_pixels(pixel_t *pixels, int num_pixels, int *canvas, int canvas_width, int canvas_height) {
    for (int i = 0; i < num_pixels; i++) {
        draw_pixel(pixels[i], canvas, canvas_width, canvas_height);
    }
}

void save_canvas_to_file(int *canvas, int canvas_width, int canvas_height, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    fwrite(canvas, canvas_width * canvas_height, sizeof(int), file);
    fclose(file);
}

int main() {
    int num_pixels = 100;
    int max_x = 800;
    int max_y = 600;
    int canvas_width = max_x * 2;
    int canvas_height = max_y * 2;
    int *canvas = malloc(canvas_width * canvas_height * sizeof(int));
    memset(canvas, 0, canvas_width * canvas_height * sizeof(int));

    pixel_t *pixels = generate_pixels(num_pixels, max_x, max_y);
    draw_pixels(pixels, num_pixels, canvas, canvas_width, canvas_height);

    save_canvas_to_file(canvas, canvas_width, canvas_height, "canvas.bin");

    free(pixels);
    free(canvas);

    return 0;
}