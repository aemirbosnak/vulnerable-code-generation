//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a pixel
typedef struct {
    unsigned char r, g, b;
} Pixel;

// Structure to represent an image
typedef struct {
    int width, height;
    Pixel *pixels;
} Image;

// Function to create a new image
Image *create_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height * sizeof(Pixel));
    return image;
}

// Function to destroy an image
void destroy_image(Image *image) {
    free(image->pixels);
    free(image);
}

// Function to set a pixel in an image
void set_pixel(Image *image, int x, int y, Pixel color) {
    image->pixels[y * image->width + x] = color;
}

// Function to get a pixel from an image
Pixel get_pixel(Image *image, int x, int y) {
    return image->pixels[y * image->width + x];
}

// Function to draw a line in an image
void draw_line(Image *image, int x1, int y1, int x2, int y2, Pixel color) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x2 >= x1) ? 1 : -1;
    int sy = (y2 >= y1) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        set_pixel(image, x1, y1, color);

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

// Function to draw a circle in an image
void draw_circle(Image *image, int x, int y, int radius, Pixel color) {
    for (int i = -radius; i <= radius; i++) {
        for (int j = -radius; j <= radius; j++) {
            if (i * i + j * j <= radius * radius) {
                set_pixel(image, x + i, y + j, color);
            }
        }
    }
}

// Function to draw a rectangle in an image
void draw_rectangle(Image *image, int x1, int y1, int x2, int y2, Pixel color) {
    for (int i = x1; i <= x2; i++) {
        set_pixel(image, i, y1, color);
        set_pixel(image, i, y2, color);
    }

    for (int i = y1; i <= y2; i++) {
        set_pixel(image, x1, i, color);
        set_pixel(image, x2, i, color);
    }
}

// Function to write an image to a PPM file
void write_ppm(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, fp);
    fclose(fp);
}

// Main function
int main() {
    // Create a new image
    Image *image = create_image(500, 500);

    // Set the background color
    Pixel background = {0, 0, 0};
    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height; j++) {
            set_pixel(image, i, j, background);
        }
    }

    // Draw a circle
    Pixel red = {255, 0, 0};
    draw_circle(image, 250, 250, 100, red);

    // Draw a rectangle
    Pixel green = {0, 255, 0};
    draw_rectangle(image, 100, 100, 400, 400, green);

    // Draw a line
    Pixel blue = {0, 0, 255};
    draw_line(image, 100, 100, 400, 400, blue);

    // Write the image to a PPM file
    write_ppm(image, "output.ppm");

    // Destroy the image
    destroy_image(image);

    return 0;
}