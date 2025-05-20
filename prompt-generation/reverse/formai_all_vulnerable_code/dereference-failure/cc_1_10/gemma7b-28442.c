//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct ImageData {
    unsigned char *data;
    int width;
    int height;
} ImageData;

ImageData *loadImage(char *filename) {
    FILE *fp;
    ImageData *image = malloc(sizeof(ImageData));

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        return NULL;
    }

    image->data = (unsigned char *)malloc(MAX_BUFFER_SIZE);
    image->width = 1024;
    image->height = 1024;

    fread(image->data, MAX_BUFFER_SIZE, 1, fp);
    fclose(fp);

    return image;
}

void saveImage(ImageData *image, char *filename) {
    FILE *fp;

    fp = fopen(filename, "wb");
    if (fp == NULL) {
        return;
    }

    fwrite(image->data, image->width * image->height, 1, fp);
    fclose(fp);
}

int main() {
    ImageData *image = loadImage("image.jpg");

    saveImage(image, "image_edited.jpg");

    free(image->data);
    free(image);

    return 0;
}