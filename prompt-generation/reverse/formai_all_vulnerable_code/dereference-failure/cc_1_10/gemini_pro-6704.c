//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
    int width;
    int height;
    int max_color;
    unsigned char *data;
} PixelArt;

PixelArt *create_pixel_art(int width, int height, int max_color) {
    PixelArt *p = malloc(sizeof(PixelArt));
    if (!p) {
        return NULL;
    }
    p->width = width;
    p->height = height;
    p->max_color = max_color;
    p->data = malloc(width * height * sizeof(unsigned char));
    if (!p->data) {
        free(p);
        return NULL;
    }
    return p;
}

void destroy_pixel_art(PixelArt *p) {
    if (p) {
        free(p->data);
        free(p);
    }
}

void set_pixel(PixelArt *p, int x, int y, unsigned char color) {
    if (x >= 0 && x < p->width && y >= 0 && y < p->height) {
        p->data[y * p->width + x] = color;
    }
}

unsigned char get_pixel(PixelArt *p, int x, int y) {
    if (x >= 0 && x < p->width && y >= 0 && y < p->height) {
        return p->data[y * p->width + x];
    }
    return 0;
}

void save_pixel_art(PixelArt *p, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        return;
    }
    fprintf(fp, "P5\n%d %d\n%d\n", p->width, p->height, p->max_color);
    fwrite(p->data, 1, p->width * p->height, fp);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <width> <height> <max_color> <filename>\n", argv[0]);
        return 1;
    }
    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    int max_color = atoi(argv[3]);
    PixelArt *p = create_pixel_art(width, height, max_color);
    if (!p) {
        fprintf(stderr, "Error: could not create pixel art\n");
        return 1;
    }
    // Draw a circle
    for (int y = 0; y < p->height; y++) {
        for (int x = 0; x < p->width; x++) {
            int dx = x - p->width / 2;
            int dy = y - p->height / 2;
            if (dx * dx + dy * dy <= p->width * p->height / 4) {
                set_pixel(p, x, y, 255);
            }
        }
    }
    // Save the pixel art
    save_pixel_art(p, argv[4]);
    // Destroy the pixel art
    destroy_pixel_art(p);
    return 0;
}