//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Elementary, my dear Watson! Let's play with images.
typedef struct {
    int width, height;
    unsigned char *data;
} Image;

// Fetch the pixel at position (x, y)
unsigned char getPixel(Image *img, int x, int y) {
    return img->data[y * img->width + x];
}

// Set the pixel at position (x, y) to the value
void setPixel(Image *img, int x, int y, unsigned char value) {
    img->data[y * img->width + x] = value;
}

// Flip the image horizontally
void flipHorizontal(Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            unsigned char temp = getPixel(img, x, y);
            setPixel(img, x, y, getPixel(img, img->width - x - 1, y));
            setPixel(img, img->width - x - 1, y, temp);
        }
    }
}

// Flip the image vertically
void flipVertical(Image *img) {
    for (int y = 0; y < img->height / 2; y++) {
        for (int x = 0; x < img->width; x++) {
            unsigned char temp = getPixel(img, x, y);
            setPixel(img, x, y, getPixel(img, x, img->height - y - 1));
            setPixel(img, x, img->height - y - 1, temp);
        }
    }
}

// Adjust the brightness of the image
void adjustBrightness(Image *img, int delta) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int value = getPixel(img, x, y) + delta;
            if (value < 0) value = 0;
            else if (value > 255) value = 255;
            setPixel(img, x, y, value);
        }
    }
}

// Adjust the contrast of the image
void adjustContrast(Image *img, float factor) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int value = (getPixel(img, x, y) - 128) * factor + 128;
            if (value < 0) value = 0;
            else if (value > 255) value = 255;
            setPixel(img, x, y, value);
        }
    }
}

// Save the image to a file
void saveImage(Image *img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    fwrite(&img->width, sizeof(int), 1, fp);
    fwrite(&img->height, sizeof(int), 1, fp);
    fwrite(img->data, sizeof(unsigned char), img->width * img->height, fp);
    fclose(fp);
}

// Load an image from a file
Image *loadImage(char *filename) {
    FILE *fp = fopen(filename, "rb");
    Image *img = malloc(sizeof(Image));
    fread(&img->width, sizeof(int), 1, fp);
    fread(&img->height, sizeof(int), 1, fp);
    img->data = malloc(sizeof(unsigned char) * img->width * img->height);
    fread(img->data, sizeof(unsigned char), img->width * img->height, fp);
    fclose(fp);
    return img;
}

// The main function
int main() {
    // Load the image
    Image *img = loadImage("input.bmp");

    // Flip the image horizontally
    flipHorizontal(img);

    // Adjust the brightness
    adjustBrightness(img, 50);

    // Adjust the contrast
    adjustContrast(img, 1.5);

    // Save the image
    saveImage(img, "output.bmp");

    // Free the image
    free(img->data);
    free(img);

    // Watson, the modifications are complete.
    return 0;
}