//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Pixel {
    unsigned char r, g, b;
} Pixel;

typedef struct Image {
    int width, height;
    Pixel *pixels;
} Image;

Image *create_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(sizeof(Pixel) * width * height);
    return image;
}

void destroy_image(Image *image) {
    free(image->pixels);
    free(image);
}

void set_pixel(Image *image, int x, int y, Pixel pixel) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return;
    }
    image->pixels[y * image->width + x] = pixel;
}

Pixel get_pixel(Image *image, int x, int y) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return (Pixel) {0, 0, 0};
    }
    return image->pixels[y * image->width + x];
}

void draw_line(Image *image, int x1, int y1, int x2, int y2, Pixel pixel) {
    int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
    int dy = abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    while (true) {
        set_pixel(image, x1, y1, pixel);
        if (x1 == x2 && y1 == y2) {
            break;
        }
        int e2 = err;
        if (e2 > -dx) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dy) {
            err += dx;
            y1 += sy;
        }
    }
}

void draw_circle(Image *image, int x, int y, int radius, Pixel pixel) {
    int x0 = 0, y0 = radius;
    int err = 1 - radius;
    while (x0 <= y0) {
        set_pixel(image, x + x0, y + y0, pixel);
        set_pixel(image, x + y0, y + x0, pixel);
        set_pixel(image, x - x0, y + y0, pixel);
        set_pixel(image, x - y0, y + x0, pixel);
        set_pixel(image, x + x0, y - y0, pixel);
        set_pixel(image, x + y0, y - x0, pixel);
        set_pixel(image, x - x0, y - y0, pixel);
        set_pixel(image, x - y0, y - x0, pixel);
        x0++;
        if (err < 0) {
            err += 2 * x0 + 1;
        } else {
            y0--;
            err += 2 * (x0 - y0) + 1;
        }
    }
}

void draw_rectangle(Image *image, int x1, int y1, int x2, int y2, Pixel pixel) {
    draw_line(image, x1, y1, x2, y1, pixel);
    draw_line(image, x2, y1, x2, y2, pixel);
    draw_line(image, x2, y2, x1, y2, pixel);
    draw_line(image, x1, y2, x1, y1, pixel);
}

void draw_triangle(Image *image, int x1, int y1, int x2, int y2, int x3, int y3, Pixel pixel) {
    draw_line(image, x1, y1, x2, y2, pixel);
    draw_line(image, x2, y2, x3, y3, pixel);
    draw_line(image, x3, y3, x1, y1, pixel);
}

void save_image(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        return;
    }
    fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
}

int main() {
    Image *image = create_image(512, 512);

    // Draw a black background
    Pixel black = {0, 0, 0};
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            set_pixel(image, x, y, black);
        }
    }

    // Draw a red circle
    Pixel red = {255, 0, 0};
    draw_circle(image, 256, 256, 128, red);

    // Draw a green rectangle
    Pixel green = {0, 255, 0};
    draw_rectangle(image, 128, 128, 384, 384, green);

    // Draw a blue triangle
    Pixel blue = {0, 0, 255};
    draw_triangle(image, 128, 384, 384, 384, 256, 128, blue);

    // Save the image to a file
    save_image(image, "pixel_art.ppm");

    // Free the image memory
    destroy_image(image);

    return 0;
}