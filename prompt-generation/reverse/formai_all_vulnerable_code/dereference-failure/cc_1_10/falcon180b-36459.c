//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000
#define MAX_COLORS 256

typedef struct {
    int width;
    int height;
    int channels;
    int colors;
    int *data;
} Image;

Image *createImage(int width, int height, int channels, int colors) {
    Image *image = (Image *)malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->channels = channels;
    image->colors = colors;
    image->data = (int *)malloc(sizeof(int) * width * height * channels);
    return image;
}

void destroyImage(Image *image) {
    free(image->data);
    free(image);
}

void setPixel(Image *image, int x, int y, int channel, int value) {
    int offset = (y * image->width + x) * image->channels;
    image->data[offset + channel] = value;
}

int getPixel(Image *image, int x, int y, int channel) {
    int offset = (y * image->width + x) * image->channels;
    return image->data[offset + channel];
}

void printImage(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            for (int channel = 0; channel < image->channels; channel++) {
                int value = getPixel(image, x, y, channel);
                printf("%d ", value);
            }
        }
        printf("\n");
    }
}

int main() {
    Image *image = createImage(MAX_WIDTH, MAX_HEIGHT, 3, MAX_COLORS);

    // Set some initial pixels
    setPixel(image, 0, 0, 0, 0);
    setPixel(image, 0, 0, 1, 255);
    setPixel(image, 0, 0, 2, 0);

    // Print the image
    printImage(image);

    // Destroy the image
    destroyImage(image);

    return 0;
}