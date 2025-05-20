//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: satisfied
#include <stdio.h>

// Function to flip the image horizontally
void flip_horizontal(int width, int height, int image[width][height]) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            int temp = image[x][y];
            image[x][y] = image[width - x - 1][y];
            image[width - x - 1][y] = temp;
        }
    }
}

// Function to adjust the brightness of the image
void adjust_brightness(int width, int height, int image[width][height], int brightness) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            image[x][y] += brightness;
            if (image[x][y] < 0) {
                image[x][y] = 0;
            } else if (image[x][y] > 255) {
                image[x][y] = 255;
            }
        }
    }
}

// Function to adjust the contrast of the image
void adjust_contrast(int width, int height, int image[width][height], float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            image[x][y] = (int)(factor * (image[x][y] - 128) + 128);
            if (image[x][y] < 0) {
                image[x][y] = 0;
            } else if (image[x][y] > 255) {
                image[x][y] = 255;
            }
        }
    }
}

int main() {
    int width = 5;
    int height = 5;
    int image[5][5] = {
        {255, 255, 255, 255, 255},
        {255, 255, 128, 255, 255},
        {255, 128, 0, 128, 255},
        {255, 255, 128, 255, 255},
        {255, 255, 255, 255, 255}
    };

    printf("Original image:\n");
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%-3d ", image[x][y]);
        }
        printf("\n");
      }
    
    flip_horizontal(width, height, image);
    
    printf("\nImage after flipping horizontally:\n");
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%-3d ", image[x][y]);
        }
        printf("\n");
      }
    
    adjust_brightness(width, height, image, -30);

    printf("\nImage after reducing brightness:\n");
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%-3d ", image[x][y]);
        }
        printf("\n");
      }

    adjust_contrast(width, height, image, 50);

    printf("\nImage after increasing contrast:\n");
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%-3d ", image[x][y]);
        }
        printf("\n");
      }

    return 0;
}