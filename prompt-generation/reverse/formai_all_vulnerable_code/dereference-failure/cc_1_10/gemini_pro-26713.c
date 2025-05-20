//GEMINI-pro DATASET v1.0 Category: Educational ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// A palette of colors to paint with
typedef enum {
    BLACK,
    WHITE,
    RED,
    GREEN,
    BLUE,
    YELLOW,
    MAGENTA,
    CYAN
} Color;

// A canvas to paint on
typedef struct {
    int width;
    int height;
    Color** pixels;
} Canvas;

// Create a new canvas
Canvas* new_canvas(int width, int height) {
    Canvas* canvas = malloc(sizeof(Canvas));
    canvas->width = width;
    canvas->height = height;
    canvas->pixels = malloc(sizeof(Color*) * height);
    for (int y = 0; y < height; y++) {
        canvas->pixels[y] = malloc(sizeof(Color) * width);
    }
    return canvas;
}

// Free the memory allocated for a canvas
void free_canvas(Canvas* canvas) {
    for (int y = 0; y < canvas->height; y++) {
        free(canvas->pixels[y]);
    }
    free(canvas->pixels);
    free(canvas);
}

// Set the color of a pixel on the canvas
void set_pixel(Canvas* canvas, int x, int y, Color color) {
    if (x >= 0 && x < canvas->width && y >= 0 && y < canvas->height) {
        canvas->pixels[y][x] = color;
    }
}

// Get the color of a pixel on the canvas
Color get_pixel(Canvas* canvas, int x, int y) {
    if (x >= 0 && x < canvas->width && y >= 0 && y < canvas->height) {
        return canvas->pixels[y][x];
    }
    return BLACK;
}

// Draw a line on the canvas
void draw_line(Canvas* canvas, int x0, int y0, int x1, int y1, Color color) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = (dx>dy ? dx : -dy)/2, e2;

    for(;;){
        set_pixel(canvas, x0,y0,color);
        if (x0==x1 && y0==y1) break;
        e2 = err;
        if (e2 >-dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }
    }
}

// Draw a circle on the canvas
void draw_circle(Canvas* canvas, int x0, int y0, int radius, Color color) {
    int x = radius, y = 0;
    int err = 0;

    while (x >= y) {
        set_pixel(canvas, x0 + x, y0 + y, color);
        set_pixel(canvas, x0 - x, y0 + y, color);
        set_pixel(canvas, x0 + x, y0 - y, color);
        set_pixel(canvas, x0 - x, y0 - y, color);
        set_pixel(canvas, x0 + y, y0 + x, color);
        set_pixel(canvas, x0 - y, y0 + x, color);
        set_pixel(canvas, x0 + y, y0 - x, color);
        set_pixel(canvas, x0 - y, y0 - x, color);

        y++;
        err += 1 + 2*y;
        if (2*(err - x + 1) < 0) {
            x--;
            err += 2*x + 1;
        }
    }
}

// Draw a filled rectangle on the canvas
void draw_filled_rectangle(Canvas* canvas, int x0, int y0, int width, int height, Color color) {
    for (int y = y0; y < y0 + height; y++) {
        for (int x = x0; x < x0 + width; x++) {
            set_pixel(canvas, x, y, color);
        }
    }
}

// Draw a filled circle on the canvas
void draw_filled_circle(Canvas* canvas, int x0, int y0, int radius, Color color) {
    for (int y = -radius; y <= radius; y++) {
        for (int x = -radius; x <= radius; x++) {
            if (x*x + y*y <= radius*radius) {
                set_pixel(canvas, x0 + x, y0 + y, color);
            }
        }
    }
}

// Save the canvas to a PPM file
void save_canvas(Canvas* canvas, const char* filename) {
    FILE* file = fopen(filename, "w");
    fprintf(file, "P3\n");
    fprintf(file, "%d %d\n", canvas->width, canvas->height);
    fprintf(file, "255\n");
    for (int y = 0; y < canvas->height; y++) {
        for (int x = 0; x < canvas->width; x++) {
            Color color = get_pixel(canvas, x, y);
            fprintf(file, "%d %d %d ", color, color, color);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

// Main function
int main() {
    // Create a new canvas
    Canvas* canvas = new_canvas(500, 500);

    // Draw a masterpiece
    draw_filled_rectangle(canvas, 0, 0, 500, 500, WHITE);
    draw_filled_circle(canvas, 250, 250, 100, RED);
    draw_filled_circle(canvas, 250, 250, 75, GREEN);
    draw_filled_circle(canvas, 250, 250, 50, BLUE);
    draw_line(canvas, 250, 50, 250, 450, BLACK);
    draw_line(canvas, 50, 250, 450, 250, BLACK);

    // Save the canvas to a file
    save_canvas(canvas, "masterpiece.ppm");

    // Free the memory allocated for the canvas
    free_canvas(canvas);

    return 0;
}