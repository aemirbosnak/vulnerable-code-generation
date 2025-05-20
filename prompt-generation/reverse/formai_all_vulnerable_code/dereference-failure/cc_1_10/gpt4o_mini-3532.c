//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *data;
} Image;

Image* load_image(const char *filename);
void save_image(const char *filename, const Image *image);
void flip_image(Image *image);
void adjust_brightness(Image *image, int brightness);
void adjust_contrast(Image *image, float contrast);
void free_image(Image *image);

int main() {
    const char *input_file = "input.bmp";
    const char *output_flip = "output_flipped.bmp";
    const char *output_brightness = "output_bright.bmp";
    const char *output_contrast = "output_contrast.bmp";

    // Load the image
    Image *image = load_image(input_file);
    if (!image) {
        fprintf(stderr, "Error loading image.\n");
        return 1;
    }

    // Flip the image
    flip_image(image);
    save_image(output_flip, image);
    printf("Flipped image saved as %s\n", output_flip);

    // Adjust brightness
    adjust_brightness(image, 50);
    save_image(output_brightness, image);
    printf("Brightness adjusted image saved as %s\n", output_brightness);

    // Adjust contrast
    adjust_contrast(image, 1.5);
    save_image(output_contrast, image);
    printf("Contrast adjusted image saved as %s\n", output_contrast);

    // Free the image memory
    free_image(image);

    return 0;
}

Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        return NULL;
    }

    // Read BMP header
    fseek(file, 18, SEEK_SET);
    int width, height;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);

    // Allocate memory for the image
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * sizeof(Pixel));

    // Read pixel data
    fseek(file, 54, SEEK_SET); // BMP file header is 54 bytes
    fread(image->data, sizeof(Pixel), width * height, file);
    fclose(file);

    return image;
}

void save_image(const char *filename, const Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Could not open file for writing");
        return;
    }

    // Write BMP header (simplified)
    fwrite("BM", 1, 2, file);
    int file_size = 54 + image->width * image->height * sizeof(Pixel);
    fwrite(&file_size, sizeof(int), 1, file);
    int reserved = 0;
    fwrite(&reserved, sizeof(int), 1, file);
    int offset = 54;
    fwrite(&offset, sizeof(int), 1, file);
    
    // Write DIB header
    int dib_header_size = 40;
    fwrite(&dib_header_size, sizeof(int), 1, file);
    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);
    
    short planes = 1;
    fwrite(&planes, sizeof(short), 1, file);
    short bpp = 24; // bits per pixel
    fwrite(&bpp, sizeof(short), 1, file);
    int compression = 0;
    fwrite(&compression, sizeof(int), 1, file);
    int image_size = image->width * image->height * sizeof(Pixel);
    fwrite(&image_size, sizeof(int), 1, file);
    int ppm = 2835;
    fwrite(&ppm, sizeof(int), 1, file);
    fwrite(&ppm, sizeof(int), 1, file);
    int important_colors = 0;
    fwrite(&important_colors, sizeof(int), 1, file);

    // Write pixel data
    fwrite(image->data, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
}

void flip_image(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            int opposite_x = image->width - 1 - x;
            Pixel temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[y * image->width + opposite_x];
            image->data[y * image->width + opposite_x] = temp;
        }
    }
}

void adjust_brightness(Image *image, int brightness) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i].r = (uint8_t) fmin(fmax(image->data[i].r + brightness, 0), 255);
        image->data[i].g = (uint8_t) fmin(fmax(image->data[i].g + brightness, 0), 255);
        image->data[i].b = (uint8_t) fmin(fmax(image->data[i].b + brightness, 0), 255);
    }
}

void adjust_contrast(Image *image, float contrast) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i].r = (uint8_t) fmin(fmax((image->data[i].r - 128) * contrast + 128, 0), 255);
        image->data[i].g = (uint8_t) fmin(fmax((image->data[i].g - 128) * contrast + 128, 0), 255);
        image->data[i].b = (uint8_t) fmin(fmax((image->data[i].b - 128) * contrast + 128, 0), 255);
    }
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}