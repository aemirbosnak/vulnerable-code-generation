//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum width and height of the pixel art
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Define the colors that can be used in the pixel art
#define COLOR_BLACK 0
#define COLOR_WHITE 255

// Define the structure of a pixel
typedef struct {
    unsigned char r, g, b;
} Pixel;

// Define the structure of a pixel art image
typedef struct {
    int width, height;
    Pixel pixels[MAX_WIDTH][MAX_HEIGHT];
} Image;

// Create a new pixel art image
Image *create_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            image->pixels[i][j].r = COLOR_BLACK;
            image->pixels[i][j].g = COLOR_BLACK;
            image->pixels[i][j].b = COLOR_BLACK;
        }
    }
    return image;
}

// Free the memory allocated for a pixel art image
void free_image(Image *image) {
    free(image);
}

// Set the color of a pixel in a pixel art image
void set_pixel(Image *image, int x, int y, Pixel color) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return;
    }
    image->pixels[x][y] = color;
}

// Get the color of a pixel in a pixel art image
Pixel get_pixel(Image *image, int x, int y) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return (Pixel) {0, 0, 0};
    }
    return image->pixels[x][y];
}

// Load a pixel art image from a file
Image *load_image(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return NULL;
    }

    // Read the header of the file
    int width, height;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);

    // Create a new pixel art image
    Image *image = create_image(width, height);

    // Read the pixels from the file
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            fread(&image->pixels[i][j], sizeof(Pixel), 1, file);
        }
    }

    // Close the file
    fclose(file);

    return image;
}

// Save a pixel art image to a file
void save_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        return;
    }

    // Write the header of the file
    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);

    // Write the pixels to the file
    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height; j++) {
            fwrite(&image->pixels[i][j], sizeof(Pixel), 1, file);
        }
    }

    // Close the file
    fclose(file);
}

// Print a pixel art image to the console
void print_image(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            Pixel pixel = get_pixel(image, j, i);
            printf("%c", pixel.r == COLOR_BLACK ? ' ' : '*');
        }
        printf("\n");
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user provided a filename
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Load the pixel art image from the file
    Image *image = load_image(argv[1]);
    if (image == NULL) {
        printf("Error: could not load image from file\n");
        return 1;
    }

    // Print the pixel art image to the console
    print_image(image);

    // Free the memory allocated for the pixel art image
    free_image(image);

    return 0;
}