//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
    unsigned char r, g, b;
} pixel;

typedef struct {
    int width, height;
    pixel *data;
} image;

image *create_image(int width, int height) {
    image *img = malloc(sizeof(image));
    img->width = width;
    img->height = height;
    img->data = malloc(width * height * sizeof(pixel));
    return img;
}

void destroy_image(image *img) {
    free(img->data);
    free(img);
}

void load_image(image *img, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    // Read the header
    unsigned char header[54];
    fread(header, 1, 54, fp);

    // Check if the file is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: file is not a valid BMP file\n");
        exit(1);
    }

    // Get the image dimensions
    img->width = *(int *)&header[18];
    img->height = *(int *)&header[22];

    // Read the image data
    fread(img->data, 1, img->width * img->height * sizeof(pixel), fp);

    fclose(fp);
}

void save_image(image *img, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    // Write the header
    unsigned char header[54] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0
    };

    *(int *)&header[18] = img->width;
    *(int *)&header[22] = img->height;

    fwrite(header, 1, 54, fp);

    // Write the image data
    fwrite(img->data, 1, img->width * img->height * sizeof(pixel), fp);

    fclose(fp);
}

void flip_image(image *img) {
    for (int i = 0; i < img->height / 2; i++) {
        for (int j = 0; j < img->width; j++) {
            pixel temp = img->data[i * img->width + j];
            img->data[i * img->width + j] = img->data[(img->height - i - 1) * img->width + j];
            img->data[(img->height - i - 1) * img->width + j] = temp;
        }
    }
}

void adjust_brightness(image *img, int brightness) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->data[i * img->width + j].r = img->data[i * img->width + j].r + brightness;
            img->data[i * img->width + j].g = img->data[i * img->width + j].g + brightness;
            img->data[i * img->width + j].b = img->data[i * img->width + j].b + brightness;
        }
    }
}

void adjust_contrast(image *img, int contrast) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->data[i * img->width + j].r = img->data[i * img->width + j].r * contrast;
            img->data[i * img->width + j].g = img->data[i * img->width + j].g * contrast;
            img->data[i * img->width + j].b = img->data[i * img->width + j].b * contrast;
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input image> [<output image>]\n", argv[0]);
        exit(1);
    }

    // Load the input image
    image *img = create_image(MAX_WIDTH, MAX_HEIGHT);
    load_image(img, argv[1]);

    // Flip the image
    flip_image(img);

    // Adjust the brightness and contrast
    adjust_brightness(img, 10);
    adjust_contrast(img, 1.5);

    // Save the output image
    if (argc >= 3) {
        save_image(img, argv[2]);
    } else {
        save_image(img, "output.bmp");
    }

    // Destroy the image
    destroy_image(img);

    return 0;
}