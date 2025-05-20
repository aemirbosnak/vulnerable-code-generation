//FormAI DATASET v1.0 Category: Image Editor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    unsigned char r, g, b;
} pixel_t;

pixel_t* load_image(const char* filename);
void save_image(const char* filename, const pixel_t* image, int width, int height);
void grayscale(pixel_t* image, int width, int height);
void flip_horizontal(pixel_t* image, int width, int height);
void blur(pixel_t* image, int width, int height);

int main() {
    pixel_t* image = load_image("input.bmp");

    grayscale(image, WIDTH, HEIGHT);
    flip_horizontal(image, WIDTH, HEIGHT);
    blur(image, WIDTH, HEIGHT);

    save_image("output.bmp", image, WIDTH, HEIGHT);

    free(image);
    return 0;
}

pixel_t* load_image(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }

    // read BMP header
    fseek(file, 18, SEEK_SET);
    int width = 0, height = 0;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);
    fseek(file, 54, SEEK_SET);

    // allocate memory for image
    pixel_t* image = malloc(width * height * sizeof(pixel_t));
    if (!image) {
        fprintf(stderr, "Error: could not allocate memory for image\n");
        exit(1);
    }

    // read image data
    int i;
    for (i = 0; i < width * height; i++) {
        fread(&image[i].b, sizeof(unsigned char), 1, file);
        fread(&image[i].g, sizeof(unsigned char), 1, file);
        fread(&image[i].r, sizeof(unsigned char), 1, file);
    }

    fclose(file);
    return image;
}

void save_image(const char* filename, const pixel_t* image, int width, int height) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }

    // write BMP header
    int filesize = 54 + width * height * 3;
    fwrite("BM", sizeof(unsigned char), 2, file);
    fwrite(&filesize, sizeof(int), 1, file);
    fwrite("\0\0\0\0", sizeof(unsigned char), 4, file);
    fwrite("\x36\0\0\0", sizeof(unsigned char), 4, file);
    fwrite("\x28\0\0\0", sizeof(unsigned char), 4, file);
    fwrite(&width, sizeof(int), 1, file);
    fwrite(&height, sizeof(int), 1, file);
    fwrite("\x01\0", sizeof(unsigned char), 2, file);
    fwrite("\x18\0", sizeof(unsigned char), 2, file);
    fwrite("\0\0\0\0", sizeof(unsigned char), 4, file);
    fwrite("\x00\x00\x00\x00\x00\x00\x00\x00", sizeof(unsigned char), 8, file);

    // write image data
    int i;
    for (i = 0; i < width * height; i++) {
        fwrite(&image[i].b, sizeof(unsigned char), 1, file);
        fwrite(&image[i].g, sizeof(unsigned char), 1, file);
        fwrite(&image[i].r, sizeof(unsigned char), 1, file);
    }

    fclose(file);
}

void grayscale(pixel_t* image, int width, int height) {
    int i;
    for (i = 0; i < width * height; i++) {
        unsigned char gray = 0.3 * image[i].r + 0.59 * image[i].g + 0.11 * image[i].b;
        image[i].r = gray;
        image[i].g = gray;
        image[i].b = gray;
    }
}

void flip_horizontal(pixel_t* image, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width / 2; j++) {
            int k = i * width + j;
            int l = i * width + (width - j - 1);
            pixel_t temp = image[k];
            image[k] = image[l];
            image[l] = temp;
        }
    }
}

void blur(pixel_t* image, int width, int height) {
    int i, j;
    for (i = 1; i < height - 1; i++) {
        for (j = 1; j < width - 1; j++) {
            int k = i * width + j;
            int k1 = (i - 1) * width + j;
            int k2 = (i + 1) * width + j;
            int k3 = i * width + (j - 1);
            int k4 = i * width + (j + 1);
            image[k].r = (image[k1].r + image[k2].r + image[k3].r + image[k4].r) / 4;
            image[k].g = (image[k1].g + image[k2].g + image[k3].g + image[k4].g) / 4;
            image[k].b = (image[k1].b + image[k2].b + image[k3].b + image[k4].b) / 4;
        }
    }
}