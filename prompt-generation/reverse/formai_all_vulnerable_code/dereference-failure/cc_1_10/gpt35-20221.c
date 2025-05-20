//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Define the image structure
typedef struct {
    int height;
    int width;
    int *data;
} Image;

// Function to print image to console
void print_image(Image img) {
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            printf("%d ", img.data[i * img.width + j]);
        }
        printf("\n");
    }
}

// Function to flip an image horizontally
Image flip_horizontal(Image img) {
    Image result = {img.height, img.width, malloc(sizeof(int) * img.height * img.width)};
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            result.data[i * img.width + j] = img.data[i * img.width + img.width - j - 1];
        }
    }
    return result;
}

// Function to adjust the brightness of an image
Image adjust_brightness(Image img, int amount) {
    Image result = {img.height, img.width, malloc(sizeof(int) * img.height * img.width)};
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            int pixel_value = img.data[i * img.width + j];
            pixel_value += amount;
            if (pixel_value < 0) {
                pixel_value = 0;
            } else if (pixel_value > 255) {
                pixel_value = 255;
            }
            result.data[i * img.width + j] = pixel_value;
        }
    }
    return result;
}

// Function to adjust the contrast of an image
Image adjust_contrast(Image img, float factor) {
    Image result = {img.height, img.width, malloc(sizeof(int) * img.height * img.width)};
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            int pixel_value = img.data[i * img.width + j];
            pixel_value = (pixel_value - 128) * factor + 128;
            if (pixel_value < 0) {
                pixel_value = 0;
            } else if (pixel_value > 255) {
                pixel_value = 255;
            }
            result.data[i * img.width + j] = pixel_value;
        }
    }
    return result;
}

int main() {
    // Define sample image data
    int data[] = {
        150, 150, 100, 255,
        200, 200, 50, 255,
        100, 100, 150, 255,
        255, 255, 255, 255,
    };
    int height = 4;
    int width = 4;
    Image img = {height, width, data};

    // Print the original image
    printf("Original Image:\n");
    print_image(img);
    printf("\n");

    // Flip the image horizontally and print it
    printf("Horizontal Flip:\n");
    Image flipped = flip_horizontal(img);
    print_image(flipped);
    printf("\n");
    free(flipped.data);

    // Adjust the brightness of the image and print it
    printf("Brightness Increase by 50:\n");
    Image bright = adjust_brightness(img, 50);
    print_image(bright);
    printf("\n");
    free(bright.data);

    // Adjust the contrast of the image and print it
    printf("Contrast Increase by 50%%:\n");
    Image contrast = adjust_contrast(img, 1.5);
    print_image(contrast);
    printf("\n");
    free(contrast.data);

    return 0;
}