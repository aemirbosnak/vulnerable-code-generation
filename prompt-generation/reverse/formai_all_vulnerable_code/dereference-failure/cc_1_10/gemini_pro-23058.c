//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define WIDTH 64
#define HEIGHT 64

typedef struct {
    uint8_t r, g, b, a;
} color_t;

color_t palette[] = {
    { 0x00, 0x00, 0x00, 0xff },
    { 0xff, 0xff, 0xff, 0xff },
    { 0x00, 0xff, 0x00, 0xff },
    { 0xff, 0x00, 0x00, 0xff },
    { 0x00, 0x00, 0xff, 0xff },
    { 0xff, 0xff, 0x00, 0xff },
    { 0x00, 0xff, 0xff, 0xff },
    { 0xff, 0x00, 0xff, 0xff },
};

void draw_pixel(uint8_t *pixels, int x, int y, color_t color) {
    pixels[y * WIDTH + x] = color.r;
    pixels[y * WIDTH + x + 1] = color.g;
    pixels[y * WIDTH + x + 2] = color.b;
    pixels[y * WIDTH + x + 3] = color.a;
}

void render_mandelbrot(uint8_t *pixels) {
    double x0 = -2.0;
    double x1 = 1.0;
    double y0 = -1.5;
    double y1 = 1.5;

    double scale_x = (x1 - x0) / WIDTH;
    double scale_y = (y1 - y0) / HEIGHT;

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double cx = x0 + x * scale_x;
            double cy = y0 + y * scale_y;

            double zx = 0.0;
            double zy = 0.0;

            int iteration = 0;
            while (zx * zx + zy * zy < 4.0 && iteration < 255) {
                double tmp = zx * zx - zy * zy + cx;
                zy = 2.0 * zx * zy + cy;
                zx = tmp;

                iteration++;
            }

            if (iteration == 255) {
                draw_pixel(pixels, x, y, palette[0]);
            } else {
                draw_pixel(pixels, x, y, palette[iteration % 8]);
            }
        }
    }
}

int main(int argc, char **argv) {
    uint8_t *pixels = malloc(WIDTH * HEIGHT * 4);

    render_mandelbrot(pixels);

    FILE *fp = fopen("mandelbrot.ppm", "wb");
    fprintf(fp, "P3\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(pixels, 1, WIDTH * HEIGHT * 4, fp);
    fclose(fp);

    free(pixels);

    return 0;
}