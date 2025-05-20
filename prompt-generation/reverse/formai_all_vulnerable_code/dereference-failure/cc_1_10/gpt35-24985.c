//FormAI DATASET v1.0 Category: Image Editor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pixel {
    unsigned char r, g, b;
};

struct Image {
    int width, height;
    struct Pixel *pixels;
};

// Function to load an image from a PPM file
struct Image *loadImage(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "File not found\n");
        return NULL;
    }

    char type[3];
    fgets(type, sizeof type, file);
    if (strcmp(type, "P6\n") != 0) {
        fprintf(stderr, "Invalid file format\n");
        return NULL;
    }

    int width, height, maxVal;
    fscanf(file, "%d %d\n%d\n", &width, &height, &maxVal);
    if (maxVal != 255) {
        fprintf(stderr, "Invalid color depth\n");
        return NULL;
    }

    struct Image *image = malloc(sizeof(struct Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height * sizeof(struct Pixel));

    fread(image->pixels, width * height * sizeof(struct Pixel), 1, file);
    fclose(file);

    return image;
}

// Function to save an image to a PPM file
void saveImage(struct Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Failed to create file\n");
        return;
    }

    fprintf(file, "P6\n%d %d\n%d\n", image->width, image->height, 255);
    fwrite(image->pixels, image->width * image->height * sizeof(struct Pixel), 1, file);
    fclose(file);
}

// Function to apply a Gaussian blur filter to an image
void gaussianBlur(struct Image *image, float sigma) {
    int kSize = (int)(sigma * 3 * 2 + 1) | 1;
    float *kernel = malloc(kSize * sizeof(float));
    float kSum = 0;
    for (int i = 0; i < kSize; i++) {
        float x = i - kSize / 2;
        kernel[i] = expf(-x * x / (2 * sigma * sigma));
        kSum += kernel[i];
    }
    for (int i = 0; i < kSize; i++) {
        kernel[i] /= kSum;
    }

    struct Pixel *tmp = malloc(image->width * image->height * sizeof(struct Pixel));
    memcpy(tmp, image->pixels, image->width * image->height * sizeof(struct Pixel));

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            float r = 0, g = 0, b = 0, kTotal = 0;
            for (int ky = 0; ky < kSize; ky++) {
                for (int kx = 0; kx < kSize; kx++) {
                    int px = x + kx - kSize / 2;
                    int py = y + ky - kSize / 2;
                    if (px < 0 || px >= image->width || py < 0 || py >= image->height) {
                        continue;
                    }
                    struct Pixel p = tmp[py * image->width + px];
                    float k = kernel[ky * kSize + kx];
                    r += p.r * k;
                    g += p.g * k;
                    b += p.b * k;
                    kTotal += k;
                }
            }
            struct Pixel *p = &image->pixels[y * image->width + x];
            p->r = r / kTotal + 0.5f;
            p->g = g / kTotal + 0.5f;
            p->b = b / kTotal + 0.5f;
        }
    }

    free(kernel);
    free(tmp);
}

int main() {
    struct Image *image = loadImage("input.ppm");
    if (!image) {
        return 1;
    }

    gaussianBlur(image, 3);

    saveImage(image, "output.ppm");

    free(image->pixels);
    free(image);

    return 0;
}