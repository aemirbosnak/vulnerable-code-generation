//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char red, green, blue;
} pixel;

typedef struct {
    int width, height;
    pixel *data;
} image;

// Function to flip image horizontally
void flip_horizontal(image *img) {
    int width = img->width;
    int height = img->height;
    pixel temp;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width / 2; col++) {
            temp = img->data[row * width + col];
            img->data[row * width + col] = img->data[row * width + (width - col - 1)];
            img->data[row * width + (width - col - 1)] = temp;
        }
    }
}

// Function to adjust image brightness
void adjust_brightness(image *img, int value) {
    int width = img->width;
    int height = img->height;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            img->data[row * width + col].red += value;
            img->data[row * width + col].green += value;
            img->data[row * width + col].blue += value;
        }
    }
}

// Function to adjust image contrast
void adjust_contrast(image *img, int value) {
    int width = img->width;
    int height = img->height;
    float factor = ((float)259 * (value + 255)) / ((float)255 * (259 - value));

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            img->data[row * width + col].red = (unsigned char)clamp((int)((factor * (img->data[row * width + col].red - 128)) + 128), 0, 255);
            img->data[row * width + col].green = (unsigned char)clamp((int)((factor * (img->data[row * width + col].green - 128)) + 128), 0, 255);
            img->data[row * width + col].blue = (unsigned char)clamp((int)((factor * (img->data[row * width + col].blue - 128)) + 128), 0, 255);
        }
    }
}

// Helper function to clamp values
int clamp(int value, int min, int max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

// Main function
int main() {
    // Load image data (in this case, simple 4x3 image)
    image img;
    img.width = 4;
    img.height = 3;
    img.data = (pixel *)malloc(img.width * img.height * sizeof(pixel));
    img.data[0] = (pixel){255, 0, 0};
    img.data[1] = (pixel){0, 255, 0};
    img.data[2] = (pixel){0, 0, 255};
    img.data[3] = (pixel){0, 0, 0};
    img.data[4] = (pixel){255, 255, 255};
    img.data[5] = (pixel){128, 128, 128};
    img.data[6] = (pixel){255, 128, 0};
    img.data[7] = (pixel){255, 255, 0};
    img.data[8] = (pixel){0, 255, 255};
    img.data[9] = (pixel){255, 0, 255};
    img.data[10] = (pixel){128, 0, 128};
    img.data[11] = (pixel){128, 128, 0};

    // Flip the image horizontally
    flip_horizontal(&img);

    // Adjust the image brightness by a value of 50
    adjust_brightness(&img, 50);

    // Adjust the image contrast by a value of 50
    adjust_contrast(&img, 50);

    // Print out the modified image data
    for (int row = 0; row < img.height; row++) {
        for (int col = 0; col < img.width; col++) {
            printf("(%d, %d, %d) ", img.data[row * img.width + col].red, img.data[row * img.width + col].green, img.data[row * img.width + col].blue);
        }
        printf("\n");
    }

    return 0;
}