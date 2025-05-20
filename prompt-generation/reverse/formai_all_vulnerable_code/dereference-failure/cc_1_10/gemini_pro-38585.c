//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

void allocateImage(Image *image, int width, int height) {
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * sizeof(unsigned char));
}

void freeImage(Image *image) {
    free(image->data);
}

void loadImage(Image *image, char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    int width, height;
    fscanf(file, "P5\n%d %d\n255\n", &width, &height);
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * sizeof(unsigned char));
    fread(image->data, 1, width * height * sizeof(unsigned char), file);
    fclose(file);
}

void saveImage(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    fprintf(file, "P5\n%d %d\n255\n", image->width, image->height);
    fwrite(image->data, 1, image->width * image->height * sizeof(unsigned char), file);
    fclose(file);
}

void brightenImage(Image *image, int amount) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i] = fmin(255, image->data[i] + amount);
    }
}

void darkenImage(Image *image, int amount) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i] = fmax(0, image->data[i] - amount);
    }
}

void invertImage(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i] = 255 - image->data[i];
    }
}

void grayscaleImage(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        int gray = (image->data[i] + image->data[i + 1] + image->data[i + 2]) / 3;
        image->data[i] = gray;
        image->data[i + 1] = gray;
        image->data[i + 2] = gray;
    }
}

void rotateImage(Image *image, double angle) {
    int newWidth = round(image->width * cos(angle) + image->height * sin(angle));
    int newHeight = round(image->width * sin(angle) + image->height * cos(angle));

    Image newImage;
    allocateImage(&newImage, newWidth, newHeight);

    double cx = image->width / 2.0;
    double cy = image->height / 2.0;
    double cosA = cos(angle);
    double sinA = sin(angle);

    for (int i = 0; i < newWidth; i++) {
        for (int j = 0; j < newHeight; j++) {
            double x = (i - cx) * cosA + (j - cy) * sinA + cx;
            double y = (j - cy) * cosA - (i - cx) * sinA + cy;

            if (x >= 0 && x < image->width && y >= 0 && y < image->height) {
                int index = (int)y * image->width + (int)x;
                newImage.data[i + j * newWidth] = image->data[index];
            }
        }
    }

    freeImage(image);
    *image = newImage;
}

void flipImage(Image *image, int horizontal) {
    int width = image->width;
    int height = image->height;
    unsigned char *data = image->data;

    if (horizontal) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width / 2; j++) {
                int index1 = i * width + j;
                int index2 = i * width + (width - j - 1);
                unsigned char temp = data[index1];
                data[index1] = data[index2];
                data[index2] = temp;
            }
        }
    } else {
        for (int i = 0; i < height / 2; i++) {
            for (int j = 0; j < width; j++) {
                int index1 = i * width + j;
                int index2 = (height - i - 1) * width + j;
                unsigned char temp = data[index1];
                data[index1] = data[index2];
                data[index2] = temp;
            }
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input image> <output image>\n", argv[0]);
        exit(1);
    }

    Image image;
    loadImage(&image, argv[1]);

    // Perform image processing operations here
    brightenImage(&image, 50);
    rotateImage(&image, M_PI / 6);
    flipImage(&image, 1);
    grayscaleImage(&image);

    saveImage(&image, argv[2]);
    freeImage(&image);

    return 0;
}