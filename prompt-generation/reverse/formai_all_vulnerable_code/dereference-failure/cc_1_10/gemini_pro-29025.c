//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the maximum width and height of the pixel art
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Define the colors that can be used in the pixel art
#define COLOR_BLACK 0x000000
#define COLOR_WHITE 0xFFFFFF
#define COLOR_RED 0xFF0000
#define COLOR_GREEN 0x00FF00
#define COLOR_BLUE 0x0000FF

// Define the structure of a pixel
typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

// Define the structure of a pixel art image
typedef struct {
    int width;
    int height;
    Pixel pixels[MAX_WIDTH][MAX_HEIGHT];
} PixelArtImage;

// Create a new pixel art image
PixelArtImage *create_pixel_art_image(int width, int height) {
    PixelArtImage *image = malloc(sizeof(PixelArtImage));
    image->width = width;
    image->height = height;
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            image->pixels[x][y].red = 0;
            image->pixels[x][y].green = 0;
            image->pixels[x][y].blue = 0;
        }
    }
    return image;
}

// Free the memory allocated for a pixel art image
void free_pixel_art_image(PixelArtImage *image) {
    free(image);
}

// Set the color of a pixel
void set_pixel(PixelArtImage *image, int x, int y, unsigned int color) {
    image->pixels[x][y].red = (color >> 16) & 0xFF;
    image->pixels[x][y].green = (color >> 8) & 0xFF;
    image->pixels[x][y].blue = color & 0xFF;
}

// Draw a line from one pixel to another
void draw_line(PixelArtImage *image, int x1, int y1, int x2, int y2, unsigned int color) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
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

// Draw a circle with a given radius
void draw_circle(PixelArtImage *image, int x, int y, int radius, unsigned int color) {
    int x0 = x - radius;
    int y0 = y - radius;
    int x1 = x + radius;
    int y1 = y + radius;
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int err = dx - dy;
    while (x0 <= x1 && y0 <= y1) {
        set_pixel(image, x0, y0, color);
        set_pixel(image, x1, y0, color);
        set_pixel(image, x0, y1, color);
        set_pixel(image, x1, y1, color);
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0++;
            x1--;
        }
        if (e2 < dx) {
            err += dx;
            y0++;
            y1--;
        }
    }
}

// Draw a rectangle with a given width and height
void draw_rectangle(PixelArtImage *image, int x1, int y1, int width, int height, unsigned int color) {
    for (int x = x1; x < x1 + width; x++) {
        for (int y = y1; y < y1 + height; y++) {
            set_pixel(image, x, y, color);
        }
    }
}

// Draw a triangle with given vertices
void draw_triangle(PixelArtImage *image, int x1, int y1, int x2, int y2, int x3, int y3, unsigned int color) {
    draw_line(image, x1, y1, x2, y2, color);
    draw_line(image, x2, y2, x3, y3, color);
    draw_line(image, x3, y3, x1, y1, color);
}

// Generate a random pixel art image
PixelArtImage *generate_random_pixel_art_image(int width, int height) {
    PixelArtImage *image = create_pixel_art_image(width, height);
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            unsigned int color = rand() % 0xFFFFFF;
            set_pixel(image, x, y, color);
        }
    }
    return image;
}

// Save a pixel art image to a PPM file
void save_pixel_art_image(PixelArtImage *image, char *filename) {
    FILE *file = fopen(filename, "w");
    fprintf(file, "P3\n%d %d\n255\n", image->width, image->height);
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            fprintf(file, "%d %d %d ", image->pixels[x][y].red, image->pixels[x][y].green, image->pixels[x][y].blue);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

// Main function
int main() {
    // Create a pixel art image
    PixelArtImage *image = create_pixel_art_image(640, 480);

    // Draw a blue rectangle
    draw_rectangle(image, 10, 10, 100, 100, COLOR_BLUE);

    // Draw a red circle
    draw_circle(image, 200, 200, 50, COLOR_RED);

    // Draw a green triangle
    draw_triangle(image, 300, 300, 400, 300, 350, 400, COLOR_GREEN);

    // Save the pixel art image to a PPM file
    save_pixel_art_image(image, "pixel_art.ppm");

    // Free the memory allocated for the pixel art image
    free_pixel_art_image(image);

    return 0;
}