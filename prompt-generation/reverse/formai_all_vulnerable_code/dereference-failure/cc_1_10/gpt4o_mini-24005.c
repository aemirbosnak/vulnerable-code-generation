//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char BYTE;

typedef struct {
    BYTE r, g, b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *data;
} Image;

Image *load_image(const char *filename);
void save_image(const char *filename, Image *img);
void flip_image(Image *img);
void adjust_brightness(Image *img, int adjustment);
void adjust_contrast(Image *img, float factor);
void free_image(Image *img);

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: %s <input_image> <output_image> <brightness_adjustment> <contrast_factor>\n", argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    int brightness_adjustment = atoi(argv[3]);
    float contrast_factor = atof(argv[4]);

    Image *img = load_image(input_file);
    if (!img) {
        fprintf(stderr, "Error: Could not load image.\n");
        return 1;
    }

    flip_image(img);
    adjust_brightness(img, brightness_adjustment);
    adjust_contrast(img, contrast_factor);

    save_image(output_file, img);
    
    free_image(img);
    return 0;
}

Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return NULL;
    }

    // Read image header (Assuming a PPM P6 format for simplicity)
    char header[3];
    int width, height, max_colors;
    fscanf(file, "%s\n%d %d\n%d\n", header, &width, &height, &max_colors);
    
    if (strcmp(header, "P6") != 0 || max_colors != 255) {
        fclose(file);
        return NULL;
    }

    Image *img = malloc(sizeof(Image));
    if (!img) {
        fclose(file);
        return NULL;
    }
    
    img->width = width;
    img->height = height;
    img->data = malloc(sizeof(Pixel) * width * height);
    if (!img->data) {
        free(img);
        fclose(file);
        return NULL;
    }

    fread(img->data, sizeof(Pixel), width * height, file);
    fclose(file);
    
    return img;
}

void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: Could not save image.\n");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void flip_image(Image *img) {
    for (int j = 0; j < img->height; j++) {
        for (int i = 0; i < img->width / 2; i++) {
            Pixel temp = img->data[j * img->width + i];
            img->data[j * img->width + i] = img->data[j * img->width + (img->width - i - 1)];
            img->data[j * img->width + (img->width - i - 1)] = temp;
        }
    }
}

void adjust_brightness(Image *img, int adjustment) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (BYTE)fmin(fmax(img->data[i].r + adjustment, 0), 255);
        img->data[i].g = (BYTE)fmin(fmax(img->data[i].g + adjustment, 0), 255);
        img->data[i].b = (BYTE)fmin(fmax(img->data[i].b + adjustment, 0), 255);
    }
}

void adjust_contrast(Image *img, float factor) {
    float factor_div = (259 * (factor + 255)) / (255 * (259 - factor));
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (BYTE)fmin(fmax(factor_div * (img->data[i].r - 128) + 128, 0), 255);
        img->data[i].g = (BYTE)fmin(fmax(factor_div * (img->data[i].g - 128) + 128, 0), 255);
        img->data[i].b = (BYTE)fmin(fmax(factor_div * (img->data[i].b - 128) + 128, 0), 255);
    }
}

void free_image(Image *img) {
    if (img) {
        free(img->data);
        free(img);
    }
}