//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024

typedef struct Image {
    int width;
    int height;
    unsigned char **pixels;
} Image;

Image *load_image(char *filename) {
    Image *image = malloc(sizeof(Image));
    image->pixels = malloc(MAX_IMAGE_SIZE * sizeof(unsigned char *));
    for (int i = 0; i < MAX_IMAGE_SIZE; i++) {
        image->pixels[i] = malloc(MAX_IMAGE_SIZE * sizeof(unsigned char));
    }

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    fscanf(fp, "%d %d", &image->width, &image->height);
    image->pixels[0][0] = fread(image->pixels[0][0], image->width * image->height, 1, fp);

    fclose(fp);

    return image;
}

void convert_image_to_ascii(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            unsigned char pixel_value = image->pixels[y][x];
            switch (pixel_value) {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(". ");
                    break;
                case 2:
                    printf("* ");
                    break;
                case 3:
                    printf("# ");
                    break;
                default:
                    printf("Error!");
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    Image *image = load_image("image.jpg");
    convert_image_to_ascii(image);
    free(image);

    return 0;
}