//FormAI DATASET v1.0 Category: Image Editor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    int r;
    int g;
    int b;
} Color;

typedef struct {
    int width;
    int height;
    Color* data;
} Image;

Image* loadImage(char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("ERROR: Could not open file '%s'\n", filename);
        return NULL;
    }
    char magicNumber[3];
    fgets(magicNumber, 3, fp);
    if (magicNumber[0] != 'P' || magicNumber[1] != '6') {
        printf("ERROR: Invalid image format in '%s'\n", filename);
        fclose(fp);
        return NULL;
    }
    int width, height, maxVal;
    fscanf(fp, "%d %d", &width, &height);
    fscanf(fp, "%d", &maxVal);
    if (maxVal != 255) {
        printf("ERROR: Invalid max value in '%s'\n", filename);
        fclose(fp);
        return NULL;
    }
    Image* img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = malloc(sizeof(Color) * width * height);
    for (int i = 0; i < width * height; i++) {
        Color c;
        c.r = fgetc(fp);
        c.g = fgetc(fp);
        c.b = fgetc(fp);
        img->data[i] = c;
    }
    fclose(fp);
    printf("Loaded image '%s'\n", filename);
    return img;
}

void saveImage(Image* img, char* filename) {
    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        printf("ERROR: Could not open file '%s'\n", filename);
        return;
    }
    fprintf(fp, "P6\n");
    fprintf(fp, "%d %d\n", img->width, img->height);
    fprintf(fp, "255\n");
    for (int i = 0; i < img->width * img->height; i++) {
        fputc(img->data[i].r, fp);
        fputc(img->data[i].g, fp);
        fputc(img->data[i].b, fp);
    }
    fclose(fp);
    printf("Saved image '%s'\n", filename);
}

Image* newImage(int width, int height) {
    Image* img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = malloc(sizeof(Color) * width * height);
    return img;
}

void destroyImage(Image* img) {
    free(img->data);
    free(img);
}

void setPixel(Image* img, int x, int y, Color c) {
    img->data[y * img->width + x] = c;
}

Color getPixel(Image* img, int x, int y) {
    return img->data[y * img->width + x];
}


int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <input image> <output image>\n", argv[0]);
        return 1;
    }
    Image* input = loadImage(argv[1]);
    if (!input) {
        return 1;
    }
    Image* output = newImage(input->width, input->height);
    for (int y = 0; y < input->height; y++) {
        for (int x = 0; x < input->width; x++) {
            Color c = getPixel(input, x, y);
            c.r = 255 - c.r;
            c.g = 255 - c.g;
            c.b = 255 - c.b;
            setPixel(output, x, y, c);
        }
    }
    saveImage(output, argv[2]);
    destroyImage(input);
    destroyImage(output);
    return 0;
}