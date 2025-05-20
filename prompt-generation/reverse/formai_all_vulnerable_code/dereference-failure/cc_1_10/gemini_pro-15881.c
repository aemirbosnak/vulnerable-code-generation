//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the canvas size
#define WIDTH 800
#define HEIGHT 600

// Define the number of colors
#define NUM_COLORS 256

// Define the color palette
const unsigned char palette[NUM_COLORS][3] = {
    {0, 0, 0},       // Black
    {255, 255, 255}, // White
    {255, 0, 0},     // Red
    {0, 255, 0},     // Green
    {0, 0, 255},     // Blue
    {255, 255, 0},   // Yellow
    {0, 255, 255},   // Cyan
    {255, 0, 255}    // Magenta
};

// Define the canvas data structure
struct canvas {
    unsigned char *data;
    int width;
    int height;
};

// Create a new canvas
struct canvas *create_canvas(int width, int height) {
    struct canvas *canvas = malloc(sizeof(struct canvas));
    canvas->data = malloc(width * height * 3);
    canvas->width = width;
    canvas->height = height;
    return canvas;
}

// Free the memory allocated for the canvas
void free_canvas(struct canvas *canvas) {
    free(canvas->data);
    free(canvas);
}

// Set the pixel at the given coordinates to the given color
void set_pixel(struct canvas *canvas, int x, int y, unsigned char color) {
    canvas->data[(y * canvas->width + x) * 3] = palette[color][0];
    canvas->data[(y * canvas->width + x) * 3 + 1] = palette[color][1];
    canvas->data[(y * canvas->width + x) * 3 + 2] = palette[color][2];
}

// Draw a line from the given start coordinates to the given end coordinates
void draw_line(struct canvas *canvas, int x0, int y0, int x1, int y1, unsigned char color) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;

    while (x0 != x1 || y0 != y1) {
        set_pixel(canvas, x0, y0, color);
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

// Draw a circle centered at the given coordinates with the given radius
void draw_circle(struct canvas *canvas, int x0, int y0, int radius, unsigned char color) {
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;

    while (y >= x) {
        set_pixel(canvas, x0 + x, y0 + y, color);
        set_pixel(canvas, x0 - x, y0 + y, color);
        set_pixel(canvas, x0 + x, y0 - y, color);
        set_pixel(canvas, x0 - x, y0 - y, color);
        set_pixel(canvas, x0 + y, y0 + x, color);
        set_pixel(canvas, x0 - y, y0 + x, color);
        set_pixel(canvas, x0 + y, y0 - x, color);
        set_pixel(canvas, x0 - y, y0 - x, color);

        if (d < 0) {
            d += 4 * x + 6;
        } else {
            d += 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

// Draw a filled rectangle with the given top-left coordinates, width, and height
void draw_rectangle(struct canvas *canvas, int x0, int y0, int width, int height, unsigned char color) {
    for (int y = y0; y < y0 + height; y++) {
        for (int x = x0; x < x0 + width; x++) {
            set_pixel(canvas, x, y, color);
        }
    }
}

// Draw a filled circle centered at the given coordinates with the given radius
void draw_filled_circle(struct canvas *canvas, int x0, int y0, int radius, unsigned char color) {
    for (int y = y0 - radius; y <= y0 + radius; y++) {
        for (int x = x0 - radius; x <= x0 + radius; x++) {
            if ((x - x0) * (x - x0) + (y - y0) * (y - y0) <= radius * radius) {
                set_pixel(canvas, x, y, color);
            }
        }
    }
}

// Generate a random color
unsigned char random_color() {
    return rand() % NUM_COLORS;
}

// Draw a random shape on the canvas
void draw_random_shape(struct canvas *canvas) {
    int shape_type = rand() % 4;
    int x0 = rand() % canvas->width;
    int y0 = rand() % canvas->height;
    int radius = rand() % (canvas->width / 2);
    int width = rand() % (canvas->width / 2);
    int height = rand() % (canvas->height / 2);
    unsigned char color = random_color();

    switch (shape_type) {
        case 0:
            draw_line(canvas, x0, y0, x0 + width, y0 + height, color);
            break;
        case 1:
            draw_circle(canvas, x0, y0, radius, color);
            break;
        case 2:
            draw_rectangle(canvas, x0, y0, width, height, color);
            break;
        case 3:
            draw_filled_circle(canvas, x0, y0, radius, color);
            break;
    }
}

// Fill the canvas with random shapes
void fill_canvas(struct canvas *canvas) {
    for (int i = 0; i < 1000; i++) {
        draw_random_shape(canvas);
    }
}

// Save the canvas to a PPM file
void save_canvas(struct canvas *canvas, const char *filename) {
    FILE *file = fopen(filename, "wb");
    fprintf(file, "P6\n%d %d\n255\n", canvas->width, canvas->height);
    fwrite(canvas->data, 1, canvas->width * canvas->height * 3, file);
    fclose(file);
}

int main(int argc, char **argv) {
    srand(time(NULL));

    // Create a new canvas
    struct canvas *canvas = create_canvas(WIDTH, HEIGHT);

    // Fill the canvas with random shapes
    fill_canvas(canvas);

    // Save the canvas to a PPM file
    save_canvas(canvas, "art.ppm");

    // Free the memory allocated for the canvas
    free_canvas(canvas);

    return 0;
}