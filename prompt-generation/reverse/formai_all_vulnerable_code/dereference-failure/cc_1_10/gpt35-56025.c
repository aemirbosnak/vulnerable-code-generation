//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10
#define PIXEL_SIZE 3

// Define RGB colors
#define BLACK 0
#define WHITE 255
#define RED 255, 0, 0
#define GREEN 0, 255, 0
#define BLUE 0, 0, 255

// Define a structure to represent a single pixel
struct Pixel {
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

// Helper function to set a pixel to a specific color
void set_pixel(struct Pixel* pixels, int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        struct Pixel* p = pixels + (y * WIDTH + x) * PIXEL_SIZE;
        p->r = r;
        p->g = g;
        p->b = b;
    }
}

// Helper function to draw a rectangle on the screen
void draw_rect(struct Pixel* pixels, int x, int y, int w, int h, unsigned char r, unsigned char g, unsigned char b) {
    for (int i = x; i < x + w; ++i) {
        for (int j = y; j < y + h; ++j) {
            set_pixel(pixels, i, j, r, g, b);
        }
    }
}

int main() {
    // Create a buffer to hold the pixels
    struct Pixel* pixels = malloc(WIDTH * HEIGHT * PIXEL_SIZE);

    if (!pixels) {
        printf("Error: Could not allocate memory\n");
        return -1;
    }

    // Initialize the pixels to white
    for (int i = 0; i < WIDTH * HEIGHT; ++i) {
        pixels[i].r = WHITE;
        pixels[i].g = WHITE;
        pixels[i].b = WHITE;
    }

    // Draw a rectangle
    draw_rect(pixels, 2, 2, 6, 6, RED);

    // Output the pixels to a file
    FILE* fp = fopen("output.ppm", "wb");

    if (!fp) {
        printf("Error: Could not open output file\n");
        return -1;
    }

    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);

    for (int i = 0; i < WIDTH * HEIGHT; ++i) {
        fwrite(&pixels[i].r, 1, 1, fp);
        fwrite(&pixels[i].g, 1, 1, fp);
        fwrite(&pixels[i].b, 1, 1, fp);
    }

    fclose(fp);

    // Free the memory
    free(pixels);

    return 0;
}