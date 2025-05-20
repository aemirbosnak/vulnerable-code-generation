//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_BRIGHTNESS 255

void flip_horizontal(int height, int width, unsigned char image[height][width]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            unsigned char temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}

void flip_vertical(int height, int width, unsigned char image[height][width]) {
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char temp = image[i][j];
            image[i][j] = image[height - i - 1][j];
            image[height - i - 1][j] = temp;
        }
    }
}

void change_brightness(int height, int width, unsigned char image[height][width], int brightness) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int new_value = (int) image[i][j] + brightness;
            if (new_value < 0) {
                new_value = 0;
            } else if (new_value > MAX_BRIGHTNESS) {
                new_value = MAX_BRIGHTNESS;
            }
            image[i][j] = (unsigned char) new_value;
        }
    }
}

void change_contrast(int height, int width, unsigned char image[height][width], float contrast) {
    float factor = (259.0f * (contrast + 255.0f)) / (255.0f * (259.0f - contrast));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int new_value = (int) (factor * (image[i][j] - 128) + 128);
            if (new_value < 0) {
                new_value = 0;
            } else if (new_value > MAX_BRIGHTNESS) {
                new_value = MAX_BRIGHTNESS;
            }
            image[i][j] = (unsigned char) new_value;
        }
    }
}

int main() {
    // Simple example image with 3x5 pixels
    unsigned char example_image[3][5] = {
            {100, 200, 50,  120, 180},
            {20,  80,  150, 70,  30},
            {210, 50,  190, 120, 100}
    };

    printf("Original image:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d\t", example_image[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    flip_horizontal(3, 5, example_image);

    printf("Image after horizontal flip:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d\t", example_image[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    flip_vertical(3, 5, example_image);

    printf("Image after vertical flip:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d\t", example_image[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    change_brightness(3, 5, example_image, 50);

    printf("Image after brightness change (+50):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d\t", example_image[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    change_contrast(3, 5, example_image, 50.0);

    printf("Image after contrast change (+50.0):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d\t", example_image[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}