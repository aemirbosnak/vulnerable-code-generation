//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a pixel
typedef struct {
    unsigned char r;  // Red component
    unsigned char g;  // Green component
    unsigned char b;  // Blue component
} pixel;

// Structure to represent an image
typedef struct {
    int width;      // Width of the image in pixels
    int height;     // Height of the image in pixels
    pixel* pixels;  // Array of pixels
} image;

// Function to create a new image
image* create_image(int width, int height) {
    image* img = (image*)malloc(sizeof(image));
    img->width = width;
    img->height = height;
    img->pixels = (pixel*)malloc(width * height * sizeof(pixel));
    return img;
}

// Function to set the color of a pixel
void set_pixel(image* img, int x, int y, pixel color) {
    if (x >= 0 && x < img->width && y >= 0 && y < img->height) {
        img->pixels[y * img->width + x] = color;
    }
}

// Function to save the image to a PPM file
void save_image(image* img, char* filename) {
    FILE* fp = fopen(filename, "wb");
    fprintf(fp, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->pixels, sizeof(pixel), img->width * img->height, fp);
    fclose(fp);
}

// Main function
int main() {
    // Create a new image
    image* img = create_image(500, 500);

    // Set the color of some pixels
    pixel white = {255, 255, 255};
    pixel black = {0, 0, 0};
    pixel red = {255, 0, 0};
    pixel green = {0, 255, 0};
    pixel blue = {0, 0, 255};

    for (int i = 0; i < img->width; i++) {
        for (int j = 0; j < img->height; j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                set_pixel(img, i, j, white);
            } else if (i % 2 == 1 && j % 2 == 1) {
                set_pixel(img, i, j, black);
            } else if (i % 2 == 0 && j % 2 == 1) {
                set_pixel(img, i, j, red);
            } else if (i % 2 == 1 && j % 2 == 0) {
                set_pixel(img, i, j, green);
            } else {
                set_pixel(img, i, j, blue);
            }
        }
    }

    // Save the image to a file
    save_image(img, "pixel-art.ppm");

    // Free the memory allocated for the image
    free(img->pixels);
    free(img);

    return 0;
}