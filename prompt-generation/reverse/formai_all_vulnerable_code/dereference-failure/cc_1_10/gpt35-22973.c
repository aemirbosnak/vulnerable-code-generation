//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

// Define the structure for image
typedef struct {
    int width;
    int height;
    unsigned char* pixels;
} Image;

// Function to create an empty image
Image* create_image(int width, int height) {
    Image* img = (Image*) malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->pixels = (unsigned char*) malloc(width * height * sizeof(unsigned char));
    return img;
}

// Function to read image from file
Image* read_image(char* filename) {
    FILE* in = fopen(filename, "rb");
    int width, height;
    char magic[MAX_LINE_LENGTH];
    fscanf(in, "%s\n%d %d\n255\n", magic, &width, &height);
    Image* img = create_image(width, height);
    fread(img->pixels, sizeof(unsigned char), width * height, in);
    fclose(in);
    return img;
}

// Function to save image to file
void save_image(Image* img, char* filename) {
    FILE* out = fopen(filename, "wb");
    fprintf(out, "P5\n%d %d\n255\n", img->width, img->height);
    fwrite(img->pixels, sizeof(unsigned char), img->width * img->height, out);
    fclose(out);
}

// Function to flip image horizontally
void flip_horizontal(Image* img) {
    unsigned char* temp = (unsigned char*) malloc(img->width * sizeof(unsigned char));
    int i, j;
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width / 2; j++) {
            temp[j] = img->pixels[i * img->width + j];
            img->pixels[i * img->width + j] = img->pixels[i * img->width + img->width - j - 1];
            img->pixels[i * img->width + img->width - j - 1] = temp[j];
        }
    }
    free(temp);
}

// Function to adjust brightness and contrast of image
void adjust_brightness_contrast(Image* img, int brightness, int contrast) {
    int i;
    for (i = 0; i < img->width * img->height; i++) {
        int pixel = img->pixels[i];
        pixel = pixel * (100 + contrast) / 100;
        pixel += brightness;
        if (pixel < 0) {
            pixel = 0;
        } else if (pixel > 255) {
            pixel = 255;
        }
        img->pixels[i] = (unsigned char) pixel;
    }
}

int main() {
    // Read image from file
    Image* img = read_image("input.pgm");

    // Flip image horizontally
    flip_horizontal(img);

    // Adjust brightness and contrast of image
    adjust_brightness_contrast(img, 50, 20);

    // Save image to file
    save_image(img, "output.pgm");

    // Free memory
    free(img->pixels);
    free(img);

    return 0;
}