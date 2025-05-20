//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int width, height;
    unsigned char *data;
} Image;

Image *image_new(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * 3);
    return image;
}

void image_free(Image *image) {
    free(image->data);
    free(image);
}

int image_get_pixel(Image *image, int x, int y) {
    return image->data[y * image->width * 3 + x * 3];
}

void image_set_pixel(Image *image, int x, int y, int value) {
    image->data[y * image->width * 3 + x * 3] = value;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <input image> <output image>\n", argv[0]);
        return 1;
    }

    Image *image = image_new(128, 128);

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int r = 255 * (x / (float) image->width);
            int g = 255 * (y / (float) image->height);
            int b = 255 * (x * y / (float) (image->width * image->height));
            image_set_pixel(image, x, y, r | g | b);
        }
    }

    FILE *output = fopen(argv[2], "wb");
    fwrite(image->data, 1, image->width * image->height * 3, output);
    fclose(output);

    image_free(image);

    return 0;
}