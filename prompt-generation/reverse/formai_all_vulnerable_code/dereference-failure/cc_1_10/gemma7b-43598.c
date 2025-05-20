//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: complex
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
    image->width = image->height = 0;

    FILE *file = fopen(filename, "rb");
    if (file) {
        fscanf(file, "PBM %d %d\n", &image->width, &image->height);
        image->pixels = (unsigned char **)realloc(image->pixels, image->height * sizeof(unsigned char *));
        image->pixels[0] = malloc(image->width * sizeof(unsigned char));
        fread(image->pixels[0], image->width * image->height, 1, file);
        fclose(file);
    }

    return image;
}

void convert_image_to_ascii(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int pixel_value = image->pixels[y][x];
            switch (pixel_value) {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(".");
                    break;
                case 2:
                    printf("#");
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
    Image *image = load_image("image.pbm");
    convert_image_to_ascii(image);
    free(image->pixels);
    free(image);

    return 0;
}