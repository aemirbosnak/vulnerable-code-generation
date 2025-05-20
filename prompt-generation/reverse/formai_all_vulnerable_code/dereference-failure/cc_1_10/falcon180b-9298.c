//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 256
#define HEIGHT 256
#define MAX_VALUE 255
#define MIN_VALUE 0

typedef struct {
    int width;
    int height;
    int *data;
} Image;

void createImage(Image *image) {
    image->width = WIDTH;
    image->height = HEIGHT;
    image->data = (int *) malloc(image->width * image->height * sizeof(int));
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i] = MIN_VALUE;
    }
}

void destroyImage(Image *image) {
    free(image->data);
}

void flipImage(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            int temp = image->data[(y * image->width) + x];
            image->data[(y * image->width) + x] = image->data[(y * image->width) + (image->width - 1 - x)];
            image->data[(y * image->width) + (image->width - 1 - x)] = temp;
        }
    }
}

void changeBrightness(Image *image, int delta) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i] += delta;
        if (image->data[i] > MAX_VALUE) {
            image->data[i] = MAX_VALUE;
        } else if (image->data[i] < MIN_VALUE) {
            image->data[i] = MIN_VALUE;
        }
    }
}

void changeContrast(Image *image, int delta) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i] += delta * (image->data[i] - MIN_VALUE) / (MAX_VALUE - MIN_VALUE);
        if (image->data[i] > MAX_VALUE) {
            image->data[i] = MAX_VALUE;
        } else if (image->data[i] < MIN_VALUE) {
            image->data[i] = MIN_VALUE;
        }
    }
}

void saveImage(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    fwrite(image->data, sizeof(int), image->width * image->height, fp);
    fclose(fp);
}

int main() {
    Image image;
    createImage(&image);

    // Fill the image with some random values
    for (int i = 0; i < image.width * image.height; i++) {
        image.data[i] = rand() % MAX_VALUE;
    }

    // Flip the image
    flipImage(&image);

    // Change the brightness and contrast
    changeBrightness(&image, 50);
    changeContrast(&image, 50);

    // Save the modified image
    saveImage(&image, "modified_image.bin");

    return 0;
}