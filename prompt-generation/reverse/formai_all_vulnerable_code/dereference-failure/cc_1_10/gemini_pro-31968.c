//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Our canvas, painted with RGB pixels
typedef struct {
    unsigned char r, g, b;
} Color;

typedef struct {
    int width, height;
    Color **data;
} Image;

// Initialize an image with size and default color
Image *image_new(int width, int height, Color color) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(sizeof(Color *) * height);
    for (int y = 0; y < height; y++) {
        image->data[y] = malloc(sizeof(Color) * width);
        for (int x = 0; x < width; x++) {
            image->data[y][x] = color;
        }
    }
    return image;
}

// Free the memory allocated for the image
void image_free(Image *image) {
    for (int y = 0; y < image->height; y++) {
        free(image->data[y]);
    }
    free(image->data);
    free(image);
}

// Set the pixel at (x, y) to the given color
void image_set_pixel(Image *image, int x, int y, Color color) {
    image->data[y][x] = color;
}

// Get the color of the pixel at (x, y)
Color image_get_pixel(Image *image, int x, int y) {
    return image->data[y][x];
}

// Draw a circle with the given center and radius
void image_draw_circle(Image *image, int cx, int cy, int r, Color color) {
    for (int y = cy - r; y <= cy + r; y++) {
        for (int x = cx - r; x <= cx + r; x++) {
            if ((x - cx) * (x - cx) + (y - cy) * (y - cy) <= r * r) {
                image_set_pixel(image, x, y, color);
            }
        }
    }
}

// Draw a line using the Bresenham algorithm
void image_draw_line(Image *image, int x0, int y0, int x1, int y1, Color color) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    while (x0 != x1 || y0 != y1) {
        image_set_pixel(image, x0, y0, color);
        int e2 = err;
        if (e2 > -dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }
    }
}

// Save the image to a PPM file
void image_save_ppm(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            fputc(image->data[y][x].r, file);
            fputc(image->data[y][x].g, file);
            fputc(image->data[y][x].b, file);
        }
    }
    fclose(file);
}

int main() {
    // Create a 500x500 black canvas
    Image *image = image_new(500, 500, (Color){0, 0, 0});

    // Draw an orange circle in the center
    image_draw_circle(image, 250, 250, 100, (Color){255, 165, 0});

    // Draw a blue line from the top-left to the bottom-right corner
    image_draw_line(image, 0, 0, 500, 500, (Color){0, 0, 255});

    // Create a yellow rectangle in the top-right corner
    for (int y = 0; y < 100; y++) {
        for (int x = 400; x < 500; x++) {
            image_set_pixel(image, x, y, (Color){255, 255, 0});
        }
    }

    // Save the image as "pixel_art.ppm"
    image_save_ppm(image, "pixel_art.ppm");

    // Free the memory allocated for the image
    image_free(image);
    
    return 0;
}