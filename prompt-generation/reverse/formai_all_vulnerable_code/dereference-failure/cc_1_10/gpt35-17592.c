//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

typedef struct {
    int width;
    int height;
    int pixels[MAX_WIDTH][MAX_HEIGHT];
} Image;

Image load_image(char* file_name) {
    int width, height;
    FILE* fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", file_name);
        exit(1);
    }
    fscanf(fp, "%d %d", &width, &height);
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: Image too large\n");
        exit(1);
    }
    Image image;
    image.width = width;
    image.height = height;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fscanf(fp, "%d", &image.pixels[x][y]);
        }
    }
    fclose(fp);
    return image;
}

void save_image(Image image, char* file_name) {
    FILE* fp = fopen(file_name, "w");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", file_name);
        exit(1);
    }
    fprintf(fp, "%d %d\n", image.width, image.height);
    for (int y = 0; y < image.height; y++) {
        for (int x = 0; x < image.width; x++) {
            fprintf(fp, "%d ", image.pixels[x][y]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void flip_image(Image* image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            int tmp = image->pixels[x][y];
            image->pixels[x][y] = image->pixels[image->width - x - 1][y];
            image->pixels[image->width - x - 1][y] = tmp;
        }
    }
}

void adjust_brightness(Image* image, int brightness) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            image->pixels[x][y] += brightness;
            if (image->pixels[x][y] < 0) image->pixels[x][y] = 0;
            if (image->pixels[x][y] > 255) image->pixels[x][y] = 255;
        }
    }
}

void adjust_contrast(Image* image, float contrast) {
    float factor = (259.0f * (contrast + 255.0f)) / (255.0f * (259.0f - contrast));
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            image->pixels[x][y] = factor * (image->pixels[x][y] - 128) + 128;
            if (image->pixels[x][y] < 0) image->pixels[x][y] = 0;
            if (image->pixels[x][y] > 255) image->pixels[x][y] = 255;
        }
    }
}

int main() {
    Image image = load_image("input.txt");

    // Flip the image horizontally
    flip_image(&image);

    // Adjust the brightness of the image
    adjust_brightness(&image, -50);

    // Adjust the contrast of the image
    adjust_contrast(&image, 50);

    save_image(image, "output.txt");

    return 0;
}