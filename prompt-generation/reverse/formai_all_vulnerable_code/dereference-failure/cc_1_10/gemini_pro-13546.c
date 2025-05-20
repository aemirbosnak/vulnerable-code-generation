//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
    unsigned char r, g, b;
} pixel;

typedef struct {
    int width, height;
    pixel pixels[MAX_WIDTH][MAX_HEIGHT];
} image;

image* load_image(char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    image* img = malloc(sizeof(image));
    if (!img) {
        fprintf(stderr, "Error: could not allocate memory for image\n");
        fclose(file);
        return NULL;
    }

    fread(&img->width, sizeof(int), 1, file);
    fread(&img->height, sizeof(int), 1, file);

    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            fread(&img->pixels[x][y].r, sizeof(unsigned char), 1, file);
            fread(&img->pixels[x][y].g, sizeof(unsigned char), 1, file);
            fread(&img->pixels[x][y].b, sizeof(unsigned char), 1, file);
        }
    }

    fclose(file);

    return img;
}

void save_image(image* img, char* filename) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    fwrite(&img->width, sizeof(int), 1, file);
    fwrite(&img->height, sizeof(int), 1, file);

    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            fwrite(&img->pixels[x][y].r, sizeof(unsigned char), 1, file);
            fwrite(&img->pixels[x][y].g, sizeof(unsigned char), 1, file);
            fwrite(&img->pixels[x][y].b, sizeof(unsigned char), 1, file);
        }
    }

    fclose(file);
}

image* flip_image(image* img) {
    image* flipped = malloc(sizeof(image));
    if (!flipped) {
        fprintf(stderr, "Error: could not allocate memory for flipped image\n");
        return NULL;
    }

    flipped->width = img->width;
    flipped->height = img->height;

    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            flipped->pixels[x][y] = img->pixels[img->width - 1 - x][y];
        }
    }

    return flipped;
}

image* adjust_brightness_contrast(image* img, float brightness, float contrast) {
    image* adjusted = malloc(sizeof(image));
    if (!adjusted) {
        fprintf(stderr, "Error: could not allocate memory for adjusted image\n");
        return NULL;
    }

    adjusted->width = img->width;
    adjusted->height = img->height;

    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            pixel p = img->pixels[x][y];
            p.r = (unsigned char)round((p.r + brightness) * contrast);
            p.g = (unsigned char)round((p.g + brightness) * contrast);
            p.b = (unsigned char)round((p.b + brightness) * contrast);
            adjusted->pixels[x][y] = p;
        }
    }

    return adjusted;
}

int main(int argc, char** argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input image> <output image> <operation>\n", argv[0]);
        fprintf(stderr, "Operations: flip, brightness, contrast\n");
        return 1;
    }

    char* input_filename = argv[1];
    char* output_filename = argv[2];
    char* operation = argv[3];

    image* img = load_image(input_filename);
    if (!img) {
        return 1;
    }

    image* processed_img = NULL;
    if (strcmp(operation, "flip") == 0) {
        processed_img = flip_image(img);
    } else if (strcmp(operation, "brightness") == 0) {
        float brightness = atof(argv[4]);
        processed_img = adjust_brightness_contrast(img, brightness, 1.0);
    } else if (strcmp(operation, "contrast") == 0) {
        float contrast = atof(argv[4]);
        processed_img = adjust_brightness_contrast(img, 0.0, contrast);
    } else {
        fprintf(stderr, "Error: unknown operation %s\n", operation);
        free(img);
        return 1;
    }

    if (!processed_img) {
        fprintf(stderr, "Error: could not process image\n");
        free(img);
        return 1;
    }

    save_image(processed_img, output_filename);

    free(img);
    free(processed_img);

    return 0;
}