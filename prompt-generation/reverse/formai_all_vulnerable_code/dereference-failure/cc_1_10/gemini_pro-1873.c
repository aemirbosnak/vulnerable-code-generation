//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define WIDTH 800
#define HEIGHT 600
#define CHANNEL 3
#define MAX_BRUSH_SIZE 50

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    Pixel *pixels;
    int width, height;
} Image;

Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height * sizeof(Pixel));
    return image;
}

void free_image(Image *image) {
    free(image->pixels);
    free(image);
}

void save_image(Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, fp);
    fclose(fp);
}

void fill_image(Image *image, Pixel color) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->pixels[i] = color;
    }
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

void draw_line(Image *image, int x1, int y1, int x2, int y2, Pixel color) {
    int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
    int dy = abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    while (1) {
        set_pixel(image, x1, y1, color);
        if (x1 == x2 && y1 == y2) break;
        int e2 = err;
        if (e2 > -dx) { err -= dy; x1 += sx; }
        if (e2 < dy) { err += dx; y1 += sy; }
    }
}

void draw_circle(Image *image, int x, int y, int radius, Pixel color) {
    int f = 1 - radius;
    int ddF_x = 1;
    int ddF_y = -2 * radius;
    int x1 = 0;
    int y1 = radius;
    set_pixel(image, x + x1, y + y1, color);
    set_pixel(image, x - x1, y + y1, color);
    set_pixel(image, x + x1, y - y1, color);
    set_pixel(image, x - x1, y - y1, color);
    while (x1 < y1) {
        if (f >= 0) {
            y1--;
            ddF_y += 2;
            f += ddF_y;
        }
        x1++;
        ddF_x += 2;
        f += ddF_x;
        set_pixel(image, x + x1, y + y1, color);
        set_pixel(image, x - x1, y + y1, color);
        set_pixel(image, x + x1, y - y1, color);
        set_pixel(image, x - x1, y - y1, color);
    }
}

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

void draw_brush(Image *image, int x, int y, int radius, Pixel color) {
    for (int i = -radius; i <= radius; i++) {
        for (int j = -radius; j <= radius; j++) {
            if (i * i + j * j <= radius * radius) {
                set_pixel(image, x + i, y + j, color);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    Image *image = new_image(WIDTH, HEIGHT);
    fill_image(image, (Pixel){0, 0, 0});

    // Draw a rainbow in the sky
    int sky_height = 200;
    for (int i = 0; i < sky_height; i++) {
        float t = i / (float)sky_height;
        Pixel color = {
            255 * (1 - t),
            255 * t,
            255 * (1 - t)
        };
        for (int j = 0; j < WIDTH; j++) {
            set_pixel(image, j, i, color);
        }
    }

    // Draw a green grass field
    int grass_height = 200;
    for (int i = sky_height; i < sky_height + grass_height; i++) {
        for (int j = 0; j < WIDTH; j++) {
            set_pixel(image, j, i, (Pixel){0, 255, 0});
        }
    }

    // Draw some clouds
    int num_clouds = 5;
    for (int i = 0; i < num_clouds; i++) {
        int x = rand() % WIDTH;
        int y = rand() % sky_height;
        int radius = rand() % 50 + 50;
        draw_circle(image, x, y, radius, (Pixel){255, 255, 255});
    }

    // Draw a sun
    int sun_x = WIDTH / 2;
    int sun_y = sky_height / 2;
    int sun_radius = 50;
    draw_circle(image, sun_x, sun_y, sun_radius, (Pixel){255, 255, 0});

    // Draw a bird
    int bird_x = WIDTH / 2;
    int bird_y = sky_height / 2;
    int bird_radius = 20;
    draw_circle(image, bird_x, bird_y, bird_radius, (Pixel){0, 0, 0});
    draw_line(image, bird_x - bird_radius, bird_y, bird_x + bird_radius, bird_y, (Pixel){0, 0, 0});
    draw_line(image, bird_x, bird_y - bird_radius, bird_x, bird_y + bird_radius, (Pixel){0, 0, 0});

    // Save the image
    save_image(image, "image.ppm");
    free_image(image);
    return 0;
}