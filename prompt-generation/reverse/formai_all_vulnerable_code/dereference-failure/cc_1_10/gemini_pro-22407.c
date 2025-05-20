//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Define the maximum size of the pixel art
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Define the colors that can be used
#define COLOR_BLACK 0
#define COLOR_WHITE 1
#define COLOR_RED 2
#define COLOR_GREEN 3
#define COLOR_BLUE 4

// Define the structure of a pixel
typedef struct {
    int color;
    bool is_on;
} Pixel;

// Define the structure of a pixel art
typedef struct {
    int width;
    int height;
    Pixel pixels[MAX_WIDTH][MAX_HEIGHT];
} PixelArt;

// Create a new pixel art
PixelArt* new_pixel_art(int width, int height) {
    PixelArt* pixel_art = malloc(sizeof(PixelArt));
    pixel_art->width = width;
    pixel_art->height = height;

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            pixel_art->pixels[i][j].color = COLOR_BLACK;
            pixel_art->pixels[i][j].is_on = false;
        }
    }

    return pixel_art;
}

// Free the memory allocated for a pixel art
void free_pixel_art(PixelArt* pixel_art) {
    free(pixel_art);
}

// Set the color of a pixel
void set_pixel_color(PixelArt* pixel_art, int x, int y, int color) {
    if (x < 0 || x >= pixel_art->width || y < 0 || y >= pixel_art->height) {
        return;
    }

    pixel_art->pixels[x][y].color = color;
}

// Turn on a pixel
void turn_on_pixel(PixelArt* pixel_art, int x, int y) {
    if (x < 0 || x >= pixel_art->width || y < 0 || y >= pixel_art->height) {
        return;
    }

    pixel_art->pixels[x][y].is_on = true;
}

// Turn off a pixel
void turn_off_pixel(PixelArt* pixel_art, int x, int y) {
    if (x < 0 || x >= pixel_art->width || y < 0 || y >= pixel_art->height) {
        return;
    }

    pixel_art->pixels[x][y].is_on = false;
}

// Draw a line from (x1, y1) to (x2, y2)
void draw_line(PixelArt* pixel_art, int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x2 - x1) / dx;
    int sy = (y2 - y1) / dy;

    int err = dx - dy;

    while (true) {
        turn_on_pixel(pixel_art, x1, y1);

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

// Draw a circle with center (x, y) and radius r
void draw_circle(PixelArt* pixel_art, int x, int y, int r) {
    int x0 = x;
    int y0 = y;

    int x1 = r;
    int y1 = 0;

    int dx = 1;
    int dy = -1;

    int err = dx - (r << 1);

    while (x1 > y1) {
        turn_on_pixel(pixel_art, x + x1, y + y1);
        turn_on_pixel(pixel_art, x - x1, y + y1);
        turn_on_pixel(pixel_art, x + x1, y - y1);
        turn_on_pixel(pixel_art, x - x1, y - y1);

        if (err <= 0) {
            y1++;
            err += 2 * y1 + 1;
        }

        if (err > 0) {
            x1--;
            err -= 2 * x1 + 1;
        }
    }

    if (x1 == y1) {
        turn_on_pixel(pixel_art, x + x1, y + y1);
        turn_on_pixel(pixel_art, x - x1, y + y1);
    }
}

// Draw a filled rectangle with top-left corner at (x, y) and width and height w and h
void draw_filled_rectangle(PixelArt* pixel_art, int x, int y, int w, int h) {
    for (int i = x; i < x + w; i++) {
        for (int j = y; j < y + h; j++) {
            turn_on_pixel(pixel_art, i, j);
        }
    }
}

// Save the pixel art to a PPM file
void save_pixel_art(PixelArt* pixel_art, const char* filename) {
    FILE* fp = fopen(filename, "w");

    fprintf(fp, "P3\n");
    fprintf(fp, "%d %d\n", pixel_art->width, pixel_art->height);
    fprintf(fp, "255\n");

    for (int i = 0; i < pixel_art->width; i++) {
        for (int j = 0; j < pixel_art->height; j++) {
            int color = pixel_art->pixels[i][j].color;
            fprintf(fp, "%d %d %d ", color, color, color);
        }

        fprintf(fp, "\n");
    }

    fclose(fp);
}

// Draw an ASCII representation of the pixel art
void draw_ascii_pixel_art(PixelArt* pixel_art) {
    for (int i = 0; i < pixel_art->width; i++) {
        for (int j = 0; j < pixel_art->height; j++) {
            if (pixel_art->pixels[i][j].is_on) {
                printf("■");
            } else {
                printf(" ");
            }
        }

        printf("\n");
    }
}

// Main function
int main() {
    // Create a new pixel art
    PixelArt* pixel_art = new_pixel_art(500, 500);

    // Draw a circle
    draw_circle(pixel_art, 250, 250, 100);

    // Draw a filled rectangle
    draw_filled_rectangle(pixel_art, 100, 100, 200, 200);

    // Draw a line
    draw_line(pixel_art, 0, 0, 500, 500);

    // Save the pixel art to a PPM file
    save_pixel_art(pixel_art, "pixel_art.ppm");

    // Draw an ASCII representation of the pixel art
    draw_ascii_pixel_art(pixel_art);

    // Free the memory allocated for the pixel art
    free_pixel_art(pixel_art);

    return 0;
}