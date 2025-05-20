//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Pixel art data structure
struct Pixel {
    unsigned char r, g, b;
};

// Pixel art canvas
struct Canvas {
    int width, height;
    struct Pixel **pixels;
};

// Create a new pixel art canvas
struct Canvas *canvas_new(int width, int height) {
    struct Canvas *canvas = malloc(sizeof(struct Canvas));
    canvas->width = width;
    canvas->height = height;
    canvas->pixels = malloc(sizeof(struct Pixel *) * height);
    for (int i = 0; i < height; i++) {
        canvas->pixels[i] = malloc(sizeof(struct Pixel) * width);
    }
    return canvas;
}

// Free a pixel art canvas
void canvas_free(struct Canvas *canvas) {
    for (int i = 0; i < canvas->height; i++) {
        free(canvas->pixels[i]);
    }
    free(canvas->pixels);
    free(canvas);
}

// Set a pixel on the canvas
void canvas_set_pixel(struct Canvas *canvas, int x, int y, struct Pixel pixel) {
    canvas->pixels[y][x] = pixel;
}

// Get a pixel from the canvas
struct Pixel canvas_get_pixel(struct Canvas *canvas, int x, int y) {
    return canvas->pixels[y][x];
}

// Save the pixel art to a PPM file
void canvas_save_ppm(struct Canvas *canvas, char *filename) {
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "P3\n%d %d\n255\n", canvas->width, canvas->height);
    for (int y = 0; y < canvas->height; y++) {
        for (int x = 0; x < canvas->width; x++) {
            struct Pixel pixel = canvas_get_pixel(canvas, x, y);
            fprintf(fp, "%d %d %d ", pixel.r, pixel.g, pixel.b);
        }
    }
    fclose(fp);
}

// Generate a random pixel art canvas
struct Canvas *canvas_random(int width, int height) {
    struct Canvas *canvas = canvas_new(width, height);
    for (int y = 0; y < canvas->height; y++) {
        for (int x = 0; x < canvas->width; x++) {
            struct Pixel pixel = {
                .r = rand() % 256,
                .g = rand() % 256,
                .b = rand() % 256,
            };
            canvas_set_pixel(canvas, x, y, pixel);
        }
    }
    return canvas;
}

// Generate a pixel art canvas of a smiley face
struct Canvas *canvas_smiley_face(int width, int height) {
    struct Canvas *canvas = canvas_new(width, height);
    for (int y = 0; y < canvas->height; y++) {
        for (int x = 0; x < canvas->width; x++) {
            struct Pixel pixel = {
                .r = 0,
                .g = 0,
                .b = 0,
            };
            if (y < height / 2) {
                if (x > width / 4 && x < 3 * width / 4) {
                    pixel.r = 255;
                    pixel.g = 255;
                    pixel.b = 0;
                }
            } else {
                if (x > width / 4 && x < 3 * width / 4) {
                    if (y < 3 * height / 4) {
                        pixel.r = 0;
                        pixel.g = 0;
                        pixel.b = 255;
                    } else {
                        pixel.r = 255;
                        pixel.g = 0;
                        pixel.b = 0;
                    }
                }
            }
            canvas_set_pixel(canvas, x, y, pixel);
        }
    }
    return canvas;
}

// Generate a pixel art canvas of a landscape
struct Canvas *canvas_landscape(int width, int height) {
    struct Canvas *canvas = canvas_new(width, height);
    for (int y = 0; y < canvas->height; y++) {
        for (int x = 0; x < canvas->width; x++) {
            struct Pixel pixel = {
                .r = 0,
                .g = 0,
                .b = 0,
            };
            if (y < height / 2) {
                pixel.r = 0;
                pixel.g = 255;
                pixel.b = 0;
            } else {
                pixel.r = 128;
                pixel.g = 128;
                pixel.b = 128;
            }
            canvas_set_pixel(canvas, x, y, pixel);
        }
    }
    return canvas;
}

// Generate a pixel art canvas of a sunset
struct Canvas *canvas_sunset(int width, int height) {
    struct Canvas *canvas = canvas_new(width, height);
    for (int y = 0; y < canvas->height; y++) {
        for (int x = 0; x < canvas->width; x++) {
            struct Pixel pixel = {
                .r = 0,
                .g = 0,
                .b = 0,
            };
            if (y < height / 2) {
                pixel.r = 255;
                pixel.g = 165;
                pixel.b = 0;
            } else {
                pixel.r = 128;
                pixel.g = 0;
                pixel.b = 0;
            }
            canvas_set_pixel(canvas, x, y, pixel);
        }
    }
    return canvas;
}

// Main function
int main() {
    // Generate a random pixel art canvas
    struct Canvas *canvas = canvas_random(512, 512);

    // Save the pixel art to a PPM file
    canvas_save_ppm(canvas, "pixel_art.ppm");

    // Free the pixel art canvas
    canvas_free(canvas);

    return 0;
}