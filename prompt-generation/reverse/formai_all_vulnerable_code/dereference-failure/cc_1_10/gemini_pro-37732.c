//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    unsigned char r, g, b;
} Color;

typedef struct {
    Color **data;
    int width, height;
} Image;

Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->data = malloc(sizeof(Color *) * height);
    for (int i = 0; i < height; i++) {
        image->data[i] = malloc(sizeof(Color) * width);
    }
    image->width = width;
    image->height = height;
    return image;
}

void free_image(Image *image) {
    for (int i = 0; i < image->height; i++) {
        free(image->data[i]);
    }
    free(image->data);
    free(image);
}

void set_pixel(Image *image, int x, int y, Color color) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return;
    }
    image->data[y][x] = color;
}

void line(Image *image, int x0, int y0, int x1, int y1, Color color) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = (dx>dy ? dx : -dy)/2, e2;

    for(;;){
        set_pixel(image, x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        e2 = err;
        if (e2 > -dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }
    }
}

void circle(Image *image, int x0, int y0, int radius, Color color) {
    int x = radius-1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (radius << 1);

    while (x >= y) {
        set_pixel(image, x0 + x, y0 + y, color);
        set_pixel(image, x0 + y, y0 + x, color);
        set_pixel(image, x0 - y, y0 + x, color);
        set_pixel(image, x0 - x, y0 + y, color);
        set_pixel(image, x0 - x, y0 - y, color);
        set_pixel(image, x0 - y, y0 - x, color);
        set_pixel(image, x0 + y, y0 - x, color);
        set_pixel(image, x0 + x, y0 - y, color);

        if (err <= 0) {
            y++;
            err += dy;
            dy += 2;
        }
        if (err > 0) {
            x--;
            dx += 2;
            err += dx - (radius << 1);
        }
    }
}

void rectangle(Image *image, int x0, int y0, int width, int height, Color color) {
    for (int i = 0; i < width; i++) {
        set_pixel(image, x0 + i, y0, color);
        set_pixel(image, x0 + i, y0 + height - 1, color);
    }
    for (int i = 0; i < height; i++) {
        set_pixel(image, x0, y0 + i, color);
        set_pixel(image, x0 + width - 1, y0 + i, color);
    }
}

void fill_region(Image *image, int x, int y, Color color) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return;
    }
    if (image->data[y][x].r == color.r && image->data[y][x].g == color.g && image->data[y][x].b == color.b) {
        return;
    }
    set_pixel(image, x, y, color);

    fill_region(image, x-1, y, color);
    fill_region(image, x+1, y, color);
    fill_region(image, x, y-1, color);
    fill_region(image, x, y+1, color);
}

int main() {
    Image *image = new_image(WIDTH, HEIGHT);

    // Draw a black background
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            set_pixel(image, i, j, (Color){0, 0, 0});
        }
    }

    // Draw a white circle
    circle(image, WIDTH / 2, HEIGHT / 2, 100, (Color){255, 255, 255});

    // Draw a red rectangle
    rectangle(image, 100, 100, 200, 100, (Color){255, 0, 0});

    // Draw a blue line
    line(image, 0, 0, WIDTH, HEIGHT, (Color){0, 0, 255});

    // Fill a region with green
    fill_region(image, 200, 200, (Color){0, 255, 0});

    // Save the image to a PNG file
    FILE *file = fopen("image.png", "wb");
    fwrite(image->data, sizeof(Color), WIDTH * HEIGHT, file);
    fclose(file);

    free_image(image);

    return 0;
}