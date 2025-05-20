//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    unsigned char r, g, b;
} pixel;

pixel **image;
int width, height;

void load_image(char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        perror("Error opening file");
        exit(1);
    }

    // Read header
    fread(&width, sizeof(int), 1, f);
    fread(&height, sizeof(int), 1, f);

    // Allocate memory for image
    image = malloc(height * sizeof(pixel *));
    for (int i = 0; i < height; i++) {
        image[i] = malloc(width * sizeof(pixel));
    }

    // Read image data
    fread(image[0], sizeof(pixel), width * height, f);

    fclose(f);
}

void save_image(char *filename) {
    FILE *f = fopen(filename, "wb");
    if (!f) {
        perror("Error opening file");
        exit(1);
    }

    // Write header
    fwrite(&width, sizeof(int), 1, f);
    fwrite(&height, sizeof(int), 1, f);

    // Write image data
    fwrite(image[0], sizeof(pixel), width * height, f);

    fclose(f);
}

void flip_image_horizontal() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            pixel temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}

void flip_image_vertical() {
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            pixel temp = image[i][j];
            image[i][j] = image[height - i - 1][j];
            image[height - i - 1][j] = temp;
        }
    }
}

void adjust_brightness(int brightness) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j].r = fmin(255, image[i][j].r + brightness);
            image[i][j].g = fmin(255, image[i][j].g + brightness);
            image[i][j].b = fmin(255, image[i][j].b + brightness);
        }
    }
}

void adjust_contrast(float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j].r = fmin(255, image[i][j].r * factor);
            image[i][j].g = fmin(255, image[i][j].g * factor);
            image[i][j].b = fmin(255, image[i][j].b * factor);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_image> <output_image>\n", argv[0]);
        return 1;
    }

    load_image(argv[1]);

    // Flip image horizontally
    flip_image_horizontal();

    // Adjust brightness
    adjust_brightness(50);

    // Adjust contrast
    adjust_contrast(1.5);

    // Save image
    save_image(argv[2]);

    return 0;
}