//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMG_W 640
#define IMG_H 480

// RGB color, each between 0-255
typedef struct {
    unsigned char r, g, b;
} rgb;

// Image
typedef struct {
    int width, height;
    rgb *data;
} image;

// Load image from file
image *load_image(char *filename) {
    image *img = (image *) malloc(sizeof(image));
    FILE *f = fopen(filename, "rb");
    if (!f) {
        fprintf(stderr, "Error: File not found.\n");
        exit(1);
    }
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, f);
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: File format not supported.\n");
        exit(1);
    }
    img->width = *(int *) &header[18];
    img->height = *(int *) &header[22];
    img->data = (rgb *) malloc(img->width * img->height * sizeof(rgb));
    unsigned char padding[3];
    int padding_size = (4 - (img->width * sizeof(rgb) % 4)) % 4;
    for (int i = 0; i < img->height; ++i) {
        for (int j = 0; j < img->width; ++j) {
            fread(&img->data[i*img->width + j], sizeof(rgb), 1, f);
        }
        fread(padding, sizeof(unsigned char), padding_size, f);
    }
    fclose(f);
    return img;
}

// Save image to file
void save_image(image *img, char *filename) {
    FILE *f = fopen(filename, "wb");
    if (!f) {
        fprintf(stderr, "Error: File could not be saved.\n");
        exit(1);
    }
    unsigned char header[54] = {
        'B', 'M',
        0, 0, 0, 0,
        0, 0, 0, 0,
        54, 0, 0, 0,
        40, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        1, 0, 24, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0
    };
    *(int *) &header[2] = 54 + img->width * img->height * sizeof(rgb);
    *(int *) &header[18] = img->width;
    *(int *) &header[22] = img->height;
    fwrite(header, sizeof(unsigned char), 54, f);
    unsigned char padding[3] = {0, 0, 0};
    int padding_size = (4 - (img->width * sizeof(rgb) % 4)) % 4;
    for (int i = 0; i < img->height; ++i) {
        for (int j = 0; j < img->width; ++j) {
            fwrite(&img->data[i*img->width + j], sizeof(rgb), 1, f);
        }
        fwrite(padding, sizeof(unsigned char), padding_size, f);
    }
    fclose(f);
}

// Flip image horizontally
void flip_horizontal(image *img) {
    rgb temp;
    for (int i = 0; i < img->height; ++i) {
        for (int j = 0; j < img->width/2; ++j) {
            temp = img->data[i*img->width + j];
            img->data[i*img->width + j] = img->data[i*img->width + img->width - j - 1];
            img->data[i*img->width + img->width - j - 1] = temp;
        }
    }
}

// Adjust brightness and contrast of image
void adjust_brightness_contrast(image *img, int brightness, int contrast) {
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for (int i = 0; i < img->height; ++i) {
        for (int j = 0; j < img->width; ++j) {
            img->data[i*img->width + j].r = (unsigned char) (factor * (img->data[i*img->width + j].r - 128) + 128 + brightness);
            img->data[i*img->width + j].g = (unsigned char) (factor * (img->data[i*img->width + j].g - 128) + 128 + brightness);
            img->data[i*img->width + j].b = (unsigned char) (factor * (img->data[i*img->width + j].b - 128) + 128 + brightness);
        }
    }
}

int main(int argc, char **argv) {

    if (argc != 4) {
        fprintf(stderr, "Usage: %s input_file output_file operation(brightness/contrast/flip)\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    char *operation = argv[3];

    image *img = load_image(input_file);

    if (strcmp(operation, "brightness") == 0) {
        adjust_brightness_contrast(img, 100, 0);
    } else if (strcmp(operation, "contrast") == 0) {
        adjust_brightness_contrast(img, 0, 50);
    } else if (strcmp(operation, "flip") == 0) {
        flip_horizontal(img);
    } else {
        fprintf(stderr, "Error: Invalid operation specified.\n");
        return 1;
    }

    save_image(img, output_file);

    return 0;
}