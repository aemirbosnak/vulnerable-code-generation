//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 100
#define HEIGHT 100

typedef struct {
    unsigned char r, g, b;
} Color;

typedef struct {
    Color pixels[WIDTH][HEIGHT];
} Image;

Image* create_image() {
    Image* image = malloc(sizeof(Image));
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            image->pixels[i][j].r = 0;
            image->pixels[i][j].g = 0;
            image->pixels[i][j].b = 0;
        }
    }
    return image;
}

void destroy_image(Image* image) {
    free(image);
}

void set_pixel(Image* image, int x, int y, Color color) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return;
    }
    image->pixels[x][y] = color;
}

Color get_pixel(Image* image, int x, int y) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return (Color){0, 0, 0};
    }
    return image->pixels[x][y];
}

void draw_line(Image* image, int x1, int y1, int x2, int y2, Color color) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x2 - x1) / dx;
    int sy = (y2 - y1) / dy;
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

void draw_rectangle(Image* image, int x1, int y1, int x2, int y2, Color color) {
    draw_line(image, x1, y1, x2, y1, color);
    draw_line(image, x2, y1, x2, y2, color);
    draw_line(image, x2, y2, x1, y2, color);
    draw_line(image, x1, y2, x1, y1, color);
}

void draw_circle(Image* image, int x, int y, int radius, Color color) {
    int x0 = x - radius;
    int y0 = y - radius;
    int x1 = x + radius;
    int y1 = y + radius;
    int dx = radius * 2;
    int dy = radius * 2;
    int err = dx - dy;
    
    while (1) {
        set_pixel(image, x0, y0, color);
        set_pixel(image, x1, y0, color);
        set_pixel(image, x0, y1, color);
        set_pixel(image, x1, y1, color);
        if (x0 == x1 && y0 == y1) {
            break;
        }
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

void draw_triangle(Image* image, int x1, int y1, int x2, int y2, int x3, int y3, Color color) {
    draw_line(image, x1, y1, x2, y2, color);
    draw_line(image, x2, y2, x3, y3, color);
    draw_line(image, x3, y3, x1, y1, color);
}

void save_image(Image* image, const char* filename) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        return;
    }
    fprintf(fp, "P3\n%d %d\n255\n", WIDTH, HEIGHT);
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            fprintf(fp, "%d %d %d ", image->pixels[i][j].r, image->pixels[i][j].g, image->pixels[i][j].b);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

int main() {
    Image* image = create_image();
    
    // Draw a red circle
    draw_circle(image, 50, 50, 25, (Color){255, 0, 0});
    
    // Draw a green rectangle
    draw_rectangle(image, 25, 25, 75, 75, (Color){0, 255, 0});
    
    // Draw a blue triangle
    draw_triangle(image, 25, 75, 75, 75, 50, 100, (Color){0, 0, 255});
    
    // Save the image
    save_image(image, "image.ppm");
    
    // Destroy the image
    destroy_image(image);
    
    return 0;
}