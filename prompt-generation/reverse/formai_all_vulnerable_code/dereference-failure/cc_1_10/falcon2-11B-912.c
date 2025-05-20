//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: enthusiastic
#include <stdio.h>

typedef struct Pixel {
    int r;
    int g;
    int b;
} Pixel;

Pixel *createPixel(int red, int green, int blue);
void drawPixel(Pixel *pixel);
void writeImage(Pixel *pixels, int width, int height);
void readImage(Pixel **pixels, int *width, int *height);
void displayImage(Pixel *pixels, int width, int height);

int main() {
    Pixel *pixels = NULL;
    int width = 640;
    int height = 480;

    // Create an empty image
    pixels = createPixel(0, 0, 0);

    // Fill the image with a solid color
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Pixel *pixel = &pixels[y * width + x];
            pixel->r = pixel->g = pixel->b = 0xff;
            drawPixel(pixel);
        }
    }

    // Save the image to a file
    writeImage(pixels, width, height);

    // Read the image back from a file
    readImage(&pixels, &width, &height);

    // Display the image on the screen
    displayImage(pixels, width, height);

    return 0;
}

Pixel *createPixel(int red, int green, int blue) {
    Pixel *pixel = malloc(sizeof(Pixel));
    if (pixel == NULL) {
        printf("Error allocating memory for pixel\n");
        return NULL;
    }
    pixel->r = red;
    pixel->g = green;
    pixel->b = blue;
    return pixel;
}

void drawPixel(Pixel *pixel) {
    printf("(%d, %d, %d)\n", pixel->r, pixel->g, pixel->b);
}

void writeImage(Pixel *pixels, int width, int height) {
    FILE *fp = fopen("image.png", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Pixel *pixel = &pixels[y * width + x];
            fprintf(fp, "%d %d %d\n", pixel->r, pixel->g, pixel->b);
        }
    }
    fclose(fp);
}

void readImage(Pixel **pixels, int *width, int *height) {
    *width = 640;
    *height = 480;

    Pixel *pixel = NULL;
    for (int y = 0; y < *height; y++) {
        for (int x = 0; x < *width; x++) {
            pixel = createPixel(0, 0, 0);
            if (pixel == NULL) {
                printf("Error allocating memory for pixel\n");
                return;
            }
            fscanf(stdin, "%d %d %d\n", &pixel->r, &pixel->g, &pixel->b);
            pixels[y * *width + x] = pixel;
        }
    }
}

void displayImage(Pixel *pixels, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Pixel *pixel = &pixels[y * width + x];
            drawPixel(pixel);
        }
    }
}