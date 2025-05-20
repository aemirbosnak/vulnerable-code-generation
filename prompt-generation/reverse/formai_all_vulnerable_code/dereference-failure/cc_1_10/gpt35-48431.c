//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pixel {
    unsigned char r, g, b;
} Pixel;

typedef struct Image {
    int width, height;
    Pixel *pixels;
} Image;

void flip(Image *image) {
    for (int i = 0; i < image->height / 2; i++) {
        for (int j = 0; j < image->width; j++) {
            Pixel tmp = image->pixels[i * image->width + j];
            image->pixels[i * image->width + j] = image->pixels[(image->height - i - 1) * image->width + j];
            image->pixels[(image->height - i - 1) * image->width + j] = tmp;
        }
    }
}

void changeBrightness(Image *image, int value) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->pixels[i].r += value;
        image->pixels[i].g += value;
        image->pixels[i].b += value;
    }
}

void changeContrast(Image *image, double value) {
    double factor = (259.0 * (value + 255.0)) / (255.0 * (259.0 - value));
    for (int i = 0; i < image->width * image->height; i++) {
        Pixel *p = &image->pixels[i];
        p->r = factor * (p->r - 128u) + 128u;
        p->g = factor * (p->g - 128u) + 128u;
        p->b = factor * (p->b - 128u) + 128u;
    }
}

Image *loadImage(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Failed to open file: %s\n", filename);
        return NULL;
    }

    Image *image = (Image *) malloc(sizeof(Image));

    char header[54];
    fread(header, sizeof(char), 54, file);

    int width = *(int *) &header[18];
    int height = *(int *) &header[22];

    image->width = width;
    image->height = height;

    int padding = (4 - (width * sizeof(Pixel)) % 4) % 4;

    image->pixels = (Pixel *) malloc(sizeof(Pixel) * width * height);
    for (int i = 0; i < height; i++) {
        fread(&image->pixels[i * width], sizeof(Pixel), width, file);
        fseek(file, padding, SEEK_CUR);
    }

    fclose(file);
    return image;
}

void saveImage(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Failed to create file: %s\n", filename);
        return;
    }

    int padding = (4 - (image->width * sizeof(Pixel)) % 4) % 4;

    char header[54];
    memset(header, 0, sizeof(header));

    header[0] = 'B';
    header[1] = 'M';
    *(int *) &header[2] = sizeof(header) + (image->width * sizeof(Pixel) + padding) * image->height;
    *(int *) &header[10] = sizeof(header);
    *(int *) &header[14] = 40;
    *(int *) &header[18] = image->width;
    *(int *) &header[22] = image->height;
    *(short *) &header[26] = 1;
    *(short *) &header[28] = 24;
    *(int *) &header[34] = (image->width * sizeof(Pixel) + padding) * image->height;

    fwrite(header, sizeof(char), sizeof(header), file);

    for (int i = 0; i < image->height; i++) {
        fwrite(&image->pixels[i * image->width], sizeof(Pixel), image->width, file);
        for (int j = 0; j < padding; j++) {
            fputc(0, file);
        }
    }

    fclose(file);
}

int main() {
    Image *image = loadImage("image.bmp");
    if (!image) {
        return 1;
    }

    flip(image);

    changeBrightness(image, 50);

    changeContrast(image, 50.0);

    saveImage("output.bmp", image);

    free(image->pixels);
    free(image);

    return 0;
}