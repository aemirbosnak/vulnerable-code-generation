//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Image struct
typedef struct {
    int** pixels;
    int width;
    int height;
} Image;

// Function prototypes
Image* createImage(int width, int height);
void destroyImage(Image* img);
void flipImage(Image* img, char direction);
void adjustBrightness(Image* img, int value);
void adjustContrast(Image* img, float value);

int main() {
    // Initialize image
    Image* img = createImage(4, 4);

    // Fill with test pixels
    img->pixels[0][0] = 255;
    img->pixels[0][1] = 200;
    img->pixels[0][2] = 150;
    img->pixels[0][3] = 100;
    img->pixels[1][0] = 220;
    img->pixels[1][1] = 170;
    img->pixels[1][2] = 90;
    img->pixels[1][3] = 60;
    img->pixels[2][0] = 180;
    img->pixels[2][1] = 130;
    img->pixels[2][2] = 40;
    img->pixels[2][3] = 20;
    img->pixels[3][0] = 100;
    img->pixels[3][1] = 75;
    img->pixels[3][2] = 30;
    img->pixels[3][3] = 10;

    // Print original image
    printf("Original Image:\n");
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            printf("%d ", img->pixels[i][j]);
        }
        printf("\n");
    }

    // Flip image horizontally
    flipImage(img, 'h');

    // Print horizontally flipped image
    printf("\nHorizontally Flipped Image:\n");
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            printf("%d ", img->pixels[i][j]);
        }
        printf("\n");
    }

    // Flip image vertically
    flipImage(img, 'v');

    // Print vertically flipped image
    printf("\nVertically Flipped Image:\n");
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            printf("%d ", img->pixels[i][j]);
        }
        printf("\n");
    }

    // Adjust brightness by 50
    adjustBrightness(img, 50);

    // Print brightness adjusted image
    printf("\nBrightness Adjusted Image (+50):\n");
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            printf("%d ", img->pixels[i][j]);
        }
        printf("\n");
    }

    // Adjust contrast by 50%
    adjustContrast(img, 0.5);

    // Print contrast adjusted image
    printf("\nContrast Adjusted Image (+50%%):\n");
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            printf("%d ", img->pixels[i][j]);
        }
        printf("\n");
    }

    // Cleanup
    destroyImage(img);

    return 0;
}

// Create new image with given dimensions
Image* createImage(int width, int height) {
    // Allocate space for image and pixel array
    Image* img = malloc(sizeof(Image));
    img->pixels = malloc(sizeof(int*) * height);
    for (int i = 0; i < height; i++) {
        img->pixels[i] = malloc(sizeof(int) * width);
    }

    // Set width and height
    img->width = width;
    img->height = height;

    return img;
}

// Free memory used by image
void destroyImage(Image* img) {
    for (int i = 0; i < img->height; i++) {
        free(img->pixels[i]);
    }
    free(img->pixels);
    free(img);
}

// Flip image in given direction
void flipImage(Image* img, char direction) {
    if (tolower(direction) == 'h') {
        // Flip horizontally
        for (int i = 0; i < img->height; i++) {
            for (int j = 0; j < img->width / 2; j++) {
                // Swap pixels
                int temp = img->pixels[i][j];
                img->pixels[i][j] = img->pixels[i][img->width - j - 1];
                img->pixels[i][img->width - j - 1] = temp;
            }
        }
    } else if (tolower(direction) == 'v') {
        // Flip vertically
        for (int i = 0; i < img->height / 2; i++) {
            for (int j = 0; j < img->width; j++) {
                // Swap pixels
                int temp = img->pixels[i][j];
                img->pixels[i][j] = img->pixels[img->height - i - 1][j];
                img->pixels[img->height - i - 1][j] = temp;
            }
        }
    } else {
        // Invalid direction
        printf("Invalid direction: %c\n", direction);
    }
}

// Adjust brightness of image by given value
void adjustBrightness(Image* img, int value) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->pixels[i][j] += value;
            // Make sure values stay within 0-255 range
            if (img->pixels[i][j] > 255) {
                img->pixels[i][j] = 255;
            } else if (img->pixels[i][j] < 0) {
                img->pixels[i][j] = 0;
            }
        }
    }
}

// Adjust contrast of image by given value
void adjustContrast(Image* img, float value) {
    float factor = (259.0 * (value + 255.0)) / (255.0 * (259.0 - value));
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->pixels[i][j] = factor * (img->pixels[i][j] - 128) + 128;
            // Make sure values stay within 0-255 range
            if (img->pixels[i][j] > 255) {
                img->pixels[i][j] = 255;
            } else if (img->pixels[i][j] < 0) {
                img->pixels[i][j] = 0;
            }
        }
    }
}