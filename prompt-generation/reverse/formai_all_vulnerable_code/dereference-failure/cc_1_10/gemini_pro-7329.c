//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    Pixel *pixels;
    int width, height;
} Image;

Image *create_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height * sizeof(Pixel));
    return image;
}

void destroy_image(Image *image) {
    free(image->pixels);
    free(image);
}

void set_pixel(Image *image, int x, int y, Pixel color) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return;
    }
    image->pixels[y * image->width + x] = color;
}

Pixel get_pixel(Image *image, int x, int y) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return (Pixel){0, 0, 0};
    }
    return image->pixels[y * image->width + x];
}

void draw_line(Image *image, int x0, int y0, int x1, int y1, Pixel color) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    while (1) {
        set_pixel(image, x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        int e2 = err;
        if (e2 > -dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }
    }
}

void draw_circle(Image *image, int x0, int y0, int radius, Pixel color) {
    int x = 0, y = radius;
    int dp = 1 - radius;
    do {
        set_pixel(image, x0 + x, y0 + y, color);
        set_pixel(image, x0 - x, y0 + y, color);
        set_pixel(image, x0 + x, y0 - y, color);
        set_pixel(image, x0 - x, y0 - y, color);
        set_pixel(image, x0 + y, y0 + x, color);
        set_pixel(image, x0 - y, y0 + x, color);
        set_pixel(image, x0 + y, y0 - x, color);
        set_pixel(image, x0 - y, y0 - x, color);
        if (dp < 0) dp += 2 * x + 3;
        else { dp += 2 * (x - y) + 5; y--; }
        x++;
    } while (x < y);
}

void draw_rectangle(Image *image, int x0, int y0, int width, int height, Pixel color) {
    for (int y = y0; y < y0 + height; y++) {
        for (int x = x0; x < x0 + width; x++) {
            set_pixel(image, x, y, color);
        }
    }
}

void draw_text(Image *image, int x, int y, const char *text, Pixel color) {
    // TODO: implement this function
}

void save_image(Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("fopen");
        return;
    }
    fprintf(fp, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, fp);
    fclose(fp);
}

int main() {
    Image *image = create_image(WIDTH, HEIGHT);

    // Draw a gradient background
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            Pixel color = {
                (unsigned char)(x * 255 / WIDTH),
                (unsigned char)(y * 255 / HEIGHT),
                (unsigned char)(0)
            };
            set_pixel(image, x, y, color);
        }
    }

    // Draw a white circle
    draw_circle(image, WIDTH / 2, HEIGHT / 2, 100, (Pixel){255, 255, 255});

    // Draw a black rectangle
    draw_rectangle(image, 100, 100, 200, 200, (Pixel){0, 0, 0});

    // Draw some text
    draw_text(image, 100, 100, "Hello, world!", (Pixel){255, 255, 255});

    // Save the image to a file
    save_image(image, "output.ppm");

    destroy_image(image);

    return 0;
}