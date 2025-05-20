//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *data;
} Image;

// Function to read PPM image
Image* read_ppm(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        return NULL;
    }
    char header[20];
    int max_color;
    
    fgets(header, sizeof(header), file); // Read PPM header
    if (header[1] != '6') {
        fprintf(stderr, "Unsupported PPM format. Use P6 format.\n");
        fclose(file);
        return NULL;
    }

    Image *img = (Image *)malloc(sizeof(Image));
    fscanf(file, "%d %d %d", &img->width, &img->height, &max_color);
    fgetc(file); // Consumes the whitespace after max_color

    img->data = (Pixel *)malloc(sizeof(Pixel) * img->width * img->height);
    fread(img->data, sizeof(Pixel), img->width * img->height, file); // Read pixel data

    fclose(file);
    return img;
}

// Function to write PPM image
void write_ppm(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        return;
    }
    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

// Function to flip an image vertically
void flip_image(Image *img) {
    for (int y = 0; y < img->height / 2; y++) {
        for (int x = 0; x < img->width; x++) {
            Pixel temp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[(img->height - y - 1) * img->width + x];
            img->data[(img->height - y - 1) * img->width + x] = temp;
        }
    }
}

// Function to adjust brightness
void adjust_brightness(Image *img, int adjustment) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (uint8_t)fmin(255, fmax(0, img->data[i].r + adjustment));
        img->data[i].g = (uint8_t)fmin(255, fmax(0, img->data[i].g + adjustment));
        img->data[i].b = (uint8_t)fmin(255, fmax(0, img->data[i].b + adjustment));
    }
}

// Function to adjust contrast
void adjust_contrast(Image *img, float factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (uint8_t)fmin(255, fmax(0, img->data[i].r * factor));
        img->data[i].g = (uint8_t)fmin(255, fmax(0, img->data[i].g * factor));
        img->data[i].b = (uint8_t)fmin(255, fmax(0, img->data[i].b * factor));
    }
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm> <brightness_change> <contrast_factor>\n", argv[0]);
        return 1;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];
    int brightness_change = atoi(argv[3]);
    float contrast_factor = atof(argv[4]);

    Image *img = read_ppm(input_filename);
    if (!img) {
        return 1;
    }

    printf("Image read successfully: %d x %d\n", img->width, img->height);

    flip_image(img);
    printf("Image flipped vertically\n");

    adjust_brightness(img, brightness_change);
    printf("Brightness adjusted by %d\n", brightness_change);

    adjust_contrast(img, contrast_factor);
    printf("Contrast adjusted by factor %.2f\n", contrast_factor);

    write_ppm(output_filename, img);
    printf("Image written to %s\n", output_filename);

    free(img->data);
    free(img);
    return 0;
}