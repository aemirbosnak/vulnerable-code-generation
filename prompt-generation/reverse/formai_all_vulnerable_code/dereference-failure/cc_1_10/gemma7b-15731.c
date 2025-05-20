//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024

typedef struct Image {
    int width;
    int height;
    unsigned char *data;
} Image;

Image *createImage(int w, int h) {
    Image *image = malloc(sizeof(Image));
    image->width = w;
    image->height = h;
    image->data = malloc(w * h * 3);
    return image;
}

void setImagePixel(Image *image, int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    if (x < image->width && y < image->height) {
        image->data[3 * (x + image->width * y)] = r;
        image->data[3 * (x + image->width * y) + 1] = g;
        image->data[3 * (x + image->width * y) + 2] = b;
    }
}

void saveImage(Image *image, FILE *file) {
    fprintf(file, "P Bitmap %d %d\n", image->width, image->height);
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            fprintf(file, "%c %c %c ", image->data[3 * (x + image->width * y)], image->data[3 * (x + image->width * y) + 1], image->data[3 * (x + image->width * y) + 2]);
        }
        fprintf(file, "\n");
    }
}

int main() {
    Image *image = createImage(512, 512);
    setImagePixel(image, 100, 100, 255, 0, 0);
    setImagePixel(image, 200, 200, 0, 255, 0);
    setImagePixel(image, 300, 300, 0, 0, 255);

    FILE *file = fopen("image.bmp", "w");
    saveImage(image, file);
    fclose(file);

    free(image->data);
    free(image);

    return 0;
}