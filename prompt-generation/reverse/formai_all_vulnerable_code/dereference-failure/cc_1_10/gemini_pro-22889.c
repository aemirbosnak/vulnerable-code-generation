//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: complex
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char *data;
    int width;
    int height;
} Image;

Image *create_image(int width, int height) {
    Image *image = (Image *)malloc(sizeof(Image));
    image->data = (unsigned char *)malloc(width * height);
    image->width = width;
    image->height = height;
    return image;
}

void destroy_image(Image *image) {
    free(image->data);
    free(image);
}

void load_image(Image *image, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    fread(image->data, 1, image->width * image->height, fp);
    fclose(fp);
}

void save_image(Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    fwrite(image->data, 1, image->width * image->height, fp);
    fclose(fp);
}

void flip_image(Image *image) {
    int i, j;
    for (i = 0; i < image->height / 2; i++) {
        for (j = 0; j < image->width; j++) {
            unsigned char temp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[(image->height - 1 - i) * image->width + j];
            image->data[(image->height - 1 - i) * image->width + j] = temp;
        }
    }
}

void change_brightness_contrast(Image *image, float brightness, float contrast) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            int value = image->data[i * image->width + j] + (brightness * 255);
            value = (value < 0) ? 0 : (value > 255) ? 255 : value;
            image->data[i * image->width + j] = (unsigned char)(value * contrast);
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input image> <output image>\n", argv[0]);
        exit(1);
    }

    Image *image = create_image(512, 512);
    load_image(image, argv[1]);

    flip_image(image);
    change_brightness_contrast(image, 0.2, 1.5);

    save_image(image, argv[2]);
    destroy_image(image);

    return 0;
}