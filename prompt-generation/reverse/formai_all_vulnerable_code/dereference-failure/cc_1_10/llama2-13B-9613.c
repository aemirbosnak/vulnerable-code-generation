//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 480
#define BITS_PER_PIXEL 8
#define IMAGE_NAME "satisfied.bmp"

// Structure to store the image data
typedef struct {
    unsigned char pixels[WIDTH * HEIGHT * BITS_PER_PIXEL / 8];
} Image;

// Function to load the image from a file
Image load_image(const char *filename) {
    Image image;
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return image;
    }

    fread(image.pixels, 1, WIDTH * HEIGHT * BITS_PER_PIXEL / 8, file);
    fclose(file);

    return image;
}

// Function to draw a line on the image
void draw_line(Image *image, int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steep = abs(dy) > abs(dx);
    int x3 = x1;
    int y3 = y1;

    if (steep) {
        dx = 0;
        dy = abs(dy);
    }

    for (int i = 0; i < abs(dx); i++) {
        image->pixels[(y3 + dy * i) * WIDTH + x3 + dx * i] = 255;
    }
}

// Function to draw a rectangle on the image
void draw_rectangle(Image *image, int x, int y, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            image->pixels[(y + j) * WIDTH + x + i] = 255;
        }
    }
}

// Function to draw a filled rectangle on the image
void fill_rectangle(Image *image, int x, int y, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            image->pixels[(y + j) * WIDTH + x + i] = 255;
        }
    }
}

// Function to draw a text on the image
void draw_text(Image *image, int x, int y, char *text) {
    for (int i = 0; i < strlen(text); i++) {
        image->pixels[(y + i) * WIDTH + x + i] = 255;
    }
}

// Function to save the image to a file
void save_image(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    fwrite(image->pixels, 1, WIDTH * HEIGHT * BITS_PER_PIXEL / 8, file);
    fclose(file);
}

int main() {
    // Load the image
    Image image = load_image(IMAGE_NAME);

    // Draw a line on the image
    draw_line(&image, 100, 100, 200, 200);

    // Draw a filled rectangle on the image
    fill_rectangle(&image, 200, 200, 100, 50);

    // Draw some text on the image
    draw_text(&image, 300, 300, "This is a satisfied image!");

    // Save the image to a file
    save_image(&image, "satisfied_edited.bmp");

    return 0;
}