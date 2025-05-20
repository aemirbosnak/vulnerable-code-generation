//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000

typedef struct {
    int width;
    int height;
    int *data;
} Image;

Image loadImage(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error loading image: %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    Image img;
    img.data = malloc(size * sizeof(int));
    fread(img.data, size, sizeof(int), fp);

    fclose(fp);

    return img;
}

void flipImage(Image *img) {
    int width = img->width;
    int height = img->height;
    int *data = img->data;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            int temp = data[y * width + x];
            data[y * width + x] = data[y * width + width - x - 1];
            data[y * width + width - x - 1] = temp;
        }
    }
}

void changeContrast(Image *img, float factor) {
    int width = img->width;
    int height = img->height;
    int *data = img->data;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int value = data[y * width + x];
            int newValue = (int) ((float) value * factor);

            if (newValue < 0) {
                newValue = 0;
            } else if (newValue > 255) {
                newValue = 255;
            }

            data[y * width + x] = newValue;
        }
    }
}

void saveImage(Image img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error saving image: %s\n", filename);
        exit(1);
    }

    fwrite(img.data, img.width * img.height, sizeof(int), fp);

    fclose(fp);
}

int main() {
    Image img = loadImage("input.bmp");
    flipImage(&img);
    changeContrast(&img, 1.5);
    saveImage(img, "output.bmp");

    return 0;
}