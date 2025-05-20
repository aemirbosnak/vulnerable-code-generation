//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a pixel
typedef struct {
    unsigned char r, g, b;
} Pixel;

// A structure to represent a bitmap image
typedef struct {
    int width, height;
    Pixel *pixels;
} Bitmap;

// Create a new bitmap image
Bitmap *create_bitmap(int width, int height) {
    Bitmap *bitmap = malloc(sizeof(Bitmap));
    bitmap->width = width;
    bitmap->height = height;
    bitmap->pixels = malloc(sizeof(Pixel) * width * height);
    return bitmap;
}

// Set the pixel at the given coordinates
void set_pixel(Bitmap *bitmap, int x, int y, Pixel color) {
    bitmap->pixels[y * bitmap->width + x] = color;
}

// Get the pixel at the given coordinates
Pixel get_pixel(Bitmap *bitmap, int x, int y) {
    return bitmap->pixels[y * bitmap->width + x];
}

// Save the bitmap image to a file
void save_bitmap(Bitmap *bitmap, char *filename) {
    FILE *file = fopen(filename, "wb");
    fwrite(&bitmap->width, sizeof(int), 1, file);
    fwrite(&bitmap->height, sizeof(int), 1, file);
    fwrite(bitmap->pixels, sizeof(Pixel), bitmap->width * bitmap->height, file);
    fclose(file);
}

// Free the memory allocated for the bitmap image
void free_bitmap(Bitmap *bitmap) {
    free(bitmap->pixels);
    free(bitmap);
}

// Generate a random color
Pixel random_color() {
    Pixel color;
    color.r = rand() % 256;
    color.g = rand() % 256;
    color.b = rand() % 256;
    return color;
}

// Generate a random pixel art image
Bitmap *generate_pixel_art(int width, int height) {
    Bitmap *bitmap = create_bitmap(width, height);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            set_pixel(bitmap, x, y, random_color());
        }
    }

    return bitmap;
}

// Print the pixel art image to the console
void print_pixel_art(Bitmap *bitmap) {
    for (int y = 0; y < bitmap->height; y++) {
        for (int x = 0; x < bitmap->width; x++) {
            Pixel pixel = get_pixel(bitmap, x, y);
            printf("\x1b[38;2;%d;%d;%dm█", pixel.r, pixel.g, pixel.b);
        }
        printf("\n");
    }
}

int main() {
    // Generate a random pixel art image
    Bitmap *bitmap = generate_pixel_art(100, 100);

    // Print the pixel art image to the console
    print_pixel_art(bitmap);

    // Save the pixel art image to a file
    save_bitmap(bitmap, "pixel_art.bmp");

    // Free the memory allocated for the bitmap image
    free_bitmap(bitmap);

    return 0;
}