//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXEL_VALUE 255

// Function to flip an image along the vertical axis
void flipVertical(int width, int height, int image[height][width]) {
    int temp;

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height / 2; y++) {
            temp = image[y][x];
            image[y][x] = image[height - y - 1][x];
            image[height - y - 1][x] = temp;
        }
    }
}

// Function to adjust the brightness of an image
void adjustBrightness(int width, int height, int image[height][width], int delta) {
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            image[y][x] += delta;

            // Clamp values to ensure they remain between 0 and MAX_PIXEL_VALUE
            if (image[y][x] < 0) {
                image[y][x] = 0;
            } else if (image[y][x] > MAX_PIXEL_VALUE) {
                image[y][x] = MAX_PIXEL_VALUE;
            }
        }
    }
}

// Function to adjust the contrast of an image
void adjustContrast(int width, int height, int image[height][width], float delta) {
    float factor = (259.0f * (delta + 255.0f)) / (255.0f * (259.0f - delta));

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            image[y][x] = (int) (factor * (image[y][x] - 128) + 128);

            // Clamp values to ensure they remain between 0 and MAX_PIXEL_VALUE
            if (image[y][x] < 0) {
                image[y][x] = 0;
            } else if (image[y][x] > MAX_PIXEL_VALUE) {
                image[y][x] = MAX_PIXEL_VALUE;
            }
        }
    }
}

int main() {
    // Sample image array
    int image[4][3] = {
        {255, 0, 128},
        {64, 192, 32},
        {96, 224, 160},
        {32, 16, 255}
    };

    // Display original image
    printf("Original image:\n");
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 3; x++) {
            printf("%3d ", image[y][x]);
        }
        printf("\n");
    }
    printf("\n");

    // Flip image vertically and display result
    flipVertical(3, 4, image);
    printf("Image flipped vertically:\n");
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 3; x++) {
            printf("%3d ", image[y][x]);
        }
        printf("\n");
    }
    printf("\n");

    // Adjust brightness of image by +50 and display result
    adjustBrightness(3, 4, image, 50);
    printf("Image with increased brightness:\n");
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 3; x++) {
            printf("%3d ", image[y][x]);
        }
        printf("\n");
    }
    printf("\n");

    // Adjust contrast of image by a factor of 1.5 and display result
    adjustContrast(3, 4, image, 50);
    printf("Image with increased contrast:\n");
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 3; x++) {
            printf("%3d ", image[y][x]);
        }
        printf("\n");
    }

    return 0;
}