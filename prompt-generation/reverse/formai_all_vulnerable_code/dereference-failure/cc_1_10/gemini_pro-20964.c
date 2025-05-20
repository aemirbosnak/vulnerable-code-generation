//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define WIDTH 640
#define HEIGHT 480
#define MAX_COLORS 256

typedef struct {
    unsigned char r, g, b;
} Color;

typedef struct {
    int x, y;
    Color color;
} Pixel;

typedef struct {
    int num_pixels;
    Pixel *pixels;
} Image;

Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->num_pixels = width * height;
    image->pixels = malloc(sizeof(Pixel) * image->num_pixels);
    return image;
}

void free_image(Image *image) {
    free(image->pixels);
    free(image);
}

void set_pixel(Image *image, int x, int y, Color color) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return;
    }
    image->pixels[y * WIDTH + x] = (Pixel) {x, y, color};
}

Color get_pixel(Image *image, int x, int y) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return (Color) {0, 0, 0};
    }
    return image->pixels[y * WIDTH + x].color;
}

void draw_line(Image *image, int x1, int y1, int x2, int y2, Color color) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x2 > x1) ? 1 : -1;
    int sy = (y2 > y1) ? 1 : -1;
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

void draw_circle(Image *image, int x, int y, int radius, Color color) {
    int f = 1 - radius;
    int ddF_x = 0;
    int ddF_y = -2 * radius;
    int x1 = 0;
    int y1 = radius;

    set_pixel(image, x, y + radius, color);
    set_pixel(image, x, y - radius, color);
    set_pixel(image, x + radius, y, color);
    set_pixel(image, x - radius, y, color);

    while (x1 < y1) {
        if (f >= 0) {
            y1--;
            ddF_y += 2;
            f += ddF_y;
        }
        x1++;
        ddF_x += 2;
        f += ddF_x + 1;

        set_pixel(image, x + x1, y + y1, color);
        set_pixel(image, x - x1, y + y1, color);
        set_pixel(image, x + x1, y - y1, color);
        set_pixel(image, x - x1, y - y1, color);
        set_pixel(image, x + y1, y + x1, color);
        set_pixel(image, x - y1, y + x1, color);
        set_pixel(image, x + y1, y - x1, color);
        set_pixel(image, x - y1, y - x1, color);
    }
}

void draw_rectangle(Image *image, int x1, int y1, int x2, int y2, Color color) {
    for (int y = y1; y <= y2; y++) {
        for (int x = x1; x <= x2; x++) {
            set_pixel(image, x, y, color);
        }
    }
}

void save_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(file, "P3\n%d %d\n255\n", WIDTH, HEIGHT);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            Color color = get_pixel(image, x, y);
            fprintf(file, "%d %d %d ", color.r, color.g, color.b);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

int main() {
    srand(time(NULL));

    Image *image = new_image(WIDTH, HEIGHT);

    // Draw some random lines
    for (int i = 0; i < 100; i++) {
        int x1 = rand() % WIDTH;
        int y1 = rand() % HEIGHT;
        int x2 = rand() % WIDTH;
        int y2 = rand() % HEIGHT;
        Color color = (Color) {rand() % 255, rand() % 255, rand() % 255};
        draw_line(image, x1, y1, x2, y2, color);
    }

    // Draw some random circles
    for (int i = 0; i < 100; i++) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        int radius = rand() % 100;
        Color color = (Color) {rand() % 255, rand() % 255, rand() % 255};
        draw_circle(image, x, y, radius, color);
    }

    // Draw a rectangle
    draw_rectangle(image, 100, 100, 200, 200, (Color) {0, 255, 0});

    // Save the image to a file
    save_image(image, "image.ppm");

    free_image(image);

    return 0;
}