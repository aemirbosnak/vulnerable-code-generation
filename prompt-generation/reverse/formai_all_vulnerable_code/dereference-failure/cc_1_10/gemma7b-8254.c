//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct Image {
    int width;
    int height;
    unsigned char **data;
} Image;

Image *createImage(int w, int h) {
    Image *image = (Image *)malloc(sizeof(Image));
    image->width = w;
    image->height = h;
    image->data = (unsigned char **)malloc(h * sizeof(unsigned char *) + 1);
    for (int i = 0; i < h; i++) {
        image->data[i] = (unsigned char *)malloc(w * sizeof(unsigned char) + 1);
    }
    return image;
}

void freeImage(Image *image) {
    for (int i = 0; i < image->height; i++) {
        free(image->data[i]);
    }
    free(image->data);
    free(image);
}

Image *loadImage(char *filename) {
    Image *image = createImage(0, 0);
    FILE *file = fopen(filename, "rb");
    if (file) {
        image->width = fread(&image->width, 1, sizeof(int), file);
        image->height = fread(&image->height, 1, sizeof(int), file);
        image->data = (unsigned char **)malloc(image->height * sizeof(unsigned char *) + 1);
        for (int i = 0; i < image->height; i++) {
            image->data[i] = (unsigned char *)malloc(image->width * sizeof(unsigned char) + 1);
            fread(image->data[i], image->width * image->height, 1, file);
        }
        fclose(file);
    }
    return image;
}

void saveImage(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file) {
        fwrite(&image->width, 1, sizeof(int), file);
        fwrite(&image->height, 1, sizeof(int), file);
        for (int i = 0; i < image->height; i++) {
            fwrite(image->data[i], image->width * image->height, 1, file);
        }
        fclose(file);
    }
}

int main() {
    Image *image = loadImage("image.jpg");
    saveImage(image, "image_edited.jpg");
    freeImage(image);
    return 0;
}