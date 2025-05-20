//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

// Function prototype declarations
Image *load_ppm(const char *filename);
void save_ppm(const char *filename, Image *img);
void flip_image(Image *img);
void adjust_brightness(Image *img, int value);
void adjust_contrast(Image *img, float factor);
void free_image(Image *img);

// Main function
int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Usage: %s <input.ppm> <output.ppm> <brightness> <contrast>\n", argv[0]);
        return 1;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];
    int brightness = atoi(argv[3]);
    float contrast = atof(argv[4]);

    Image *img = load_ppm(input_filename);
    if (!img) {
        fprintf(stderr, "Failed to load image: %s\n", input_filename);
        return 1;
    }

    flip_image(img);
    adjust_brightness(img, brightness);
    adjust_contrast(img, contrast);

    save_ppm(output_filename, img);
    free_image(img);

    printf("Image processing complete. Saved to %s\n", output_filename);
    return 0;
}

// Load PPM image
Image *load_ppm(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return NULL;
    }

    char header[3];
    int max_color_value;
    Image *img = malloc(sizeof(Image));

    fscanf(file, "%2s\n%d %d\n%d\n", header, &img->width, &img->height, &max_color_value);
    img->data = malloc(img->width * img->height * sizeof(Pixel));

    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);

    return img;
}

// Save PPM image
void save_ppm(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

// Flip image vertically
void flip_image(Image *img) {
    int row_size = img->width * sizeof(Pixel);
    Pixel *temp_row = malloc(row_size);

    for (int i = 0; i < img->height / 2; i++) {
        // Swap rows
        memcpy(temp_row, &img->data[i * img->width], row_size);
        memcpy(&img->data[i * img->width], &img->data[(img->height - 1 - i) * img->width], row_size);
        memcpy(&img->data[(img->height - 1 - i) * img->width], temp_row, row_size);
    }

    free(temp_row);
}

// Adjust brightness
void adjust_brightness(Image *img, int value) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (img->data[i].r + value > 255) ? 255 : (img->data[i].r + value < 0) ? 0 : img->data[i].r + value;
        img->data[i].g = (img->data[i].g + value > 255) ? 255 : (img->data[i].g + value < 0) ? 0 : img->data[i].g + value;
        img->data[i].b = (img->data[i].b + value > 255) ? 255 : (img->data[i].b + value < 0) ? 0 : img->data[i].b + value;
    }
}

// Adjust contrast
void adjust_contrast(Image *img, float factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (int)((img->data[i].r - 128) * factor + 128);
        img->data[i].g = (int)((img->data[i].g - 128) * factor + 128);
        img->data[i].b = (int)((img->data[i].b - 128) * factor + 128);

        img->data[i].r = (img->data[i].r > 255) ? 255 : (img->data[i].r < 0) ? 0 : img->data[i].r;
        img->data[i].g = (img->data[i].g > 255) ? 255 : (img->data[i].g < 0) ? 0 : img->data[i].g;
        img->data[i].b = (img->data[i].b > 255) ? 255 : (img->data[i].b < 0) ? 0 : img->data[i].b;
    }
}

// Free image memory
void free_image(Image *img) {
    free(img->data);
    free(img);
}