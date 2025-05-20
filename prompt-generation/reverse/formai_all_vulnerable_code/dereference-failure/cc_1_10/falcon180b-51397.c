//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
    int width;
    int height;
    char* data;
} Image;

Image* loadImage(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    char* data = malloc(size);
    if (data == NULL) {
        printf("Error: could not allocate memory\n");
        exit(1);
    }

    if (fread(data, 1, size, file)!= size) {
        printf("Error: could not read file %s\n", filename);
        exit(1);
    }

    fclose(file);

    Image* image = malloc(sizeof(Image));
    if (image == NULL) {
        printf("Error: could not allocate memory\n");
        exit(1);
    }

    image->width = 0;
    image->height = 0;
    image->data = data;

    return image;
}

void freeImage(Image* image) {
    free(image->data);
    free(image);
}

void printAsciiArt(Image* image) {
    int width = image->width;
    int height = image->height;
    char* data = image->data;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * 3;
            int r = data[index] / 16;
            int g = (data[index] % 16) / 4;
            int b = data[index] % 4;

            int brightness = (r + g + b) / 3;

            if (brightness > 128) {
                printf("  ");
            } else if (brightness > 64) {
                printf(".");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

int main() {
    Image* image = loadImage("example.bmp");
    printAsciiArt(image);
    freeImage(image);

    return 0;
}