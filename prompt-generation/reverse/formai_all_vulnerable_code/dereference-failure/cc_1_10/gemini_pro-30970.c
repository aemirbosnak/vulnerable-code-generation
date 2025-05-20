//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

// A brush to paint the canvas with colors
void md5_hash(char *input, char *output) {
    MD5_CTX md5;
    MD5_Init(&md5);
    MD5_Update(&md5, input, strlen(input));
    MD5_Final((unsigned char *)output, &md5);
}

// A palette to mix and match the colors
char *md5_to_hex(unsigned char *input) {
    char *output = malloc(33);
    for (int i = 0; i < 16; i++) {
        sprintf(output + i * 2, "%02x", input[i]);
    }
    output[32] = '\0';
    return output;
}

// An easel to hold the canvas
struct canvas {
    char *data;
    int width;
    int height;
};

// A function to create a new canvas
struct canvas *new_canvas(int width, int height) {
    struct canvas *canvas = malloc(sizeof(struct canvas));
    canvas->data = malloc(width * height);
    canvas->width = width;
    canvas->height = height;
    return canvas;
}

// A function to free the memory allocated for the canvas
void free_canvas(struct canvas *canvas) {
    free(canvas->data);
    free(canvas);
}

// A function to set a pixel on the canvas
void set_pixel(struct canvas *canvas, int x, int y, char *color) {
    canvas->data[y * canvas->width + x] = color;
}

// A function to get a pixel from the canvas
char *get_pixel(struct canvas *canvas, int x, int y) {
    return canvas->data[y * canvas->width + x];
}

// A function to draw a line on the canvas
void draw_line(struct canvas *canvas, int x1, int y1, int x2, int y2, char *color) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x2 >= x1) ? 1 : -1;
    int sy = (y2 >= y1) ? 1 : -1;
    int err = dx - dy;
    while (1) {
        set_pixel(canvas, x1, y1, color);
        if (x1 == x2 && y1 == y2) break;
        int e2 = err << 1;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx) { err += dx; y1 += sy; }
    }
}

// A function to draw a circle on the canvas
void draw_circle(struct canvas *canvas, int x, int y, int radius, char *color) {
    int x1 = x - radius;
    int y1 = y - radius;
    int x2 = x + radius;
    int y2 = y + radius;
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            if ((i - x) * (i - x) + (j - y) * (j - y) <= radius * radius) {
                set_pixel(canvas, i, j, color);
            }
        }
    }
}

// A function to draw a rectangle on the canvas
void draw_rectangle(struct canvas *canvas, int x1, int y1, int x2, int y2, char *color) {
    draw_line(canvas, x1, y1, x2, y1, color);
    draw_line(canvas, x1, y1, x1, y2, color);
    draw_line(canvas, x2, y1, x2, y2, color);
    draw_line(canvas, x1, y2, x2, y2, color);
}

// A function to fill a region on the canvas with a color
void fill(struct canvas *canvas, int x, int y, char *color) {
    if (x < 0 || x >= canvas->width || y < 0 || y >= canvas->height) return;
    if (strcmp(get_pixel(canvas, x, y), color) == 0) return;
    set_pixel(canvas, x, y, color);
    fill(canvas, x + 1, y, color);
    fill(canvas, x - 1, y, color);
    fill(canvas, x, y + 1, color);
    fill(canvas, x, y - 1, color);
}

// A function to save the canvas to a file
void save_canvas(struct canvas *canvas, char *filename) {
    FILE *file = fopen(filename, "wb");
    fwrite(canvas->data, 1, canvas->width * canvas->height, file);
    fclose(file);
}

// The main function
int main() {
    // Create a new canvas
    struct canvas *canvas = new_canvas(500, 500);

    // Draw a circle on the canvas
    draw_circle(canvas, 250, 250, 100, "000000");

    // Draw a rectangle on the canvas
    draw_rectangle(canvas, 100, 100, 400, 400, "000000");

    // Fill the region inside the rectangle with a color
    fill(canvas, 250, 250, "FF0000");

    // Save the canvas to a file
    save_canvas(canvas, "output.bmp");

    // Free the memory allocated for the canvas
    free_canvas(canvas);

    return 0;
}