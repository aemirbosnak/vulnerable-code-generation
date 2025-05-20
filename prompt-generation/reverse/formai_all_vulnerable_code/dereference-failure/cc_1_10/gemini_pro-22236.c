//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: Donald Knuth
/* Donald Knuth's Pixel Art Generator */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Colors */
enum color {
    BLACK,
    WHITE,
    RED,
    GREEN,
    BLUE,
    YELLOW,
    CYAN,
    MAGENTA
};

/* Canvas */
struct canvas {
    int width;
    int height;
    enum color **pixels;
};

/* Function to create a new canvas */
struct canvas *new_canvas(int width, int height) {
    struct canvas *canvas = malloc(sizeof(struct canvas));
    canvas->width = width;
    canvas->height = height;
    canvas->pixels = malloc(sizeof(enum color *) * height);
    for (int i = 0; i < height; i++) {
        canvas->pixels[i] = malloc(sizeof(enum color) * width);
        for (int j = 0; j < width; j++) {
            canvas->pixels[i][j] = BLACK;
        }
    }
    return canvas;
}

/* Function to free a canvas */
void free_canvas(struct canvas *canvas) {
    for (int i = 0; i < canvas->height; i++) {
        free(canvas->pixels[i]);
    }
    free(canvas->pixels);
    free(canvas);
}

/* Function to set a pixel on the canvas */
void set_pixel(struct canvas *canvas, int x, int y, enum color color) {
    if (x >= 0 && x < canvas->width && y >= 0 && y < canvas->height) {
        canvas->pixels[y][x] = color;
    }
}

/* Function to draw a line on the canvas */
void draw_line(struct canvas *canvas, int x1, int y1, int x2, int y2, enum color color) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x2 - x1) > 0 ? 1 : -1;
    int sy = (y2 - y1) > 0 ? 1 : -1;
    int err = dx - dy;
    while (1) {
        set_pixel(canvas, x1, y1, color);
        if (x1 == x2 && y1 == y2) {
            break;
        }
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

/* Function to draw a rectangle on the canvas */
void draw_rectangle(struct canvas *canvas, int x1, int y1, int x2, int y2, enum color color) {
    draw_line(canvas, x1, y1, x1, y2, color);
    draw_line(canvas, x1, y2, x2, y2, color);
    draw_line(canvas, x2, y2, x2, y1, color);
    draw_line(canvas, x2, y1, x1, y1, color);
}

/* Function to draw a circle on the canvas */
void draw_circle(struct canvas *canvas, int x, int y, int radius, enum color color) {
    int f = 1 - radius;
    int ddF_x = 1;
    int ddF_y = -2 * radius;
    int x1 = 0;
    int y1 = radius;
    set_pixel(canvas, x, y + radius, color);
    set_pixel(canvas, x, y - radius, color);
    set_pixel(canvas, x + radius, y, color);
    set_pixel(canvas, x - radius, y, color);
    while (x1 < y1) {
        if (f >= 0) {
            y1--;
            ddF_y += 2;
            f += ddF_y;
        }
        x1++;
        ddF_x += 2;
        f += ddF_x;
        set_pixel(canvas, x + x1, y + y1, color);
        set_pixel(canvas, x - x1, y + y1, color);
        set_pixel(canvas, x + x1, y - y1, color);
        set_pixel(canvas, x - x1, y - y1, color);
        set_pixel(canvas, x + y1, y + x1, color);
        set_pixel(canvas, x - y1, y + x1, color);
        set_pixel(canvas, x + y1, y - x1, color);
        set_pixel(canvas, x - y1, y - x1, color);
    }
}

/* Function to fill a region on the canvas */
void fill_region(struct canvas *canvas, int x, int y, enum color color) {
    if (x >= 0 && x < canvas->width && y >= 0 && y < canvas->height && canvas->pixels[y][x] != color) {
        canvas->pixels[y][x] = color;
        fill_region(canvas, x + 1, y, color);
        fill_region(canvas, x - 1, y, color);
        fill_region(canvas, x, y + 1, color);
        fill_region(canvas, x, y - 1, color);
    }
}

/* Function to save the canvas to a PPM file */
void save_ppm(struct canvas *canvas, char *filename) {
    FILE *file = fopen(filename, "w");
    fprintf(file, "P3\n%d %d\n255\n", canvas->width, canvas->height);
    for (int i = 0; i < canvas->height; i++) {
        for (int j = 0; j < canvas->width; j++) {
            enum color color = canvas->pixels[i][j];
            fprintf(file, "%d %d %d\n", ((color & 0x07) << 5), ((color & 0x38) >> 2), ((color & 0xC0) >> 6));
        }
    }
    fclose(file);
}

/* Main function */
int main() {
    srand(time(NULL));
    struct canvas *canvas = new_canvas(640, 480);
    for (int i = 0; i < 100; i++) {
        int x1 = rand() % canvas->width;
        int y1 = rand() % canvas->height;
        int x2 = rand() % canvas->width;
        int y2 = rand() % canvas->height;
        enum color color = rand() % 8;
        draw_line(canvas, x1, y1, x2, y2, color);
    }
    save_ppm(canvas, "pixel_art.ppm");
    free_canvas(canvas);
    return 0;
}