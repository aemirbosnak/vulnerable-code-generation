//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: high level of detail
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

image *image_new(int width, int height) {
    image *img = malloc(sizeof(image));
    img->width = width;
    img->height = height;
    img->data = malloc(width * height * sizeof(pixel));
    return img;
}

void image_free(image *img) {
    free(img->data);
    free(img);
}

int image_load(image *img, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        return -1;
    }

    // Read header
    unsigned char header[54];
    fread(header, 1, 54, fp);

    // Check if it's a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Invalid BMP file\n");
        fclose(fp);
        return -1;
    }

    // Get image dimensions
    img->width = *(int *)&header[18];
    img->height = *(int *)&header[22];

    // Read data
    fseek(fp, 54, SEEK_SET);
    fread(img->data, 1, img->width * img->height * sizeof(pixel), fp);

    fclose(fp);

    return 0;
}

int image_save(image *img, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("fopen");
        return -1;
    }

    // Write header
    unsigned char header[54] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0
    };
    *(int *)&header[18] = img->width;
    *(int *)&header[22] = img->height;
    fwrite(header, 1, 54, fp);

    // Write data
    fwrite(img->data, 1, img->width * img->height * sizeof(pixel), fp);

    fclose(fp);

    return 0;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input image> <output image>\n", argv[0]);
        return -1;
    }

    // Load input image
    image *img = image_new(0, 0);
    if (image_load(img, argv[1]) < 0) {
        return -1;
    }

    // Apply some effects

    // Invert colors
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = 255 - img->data[i].r;
        img->data[i].g = 255 - img->data[i].g;
        img->data[i].b = 255 - img->data[i].b;
    }

    // Save output image
    if (image_save(img, argv[2]) < 0) {
        return -1;
    }

    // Free image data
    image_free(img);

    return 0;
}