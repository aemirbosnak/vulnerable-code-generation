//MISTRAL-7B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512

typedef struct {
    float r, g, b;
} pixel;

void transpose(pixel **matrix, int width, int height) {
    int i, j;
    pixel temp;

    for (i = 0; i < height; i++) {
        for (j = i + 1; j < width; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

void apply_transform(pixel **matrix, int width, int height, float contrast, float brightness) {
    int i, j;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            matrix[i][j].r = pow(matrix[i][j].r * contrast + brightness, 1.0 / 2.2);
            matrix[i][j].g = pow(matrix[i][j].g * contrast + brightness, 1.0 / 2.2);
            matrix[i][j].b = pow(matrix[i][j].b * contrast + brightness, 1.0 / 2.2);
        }
    }
}

int main() {
    pixel **image;
    float contrast = 1.5, brightness = 50;

    image = malloc(WIDTH * sizeof(pixel *));
    for (int i = 0; i < HEIGHT; i++) {
        image[i] = malloc(WIDTH * sizeof(pixel));
    }

    // Initialize image here...

    // Flip the image
    transpose(image, WIDTH, HEIGHT);

    // Apply brightness and contrast
    apply_transform(image, WIDTH, HEIGHT, contrast, brightness);

    // Free memory
    for (int i = 0; i < HEIGHT; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}