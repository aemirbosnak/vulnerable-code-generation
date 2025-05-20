//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum width and height of the pixel art
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Define the colors that can be used in the pixel art
#define BLACK 0
#define WHITE 1
#define RED 2
#define GREEN 3
#define BLUE 4
#define YELLOW 5
#define CYAN 6
#define MAGENTA 7

// Define the structure of a pixel
typedef struct pixel {
    int color;
} pixel;

// Define the structure of a pixel art image
typedef struct image {
    int width;
    int height;
    pixel pixels[MAX_WIDTH][MAX_HEIGHT];
} image;

// Create a new pixel art image
image *create_image(int width, int height) {
    image *image = malloc(sizeof(image));
    image->width = width;
    image->height = height;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            image->pixels[i][j].color = BLACK;
        }
    }
    return image;
}

// Free the memory allocated for a pixel art image
void free_image(image *image) {
    free(image);
}

// Set the color of a pixel
void set_pixel(image *image, int x, int y, int color) {
    if (x >= 0 && x < image->width && y >= 0 && y < image->height) {
        image->pixels[x][y].color = color;
    }
}

// Draw a line from one point to another
void draw_line(image *image, int x1, int y1, int x2, int y2, int color) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x2 - x1) / dx;
    int sy = (y2 - y1) / dy;
    int err = dx - dy;
    while (x1 != x2 || y1 != y2) {
        set_pixel(image, x1, y1, color);
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

// Draw a rectangle
void draw_rectangle(image *image, int x1, int y1, int x2, int y2, int color) {
    draw_line(image, x1, y1, x2, y1, color);
    draw_line(image, x2, y1, x2, y2, color);
    draw_line(image, x2, y2, x1, y2, color);
    draw_line(image, x1, y2, x1, y1, color);
}

// Draw a circle
void draw_circle(image *image, int cx, int cy, int r, int color) {
    int x = 0;
    int y = r;
    int p = 3 - 2 * r;
    while (x < y) {
        set_pixel(image, cx + x, cy + y, color);
        set_pixel(image, cx - x, cy + y, color);
        set_pixel(image, cx + x, cy - y, color);
        set_pixel(image, cx - x, cy - y, color);
        set_pixel(image, cx + y, cy + x, color);
        set_pixel(image, cx - y, cy + x, color);
        set_pixel(image, cx + y, cy - x, color);
        set_pixel(image, cx - y, cy - x, color);
        if (p < 0) {
            p += 4 * x + 6;
        } else {
            p += 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

// Save the pixel art image to a file
void save_image(image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    fprintf(file, "P3\n%d %d\n255\n", image->width, image->height);
    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height; j++) {
            fprintf(file, "%d %d %d ", image->pixels[i][j].color, image->pixels[i][j].color, image->pixels[i][j].color);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

// Main function
int main() {
    // Create a new pixel art image
    image *image = create_image(300, 300);

    // Draw a circle
    draw_circle(image, 150, 150, 100, WHITE);

    // Draw a rectangle
    draw_rectangle(image, 50, 50, 250, 250, BLACK);

    // Draw a line
    draw_line(image, 50, 50, 250, 250, RED);

    // Save the pixel art image to a file
    save_image(image, "pixel_art.ppm");

    // Free the memory allocated for the pixel art image
    free_image(image);

    return 0;
}