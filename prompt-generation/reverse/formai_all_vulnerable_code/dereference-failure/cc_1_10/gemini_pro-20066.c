//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct {
    int width;
    int height;
    int data[MAX_WIDTH * MAX_HEIGHT];
} Image;

Image *create_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    memset(image->data, 0, sizeof(int) * width * height);
    return image;
}

void destroy_image(Image *image) {
    free(image);
}

void set_pixel(Image *image, int x, int y, int color) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return;
    }
    image->data[y * image->width + x] = color;
}

int get_pixel(Image *image, int x, int y) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return 0;
    }
    return image->data[y * image->width + x];
}

void draw_line(Image *image, int x1, int y1, int x2, int y2, int color) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xinc = dx / (float)steps;
    float yinc = dy / (float)steps;
    float x = x1;
    float y = y1;
    for (int i = 0; i <= steps; i++) {
        set_pixel(image, (int)x, (int)y, color);
        x += xinc;
        y += yinc;
    }
}

void draw_circle(Image *image, int x, int y, int radius, int color) {
    int x0 = x - radius;
    int y0 = y - radius;
    int x1 = x + radius;
    int y1 = y + radius;
    int dx = x1 - x0;
    int dy = y1 - y0;
    int d = dx * dx + dy * dy - radius * radius;
    while (x0 <= x1 && y0 <= y1) {
        set_pixel(image, x0, y0, color);
        set_pixel(image, x0, y1, color);
        set_pixel(image, x1, y0, color);
        set_pixel(image, x1, y1, color);
        if (d < 0) {
            d += 2 * dx + 3;
        } else {
            d += 2 * (dx - dy) + 5;
            y0++;
            y1--;
        }
        x0++;
        x1--;
    }
}

void draw_rectangle(Image *image, int x, int y, int width, int height, int color) {
    for (int i = 0; i < width; i++) {
        set_pixel(image, x + i, y, color);
        set_pixel(image, x + i, y + height - 1, color);
    }
    for (int i = 0; i < height; i++) {
        set_pixel(image, x, y + i, color);
        set_pixel(image, x + width - 1, y + i, color);
    }
}

int main() {
    Image *image = create_image(MAX_WIDTH, MAX_HEIGHT);

    // Draw a black background
    for (int i = 0; i < MAX_WIDTH; i++) {
        for (int j = 0; j < MAX_HEIGHT; j++) {
            set_pixel(image, i, j, 0);
        }
    }

    // Draw a white rectangle
    draw_rectangle(image, 20, 20, 60, 60, 0xFFFFFF);

    // Draw a blue circle
    draw_circle(image, 50, 50, 20, 0x0000FF);

    // Draw a green line
    draw_line(image, 20, 20, 80, 80, 0x00FF00);

    // Save the image to a file
    FILE *file = fopen("image.ppm", "w");
    fprintf(file, "P3\n%d %d\n255\n", image->width, image->height);
    for (int i = 0; i < MAX_WIDTH; i++) {
        for (int j = 0; j < MAX_HEIGHT; j++) {
            int color = get_pixel(image, i, j);
            fprintf(file, "%d %d %d ", (color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF);
        }
        fprintf(file, "\n");
    }
    fclose(file);

    destroy_image(image);

    return 0;
}