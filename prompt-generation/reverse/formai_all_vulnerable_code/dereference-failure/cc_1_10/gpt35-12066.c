//FormAI DATASET v1.0 Category: Image Editor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pixel {
    int red;
    int green;
    int blue;
};

struct Image {
    int width;
    int height;
    struct Pixel **pixels;
};

void read_image(struct Image *image, char *filename) {
    FILE *fp = fopen(filename, "rb");
    if(fp == NULL) {
        printf("Error: could not open file '%s' for reading.\n", filename);
        exit(1);
    }

    char header[54];
    fread(header, sizeof(char), 54, fp);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    fseek(fp, 0L, SEEK_SET);

    image->width = width;
    image->height = height;

    image->pixels = malloc(sizeof(struct Pixel *) * height);
    for(int i = 0; i < height; i++) {
        image->pixels[i] = malloc(sizeof(struct Pixel) * width);
        fread(image->pixels[i], sizeof(struct Pixel), width, fp);
    }

    fclose(fp);
}

void write_image(struct Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if(fp == NULL) {
        printf("Error: could not open file '%s' for writing.\n", filename);
        exit(1);
    }

    char header[54];
    memset(header, 0, 54);
    header[0] = 'B';
    header[1] = 'M';
    *(int*)&header[2] = 54 + 3 * image->width * image->height;
    *(int*)&header[10] = 54;
    *(int*)&header[14] = 40;
    *(int*)&header[18] = image->width;
    *(int*)&header[22] = image->height;
    *(short*)&header[26] = 1;
    *(short*)&header[28] = 24;

    fwrite(header, sizeof(char), 54, fp);

    for(int i = 0; i < image->height; i++) {
        fwrite(image->pixels[i], sizeof(struct Pixel), image->width, fp);
    }

    fclose(fp);
}

void grayscale(struct Image *image) {
    for(int i = 0; i < image->height; i++) {
        for(int j = 0; j < image->width; j++) {
            int gray = (image->pixels[i][j].red + image->pixels[i][j].green + image->pixels[i][j].blue) / 3;
            image->pixels[i][j].red = gray;
            image->pixels[i][j].green = gray;
            image->pixels[i][j].blue = gray;
        }
    }
}

void invert(struct Image *image) {
    for(int i = 0; i < image->height; i++) {
        for(int j = 0; j < image->width; j++) {
            image->pixels[i][j].red = 255 - image->pixels[i][j].red;
            image->pixels[i][j].green = 255 - image->pixels[i][j].green;
            image->pixels[i][j].blue = 255 - image->pixels[i][j].blue;
        }
    }
}

void apocalypse(struct Image *image) {
    grayscale(image);
    invert(image);
    invert(image);
    grayscale(image);
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: %s input-file output-file\n", argv[0]);
        return 1;
    }

    struct Image image;
    read_image(&image, argv[1]);

    apocalypse(&image);

    write_image(&image, argv[2]);

    return 0;
}