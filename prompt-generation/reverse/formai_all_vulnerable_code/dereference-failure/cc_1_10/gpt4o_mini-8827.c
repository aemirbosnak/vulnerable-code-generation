//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel* pixels;
} Image;

// Function to create an image with given dimensions
Image* createImage(int width, int height) {
    Image* img = (Image*)malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->pixels = (Pixel*)malloc(sizeof(Pixel) * width * height);
    return img;
}

// Function to flip the image horizontally
void flipImageHorizontally(Image* img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            int oppositeX = img->width - 1 - x;
            Pixel temp = img->pixels[y * img->width + x];
            img->pixels[y * img->width + x] = img->pixels[y * img->width + oppositeX];
            img->pixels[y * img->width + oppositeX] = temp;
        }
    }
}

// Function to change brightness of the image
void changeBrightness(Image* img, int value) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->pixels[i].r = fmin(fmax(img->pixels[i].r + value, 0), 255);
        img->pixels[i].g = fmin(fmax(img->pixels[i].g + value, 0), 255);
        img->pixels[i].b = fmin(fmax(img->pixels[i].b + value, 0), 255);
    }
}

// Function to change contrast of the image
void changeContrast(Image* img, float factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->pixels[i].r = fmin(fmax((img->pixels[i].r - 128) * factor + 128, 0), 255);
        img->pixels[i].g = fmin(fmax((img->pixels[i].g - 128) * factor + 128, 0), 255);
        img->pixels[i].b = fmin(fmax((img->pixels[i].b - 128) * factor + 128, 0), 255);
    }
}

// Function to free the memory allocated for the image
void freeImage(Image* img) {
    free(img->pixels);
    free(img);
}

// Function to simulate loading an image (dummy values)
Image* loadImage(const char* filename) {
    // For simplicity, generating a dummy image with a gradient
    int width = 256, height = 256;
    Image* img = createImage(width, height);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            img->pixels[y * width + x].r = x;
            img->pixels[y * width + x].g = y;
            img->pixels[y * width + x].b = (x + y) / 2;
        }
    }
    return img;
}

// Function to save an image to a file (dummy implementation)
void saveImage(const char* filename, Image* img) {
    printf("Saving image (%dx%d) to %s\n", img->width, img->height, filename);
}

// Main function to perform image processing tasks
int main() {
    const char* inputFile = "input.bmp";
    const char* outputFile = "output.bmp";

    Image* img = loadImage(inputFile);
    printf("Loaded image of size %dx%d.\n", img->width, img->height);

    flipImageHorizontally(img);
    printf("Image flipped horizontally.\n");

    changeBrightness(img, 50);
    printf("Increased the brightness by 50.\n");

    changeContrast(img, 1.2); // Enhance contrast by 20%
    printf("Increased contrast by a factor of 1.2.\n");

    saveImage(outputFile, img);

    freeImage(img);
    return 0;
}