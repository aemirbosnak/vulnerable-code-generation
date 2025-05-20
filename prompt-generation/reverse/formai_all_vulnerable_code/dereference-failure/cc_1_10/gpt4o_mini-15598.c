//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

Image* load_image(const char *filename);
void save_image(const char *filename, Image *img);
Image* flip_image(Image *img);
void adjust_brightness(Image *img, int brightness);
void adjust_contrast(Image *img, float contrast);
void free_image(Image *img);
void print_usage(const char *program_name);

int main(int argc, char *argv[]) {
    if (argc != 5) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    int brightness = atoi(argv[3]);
    float contrast = atof(argv[4]);

    Image *img = load_image(input_file);
    if (!img) {
        fprintf(stderr, "Error loading image: %s\n", input_file);
        return EXIT_FAILURE;
    }

    printf("Loaded image: %s, width: %d, height: %d\n", input_file, img->width, img->height);
    
    img = flip_image(img);
    printf("Image flipped vertically!\n");

    adjust_brightness(img, brightness);
    printf("Adjusted brightness by %d!\n", brightness);

    adjust_contrast(img, contrast);
    printf("Adjusted contrast by factor %f!\n", contrast);

    save_image(output_file, img);
    free_image(img);

    printf("Processed image saved as: %s\n", output_file);
    return EXIT_SUCCESS;
}

Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) return NULL;

    char header[3];
    fscanf(file, "%2s", header);
    if (strcmp(header, "P6") != 0) {
        fclose(file);
        fprintf(stderr, "Unsupported file format: %s\n", header);
        return NULL;
    }

    Image *img = (Image *)malloc(sizeof(Image));
    fscanf(file, "%d %d", &img->width, &img->height);
    int max_color_value;
    fscanf(file, "%d", &max_color_value);
    fgetc(file); // Skip the newline

    img->data = (Pixel *)malloc(sizeof(Pixel) * img->width * img->height);
    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    return img;
}

void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) return;

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

Image* flip_image(Image *img) {
    Image *flipped = (Image *)malloc(sizeof(Image));
    flipped->width = img->width;
    flipped->height = img->height;
    flipped->data = (Pixel *)malloc(sizeof(Pixel) * img->width * img->height);

    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            flipped->data[(img->height - 1 - y) * img->width + x] = img->data[y * img->width + x];
        }
    }
    free_image(img);
    return flipped;
}

void adjust_brightness(Image *img, int brightness) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (unsigned char) fmin(fmax(img->data[i].r + brightness, 0), 255);
        img->data[i].g = (unsigned char) fmin(fmax(img->data[i].g + brightness, 0), 255);
        img->data[i].b = (unsigned char) fmin(fmax(img->data[i].b + brightness, 0), 255);
    }
}

void adjust_contrast(Image *img, float contrast) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (unsigned char) fmin(fmax((img->data[i].r - 128) * contrast + 128, 0), 255);
        img->data[i].g = (unsigned char) fmin(fmax((img->data[i].g - 128) * contrast + 128, 0), 255);
        img->data[i].b = (unsigned char) fmin(fmax((img->data[i].b - 128) * contrast + 128, 0), 255);
    }
}

void free_image(Image *img) {
    free(img->data);
    free(img);
}

void print_usage(const char *program_name) {
    fprintf(stderr, "Usage: %s <input_file.ppm> <output_file.ppm> <brightness> <contrast>\n", program_name);
}