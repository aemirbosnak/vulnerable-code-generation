//FormAI DATASET v1.0 Category: Image Editor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int width;
    int height;
    unsigned char **pixels;
} Image;

Image *createImage(char *name, int width, int height) {
    Image *img = malloc(sizeof(Image));
    strcpy(img->name, name);
    img->width = width;
    img->height = height;
    img->pixels = malloc(sizeof(unsigned char *) * height);
    for (int i = 0; i < height; i++) {
        img->pixels[i] = malloc(sizeof(unsigned char) * width);
        for (int j = 0; j < width; j++) {
            img->pixels[i][j] = 0;
        }
    }
    return img;
}

void deleteImage(Image *img) {
    for (int i = 0; i < img->height; i++) {
        free(img->pixels[i]);
    }
    free(img->pixels);
    free(img);
}

void loadImage(Image *img, char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error reading file %s\n", filename);
        exit(1);
    }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp);
    img->width = *(int *)&header[18];
    img->height = *(int *)&header[22];
    int bpp = *(int *)&header[28];
    if (bpp != 24) {
        printf("Unsupported image format\n");
        fclose(fp);
        exit(1);
    }

    int paddingSize = (4 - (img->width * 3) % 4) % 4;
    unsigned char padding[3];
    img->pixels = malloc(sizeof(unsigned char *) * img->height);
    for (int i = 0; i < img->height; i++) {
        img->pixels[i] = malloc(sizeof(unsigned char) * img->width);
        fread(img->pixels[i], sizeof(unsigned char), img->width, fp);
        fread(padding, sizeof(unsigned char), paddingSize, fp);
    }

    fclose(fp);
}

void saveImage(Image *img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error writing file %s\n", filename);
        exit(1);
    }

    int paddingSize = (4 - (img->width * 3) % 4) % 4;
    unsigned char padding[3] = {0, 0, 0};
    unsigned char header[54] = {
        'B', 'M',
        0, 0, 0, 0,
        0, 0,
        0, 0,
        54, 0, 0, 0,
        40, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0
    };

    *(int *)&header[18] = img->width;
    *(int *)&header[22] = img->height;

    int rowSize = img->width * 3 + paddingSize;
    int totalSize = rowSize * img->height;
    *(int *)&header[2] = totalSize + 54;
    *(int *)&header[34] = totalSize;

    fwrite(header, sizeof(unsigned char), 54, fp);
    for (int i = 0; i < img->height; i++) {
        fwrite(img->pixels[i], sizeof(unsigned char), img->width, fp);
        fwrite(padding, sizeof(unsigned char), paddingSize, fp);
    }

    fclose(fp);
}

void grayscale(Image *img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            unsigned char r = img->pixels[i][3 * j];
            unsigned char g = img->pixels[i][3 * j + 1];
            unsigned char b = img->pixels[i][3 * j + 2];
            unsigned char gray = 0.299 * r + 0.587 * g + 0.114 * b;
            img->pixels[i][3 * j] = gray;
            img->pixels[i][3 * j + 1] = gray;
            img->pixels[i][3 * j + 2] = gray;
        }
    }
}

int main() {
    Image *img = createImage("test", 50, 50);
    loadImage(img, "input.bmp");
    grayscale(img);
    saveImage(img, "output.bmp");
    deleteImage(img);
    return 0;
}