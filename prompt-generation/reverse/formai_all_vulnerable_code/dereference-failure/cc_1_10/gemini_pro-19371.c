//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: puzzling
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Define some pixel colors
typedef enum {
    BLACK,
    WHITE,
    RED,
    GREEN,
    BLUE,
    YELLOW,
    MAGENTA,
    CYAN
} Color;

// Define the image structure
typedef struct {
    unsigned int width;
    unsigned int height;
    Color *data;
} Image;

// Create a new image
Image *new_image(unsigned int width, unsigned int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * sizeof(Color));
    return image;
}

// Free an image
void free_image(Image *image) {
    free(image->data);
    free(image);
}

// Set a pixel in an image
void set_pixel(Image *image, unsigned int x, unsigned int y, Color color) {
    image->data[y * image->width + x] = color;
}

// Get a pixel from an image
Color get_pixel(Image *image, unsigned int x, unsigned int y) {
    return image->data[y * image->width + x];
}

// Invert the colors of an image
void invert_image(Image *image) {
    for (unsigned int y = 0; y < image->height; y++) {
        for (unsigned int x = 0; x < image->width; x++) {
            Color color = get_pixel(image, x, y);
            set_pixel(image, x, y, 8 - color - 1);
        }
    }
}

// Print an image to the console
void print_image(Image *image) {
    for (unsigned int y = 0; y < image->height; y++) {
        for (unsigned int x = 0; x < image->width; x++) {
            Color color = get_pixel(image, x, y);
            switch (color) {
                case BLACK:
                    printf("⬛");
                    break;
                case WHITE:
                    printf("⬜");
                    break;
                case RED:
                    printf("🟥");
                    break;
                case GREEN:
                    printf("🟩");
                    break;
                case BLUE:
                    printf("🟦");
                    break;
                case YELLOW:
                    printf("🟨");
                    break;
                case MAGENTA:
                    printf("🟪");
                    break;
                case CYAN:
                    printf("🟦");
                    break;
            }
        }
        printf("\n");
    }
}

// The main function
int main() {
    // Create a new image
    Image *image = new_image(8, 8);

    // Set the pixels of the image
    set_pixel(image, 0, 0, BLACK);
    set_pixel(image, 1, 0, BLACK);
    set_pixel(image, 2, 0, BLACK);
    set_pixel(image, 3, 0, BLACK);
    set_pixel(image, 4, 0, BLACK);
    set_pixel(image, 5, 0, BLACK);
    set_pixel(image, 6, 0, BLACK);
    set_pixel(image, 7, 0, BLACK);
    set_pixel(image, 0, 1, BLACK);
    set_pixel(image, 1, 1, WHITE);
    set_pixel(image, 2, 1, WHITE);
    set_pixel(image, 3, 1, WHITE);
    set_pixel(image, 4, 1, WHITE);
    set_pixel(image, 5, 1, WHITE);
    set_pixel(image, 6, 1, WHITE);
    set_pixel(image, 7, 1, BLACK);
    set_pixel(image, 0, 2, BLACK);
    set_pixel(image, 1, 2, WHITE);
    set_pixel(image, 2, 2, BLACK);
    set_pixel(image, 3, 2, BLACK);
    set_pixel(image, 4, 2, BLACK);
    set_pixel(image, 5, 2, BLACK);
    set_pixel(image, 6, 2, WHITE);
    set_pixel(image, 7, 2, BLACK);
    set_pixel(image, 0, 3, BLACK);
    set_pixel(image, 1, 3, WHITE);
    set_pixel(image, 2, 3, WHITE);
    set_pixel(image, 3, 3, WHITE);
    set_pixel(image, 4, 3, WHITE);
    set_pixel(image, 5, 3, WHITE);
    set_pixel(image, 6, 3, WHITE);
    set_pixel(image, 7, 3, BLACK);
    set_pixel(image, 0, 4, BLACK);
    set_pixel(image, 1, 4, WHITE);
    set_pixel(image, 2, 4, WHITE);
    set_pixel(image, 3, 4, WHITE);
    set_pixel(image, 4, 4, WHITE);
    set_pixel(image, 5, 4, WHITE);
    set_pixel(image, 6, 4, WHITE);
    set_pixel(image, 7, 4, BLACK);
    set_pixel(image, 0, 5, BLACK);
    set_pixel(image, 1, 5, WHITE);
    set_pixel(image, 2, 5, WHITE);
    set_pixel(image, 3, 5, WHITE);
    set_pixel(image, 4, 5, WHITE);
    set_pixel(image, 5, 5, WHITE);
    set_pixel(image, 6, 5, WHITE);
    set_pixel(image, 7, 5, BLACK);
    set_pixel(image, 0, 6, BLACK);
    set_pixel(image, 1, 6, WHITE);
    set_pixel(image, 2, 6, WHITE);
    set_pixel(image, 3, 6, WHITE);
    set_pixel(image, 4, 6, WHITE);
    set_pixel(image, 5, 6, WHITE);
    set_pixel(image, 6, 6, WHITE);
    set_pixel(image, 7, 6, BLACK);
    set_pixel(image, 0, 7, BLACK);
    set_pixel(image, 1, 7, BLACK);
    set_pixel(image, 2, 7, BLACK);
    set_pixel(image, 3, 7, BLACK);
    set_pixel(image, 4, 7, BLACK);
    set_pixel(image, 5, 7, BLACK);
    set_pixel(image, 6, 7, BLACK);
    set_pixel(image, 7, 7, BLACK);

    // Invert the colors of the image
    invert_image(image);

    // Print the image to the console
    print_image(image);

    // Free the image
    free_image(image);

    return 0;
}