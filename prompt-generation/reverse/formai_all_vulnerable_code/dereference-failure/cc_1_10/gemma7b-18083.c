//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024

typedef struct Image {
    unsigned char *data;
    int width;
    int height;
} Image;

Image *load_image(char *filename) {
    Image *image = malloc(sizeof(Image));
    image->data = malloc(MAX_IMAGE_SIZE);
    image->width = 0;
    image->height = 0;

    FILE *file = fopen(filename, "r");
    if (!file) {
        return NULL;
    }

    fscanf(file, "P Bitmap (%d, %d) ", &image->width, &image->height);
    image->data = fread(image->data, MAX_IMAGE_SIZE, 1, file);
    fclose(file);

    return image;
}

void convert_image_to_ascii(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            unsigned char pixel = image->data[y * image->width + x];
            switch (pixel) {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(".");
                    break;
                case 2:
                    printf("*");
                    break;
                case 3:
                    printf("$");
                    break;
                default:
                    printf("!");
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    Image *image = load_image("image.bmp");
    convert_image_to_ascii(image);
    free(image->data);
    free(image);

    return 0;
}