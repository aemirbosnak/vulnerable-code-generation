//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define some colors for fun!
#define BLACK   0
#define WHITE   1
#define RED     2
#define GREEN   3
#define BLUE    4
#define YELLOW  5
#define MAGENTA 6
#define CYAN    7

// Define the maximum width and height of the image
#define MAX_WIDTH  100
#define MAX_HEIGHT 100

// Define the image data structure
typedef struct {
    int width;
    int height;
    unsigned char data[MAX_WIDTH * MAX_HEIGHT];
} image;

// Create a new image
image *new_image(int width, int height) {
    image *img = malloc(sizeof(image));
    if (img == NULL) {
        return NULL;
    }
    img->width = width;
    img->height = height;
    memset(img->data, WHITE, width * height);
    return img;
}

// Free the memory allocated for the image
void free_image(image *img) {
    free(img);
}

// Set the pixel at the given coordinates to the given color
void set_pixel(image *img, int x, int y, int color) {
    if (x < 0 || x >= img->width || y < 0 || y >= img->height) {
        return;
    }
    img->data[y * img->width + x] = color;
}

// Get the pixel at the given coordinates
int get_pixel(image *img, int x, int y) {
    if (x < 0 || x >= img->width || y < 0 || y >= img->height) {
        return -1;
    }
    return img->data[y * img->width + x];
}

// Save the image to a file
void save_image(image *img, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        return;
    }
    fwrite(img->data, 1, img->width * img->height, file);
    fclose(file);
}

// Load an image from a file
image *load_image(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return NULL;
    }
    image *img = malloc(sizeof(image));
    if (img == NULL) {
        fclose(file);
        return NULL;
    }
    fread(img->data, 1, img->width * img->height, file);
    fclose(file);
    return img;
}

// Create a new image and draw a happy face on it
image *happy_face() {
    image *img = new_image(100, 100);
    if (img == NULL) {
        return NULL;
    }

    // Draw the yellow face
    for (int y = 10; y < 90; y++) {
        for (int x = 10; x < 90; x++) {
            if ((x - 50) * (x - 50) + (y - 50) * (y - 50) <= 40 * 40) {
                set_pixel(img, x, y, YELLOW);
            }
        }
    }

    // Draw the black eyes
    for (int y = 30; y < 50; y++) {
        for (int x = 30; x < 50; x++) {
            if ((x - 40) * (x - 40) + (y - 40) * (y - 40) <= 10 * 10) {
                set_pixel(img, x, y, BLACK);
            }
        }
    }
    for (int y = 30; y < 50; y++) {
        for (int x = 60; x < 80; x++) {
            if ((x - 70) * (x - 70) + (y - 40) * (y - 40) <= 10 * 10) {
                set_pixel(img, x, y, BLACK);
            }
        }
    }

    // Draw the red mouth
    for (int y = 50; y < 70; y++) {
        for (int x = 40; x < 60; x++) {
            if ((x - 50) * (x - 50) + (y - 60) * (y - 60) <= 10 * 10) {
                set_pixel(img, x, y, RED);
            }
        }
    }

    return img;
}

// Main function
int main() {
    // Create a new image and draw a happy face on it
    image *img = happy_face();

    // Save the image to a file
    save_image(img, "happy_face.bmp");

    // Free the memory allocated for the image
    free_image(img);

    return 0;
}