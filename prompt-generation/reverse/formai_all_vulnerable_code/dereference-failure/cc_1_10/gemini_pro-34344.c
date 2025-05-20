//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: careful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int width;
    unsigned int height;
    unsigned char *data;
} Image;

Image *image_new(unsigned int width, unsigned int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * 4);
    return image;
}

void image_free(Image *image) {
    free(image->data);
    free(image);
}

void image_load(Image *image, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("fopen");
        exit(1);
    }

    fread(&image->width, sizeof(unsigned int), 1, file);
    fread(&image->height, sizeof(unsigned int), 1, file);

    image->data = malloc(image->width * image->height * 4);
    fread(image->data, 1, image->width * image->height * 4, file);

    fclose(file);
}

void image_save(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("fopen");
        exit(1);
    }

    fwrite(&image->width, sizeof(unsigned int), 1, file);
    fwrite(&image->height, sizeof(unsigned int), 1, file);

    fwrite(image->data, 1, image->width * image->height * 4, file);

    fclose(file);
}

void image_flip_horizontal(Image *image) {
    for (unsigned int y = 0; y < image->height; y++) {
        for (unsigned int x = 0; x < image->width / 2; x++) {
            unsigned char *pixel1 = &image->data[(y * image->width + x) * 4];
            unsigned char *pixel2 = &image->data[(y * image->width + (image->width - x - 1)) * 4];

            unsigned char temp = pixel1[0];
            pixel1[0] = pixel2[0];
            pixel2[0] = temp;

            temp = pixel1[1];
            pixel1[1] = pixel2[1];
            pixel2[1] = temp;

            temp = pixel1[2];
            pixel1[2] = pixel2[2];
            pixel2[2] = temp;
        }
    }
}

void image_flip_vertical(Image *image) {
    for (unsigned int y = 0; y < image->height / 2; y++) {
        for (unsigned int x = 0; x < image->width; x++) {
            unsigned char *pixel1 = &image->data[(y * image->width + x) * 4];
            unsigned char *pixel2 = &image->data[((image->height - y - 1) * image->width + x) * 4];

            unsigned char temp = pixel1[0];
            pixel1[0] = pixel2[0];
            pixel2[0] = temp;

            temp = pixel1[1];
            pixel1[1] = pixel2[1];
            pixel2[1] = temp;

            temp = pixel1[2];
            pixel1[2] = pixel2[2];
            pixel2[2] = temp;
        }
    }
}

void image_brightness_contrast(Image *image, float brightness, float contrast) {
    for (unsigned int y = 0; y < image->height; y++) {
        for (unsigned int x = 0; x < image->width; x++) {
            unsigned char *pixel = &image->data[(y * image->width + x) * 4];

            pixel[0] = (pixel[0] - 128) * contrast + 128 + brightness;
            pixel[1] = (pixel[1] - 128) * contrast + 128 + brightness;
            pixel[2] = (pixel[2] - 128) * contrast + 128 + brightness;
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <input image> [<output image>]\n", argv[0]);
        return 1;
    }

    Image *image = image_new(0, 0);
    image_load(image, argv[1]);

    image_flip_horizontal(image);
    image_flip_vertical(image);
    image_brightness_contrast(image, 0.5, 1.2);

    if (argc >= 3) {
        image_save(image, argv[2]);
    } else {
        printf("Flipped, vertically flipped, and adjusted brightness/contrast image:\n");
        for (unsigned int y = 0; y < image->height; y++) {
            for (unsigned int x = 0; x < image->width; x++) {
                unsigned char *pixel = &image->data[(y * image->width + x) * 4];
                printf("%02x%02x%02x ", pixel[0], pixel[1], pixel[2]);
            }
            printf("\n");
        }
    }

    image_free(image);

    return 0;
}