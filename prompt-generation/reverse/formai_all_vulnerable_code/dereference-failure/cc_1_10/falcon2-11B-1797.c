//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1000

typedef struct {
    int width;
    int height;
    char** pixels;
} Image;

Image* createImage(int width, int height) {
    Image* image = (Image*)malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = (char**)malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++) {
        image->pixels[i] = (char*)malloc(width * sizeof(char));
    }
    return image;
}

void freeImage(Image* image) {
    for (int i = 0; i < image->height; i++) {
        free(image->pixels[i]);
    }
    free(image->pixels);
    free(image);
}

void printImage(Image* image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            printf("%c", image->pixels[y][x]);
        }
        printf("\n");
    }
}

void setPixel(Image* image, int x, int y, char value) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        printf("Invalid coordinates\n");
        return;
    }
    image->pixels[y][x] = value;
}

int main() {
    Image* image = createImage(10, 10);
    setPixel(image, 5, 5, 'A');
    printImage(image);
    freeImage(image);
    return 0;
}